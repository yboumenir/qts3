#include <QtCore>

#include <qts3.h>

#ifdef USE_QPM_NS
using namespace com::github::msorvig::s3;
#endif

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QByteArray accessKeyId, secretAccessKey, bucketName, objectName;

    if(argc > 4){
        accessKeyId = QByteArray(argv[1]);
        secretAccessKey = QByteArray(argv[2]);
        bucketName = QByteArray(argv[3]);
        objectName = QByteArray(argv[4]);
    }
    else{
        qDebug() << "usage: <S3_KEY> <S3_SECRET> <S3_BUCKET> <FILE>";
        exit(0);
    }

    qDebug() << "[accessKeyId] " << accessKeyId;
    qDebug() << "[secretAccessKey] " << secretAccessKey;
    qDebug() << "[bucketName] " << bucketName;
    qDebug() << "[objectName] " << objectName;

    
    QtS3 s3(accessKeyId, secretAccessKey);

    QFile f(objectName);
    f.open(QIODevice::ReadOnly);
    QByteArray contents = f.readAll();
    
    qDebug() << "Uploading file bucket" << bucketName;
    QtS3Reply<void> putReply = s3.put(bucketName, objectName, contents);
    if (!putReply.isSuccess())
        qDebug() << "S3 put error" << putReply.anyErrorString();
        
    qDebug() << "Checking object size";
    QtS3Reply<int> sizeReply = s3.size(bucketName, objectName);
    if (!sizeReply.isSuccess()){
        qDebug() << "S3 size error:" << sizeReply.anyErrorString();
    }
    else{
        qDebug() << "Done! Object size is:" << sizeReply.value();
        exit(0);
    }

    return app.exec();
}

    

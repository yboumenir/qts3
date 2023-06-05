project(example)
message("-- building example")

add_executable(example example.cpp)
target_link_libraries(example PUBLIC Qt::Core Qt::Network qts3)

cmake_minimum_required(VERSION 3.16)

project(qts3 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_BUILD_TYPE Debug)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(HEADERS
	${CMAKE_CURRENT_SOURCE_DIR}/include/qts3.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/qts3qnam_p.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/qts3_p.h
)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/qts3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/qts3qnam.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/qts3_p.cpp
)

add_library(qts3 ${HEADERS} ${SOURCES})
target_link_libraries(qts3 PUBLIC Qt::Core Qt::Network)

add_subdirectory(example)

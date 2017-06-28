# bootstrap build system
cmake_minimum_required(VERSION 2.8.9)
project(gdal-drivers)
include(buildsys/cmake/buildsys.cmake)

enable_hidden_visibility()

find_package(Boost 1.46 REQUIRED
  COMPONENTS thread program_options filesystem system date_time
             serialization regex chrono iostreams)
link_directories(${Boost_LIBRARY_DIRS})
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

find_package(OpenCV 2.4 REQUIRED)

find_package(Proj REQUIRED)
include_directories(${PROJ_INCLUDE_DIR})
find_package(GeographicLib REQUIRED)
include_directories(${GEOGRAPHICLIB_INCLUDE_DIR})

find_package(GDAL REQUIRED)
include_directories(${GDAL_INCLUDE_DIR})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

find_package(GIF REQUIRED)
include_directories(${GIF_INCLUDE_DIR})

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

find_package(Sqlite3 REQUIRED)
link_directories(${Sqlite3_LIBRARY_DIRS})
include_directories(${Sqlite3_INCLUDE_DIRS})

find_package(JsonCPP REQUIRED)
include_directories(${JSONCPP_INCLUDE_DIRS})

# dependencies
add_subdirectory(src/dbglog EXCLUDE_FROM_ALL)
add_subdirectory(src/utility EXCLUDE_FROM_ALL)
add_subdirectory(src/math EXCLUDE_FROM_ALL)
add_subdirectory(src/imgproc EXCLUDE_FROM_ALL)
add_subdirectory(src/geometry EXCLUDE_FROM_ALL)
add_subdirectory(src/jsoncpp EXCLUDE_FROM_ALL)
add_subdirectory(src/geo EXCLUDE_FROM_ALL)

# gdal drivers
add_subdirectory(src/gdal-drivers EXCLUDE_FROM_ALL)
add_subdirectory(src/standalone-gdal-drivers)

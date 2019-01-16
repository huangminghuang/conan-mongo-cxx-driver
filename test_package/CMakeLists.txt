cmake_minimum_required(VERSION 2.8.12)
project(PackageTest CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 11)
endif()

list (FIND CONAN_DEFINES_MONGO-CXX-DRIVER "-DBSONCXX_STATIC" _index)
if (${_index} GREATER -1)
  set(LIB_SUFFIX _STATIC)
  find_package(libmongocxx-static REQUIRED)
else()
  find_package(libmongocxx REQUIRED)
endif()

message ("--   mongocxx found version \"${LIBMONGOCXX${LIB_SUFFIX}_VERSION}\"")
message ("--   mongocxx include path \"${LIBMONGOCXX${LIB_SUFFIX}_INCLUDE_DIRS}\"")
message ("--   mongocxx libraries \"${LIBMONGOCXX${LIB_SUFFIX}_LIBRARIES}\"")

add_executable(example example.cpp)
target_include_directories(example PRIVATE ${LIBMONGOCXX${LIB_SUFFIX}_INCLUDE_DIRS})
target_link_libraries(example ${LIBMONGOCXX${LIB_SUFFIX}_LIBRARIES})
target_compile_definitions(example PRIVATE ${LIBMONGOCXX${LIB_SUFFIX}_DEFINITIONS})


## Package Status

| Bintray | Windows | Linux & macOS |
|:--------:|:---------:|:-----------------:|
|[![Download](https://api.bintray.com/packages/huangminghuang/conan/mongo-cxx-driver%3Ahuangminghuang/images/download.svg) ](https://bintray.com/huangminghuang/conan/mongo-cxx-driver%3Ahuangminghuang/_latestVersion)|[![Build status](https://ci.appveyor.com/api/projects/status/github/huangminghuang/conan-mongo-cxx-driver?svg=true)](https://ci.appveyor.com/project/huangminghuang/conan-mongo-cxx-driver)|[![Build Status](https://travis-ci.com/huangminghuang/conan-mongo-cxx-driver.svg?branch=master)](https://travis-ci.com/huangminghuang/conan-mongo-cxx-driver)|


## Basic setup

    $ conan remote add huang https://api.bintray.com/conan/huangminghuang/conan 
    $ conan install mongo-cxx-driver/3.4.0@huangminghuang/stable
    
## Project setup

If you handle multiple dependencies in your project is better to add a *conanfile.txt*
    
    [requires]
    mongo-cxx-driver/3.4.0@huangminghuang/stable

    [options]
    mongo-cxx-driver:shared=False
    
    [generators]
    cmake
    cmake_paths

Complete the installation of requirements for your project running:

    conan install . 

Project setup installs the library (and all his dependencies) and generates the files *conanbuildinfo.cmake* with all the 
paths and variables that you need to link with your dependencies.

## CMake setup

### using cmake_paths generator
This recipe exports the original libmonogocxx-static-config.cmake/libbsoncxx-static-config.cmake installed by mongo-cxx-driver so you can use the *cmake_paths* generator without modifying your existing *CMakefiles.txt*.

*CMakeLists.txt*

    set (CMAKE_CXX_STANDARD 11)
    find_package(libmongocxx-static REQUIRED)
    add_executable(example example.cpp)
    target_include_directories(example PRIVATE ${LIBMONGOCXX_STATIC_INCLUDE_DIRS})
    target_link_libraries(example ${LIBMONGOCXX_STATIC_LIBRARIES})
    target_compile_definitions(example PRIVATE ${LIBMONGOCXX_STATIC_DEFINITIONS})
 

The *conan_paths.cmake* can be specified as a toolchain file when invoking cmake:

```bash
$ mkdir build && cd build
$ conan install ..
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_paths.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

### using cmake generator

*CMakeLists.txt*

    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(TARGETS)
    set (CMAKE_CXX_STANDARD 11)
    add_executable(example example.cpp)
    target_link_libraries(example CONAN_PKG::mongo-cxx-driver)
 
  
```bash
$ mkdir build && cd build
$ conan install ..
$ cmake .. -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```



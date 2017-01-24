#include <iostream>

using namespace std;

int main(){

    cout << "hello world" << endl;

}


/**
 *   CMakeLists.txt 예제
 *   * CMakeLists.txt 파일은 절대로 GIT에 포함시키지 마세요

cmake_minimum_required(VERSION 3.6)
project(Algorithm-Study)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(BUILD main)
set(SOURCE_FILES test/test.cpp)
add_executable(${BUILD} ${SOURCE_FILES})

**/
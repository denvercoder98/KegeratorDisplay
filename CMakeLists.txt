cmake_minimum_required(VERSION 2.8.9)
project(KegeratorDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -ggdb -O0 -g --coverage")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB TARGET_SOURCES "src/main/monitor/*.cpp" "src/main/presenter/*.cpp" "src/main/view/*.cpp" "src/main/storage/*.cpp" "src/main/controller/*.cpp" "src/main/shared/*.cpp")
file(GLOB UNITTEST_SOURCES "src/test/UnitTest.cpp" "src/test/monitor/*.cpp" "src/test/presenter/*.cpp" "src/test/controller/*.cpp")
file(GLOB ACCEPTANCETEST_SOURCES "src/test/AcceptanceTest.cpp")

link_directories("lib/googletest-release-1.8.1/build/googlemock/gtest/")
link_directories("lib/googletest-release-1.8.1/build/googlemock/")
include_directories("lib/googletest-release-1.8.1/googletest/include/")
include_directories("lib/googletest-release-1.8.1/googlemock/include/")
include_directories("src/main/")
include_directories("src/test/")

find_package(Boost 1.58 COMPONENTS date_time thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_library(KegeratorDisplayImplementation STATIC ${TARGET_SOURCES} )

add_executable(kegeratorDisplay "src/main/Main.cpp")
add_executable(kegeratorDisplayUnitTest ${UNITTEST_SOURCES})
add_executable(kegeratorDisplayAcceptanceTest ${ACCEPTANCETEST_SOURCES})

target_link_libraries(kegeratorDisplay KegeratorDisplayImplementation ${Boost_LIBRARIES})
target_link_libraries(kegeratorDisplayUnitTest KegeratorDisplayImplementation ${Boost_LIBRARIES} gtest gmock pthread)
target_link_libraries(kegeratorDisplayAcceptanceTest KegeratorDisplayImplementation ${Boost_LIBRARIES} gtest gmock pthread)

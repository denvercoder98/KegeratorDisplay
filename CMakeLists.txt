cmake_minimum_required(VERSION 2.8.9)
project(KegeratorDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ggdb")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB TARGET_SOURCES "src/main/monitor/*.cpp" "src/main/presenter/*.cpp" "src/main/cliview/*.cpp" "src/main/storage/*.cpp")
file(GLOB UNITTEST_SOURCES "src/test/UnitTest.cpp" "src/test/monitor/*.cpp" "src/test/presenter/*.cpp")
file(GLOB ACCEPTANCETEST_SOURCES "src/test/AcceptanceTest.cpp")

link_directories("lib/googletest-release-1.8.1/build/googlemock/gtest/")
link_directories("lib/googletest-release-1.8.1/build/googlemock/")
include_directories("lib/googletest-release-1.8.1/googletest/include/")
include_directories("lib/googletest-release-1.8.1/googlemock/include/")
include_directories(".")

add_executable(kegeratorDisplay "src/main/Main.cpp" ${TARGET_SOURCES})
add_executable(kegeratorDisplayUnitTest ${UNITTEST_SOURCES} ${TARGET_SOURCES})
add_executable(kegeratorDisplayAcceptanceTest ${ACCEPTANCETEST_SOURCES} ${TARGET_SOURCES})

target_link_libraries(kegeratorDisplayUnitTest gtest)
target_link_libraries(kegeratorDisplayUnitTest gmock)
target_link_libraries(kegeratorDisplayUnitTest pthread)

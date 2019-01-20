cmake_minimum_required(VERSION 2.8.9)
project(KegeratorDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -ggdb -O0 -g --coverage -fPIC -fprofile-arcs -ftest-coverage")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB TARGET_SOURCES
	"src/main/Kegerator.cpp"
	"src/main/entities/*.cpp"
	"src/main/interactors/*.cpp"
	"src/main/presenter/*.cpp"
	"src/main/view/qobjects/*.h"
	"src/main/view/qobjects/*.cpp"
	"src/main/view/*.cpp"
	"src/main/storage/*.cpp"
	"src/main/controllers/*.cpp"
	"src/main/devices/*.cpp"
	"src/main/devices/Qml*.h"
	"src/main/thread/*.cpp")
file(GLOB UNITTEST_SOURCES
	"src/test/unit/TestRunner.cpp"
	"src/test/unit/devices/*.cpp"
	"src/test/unit/entities/*.cpp"
	"src/test/unit/interactors/*.cpp"
	"src/test/unit/presenter/*.cpp"
	"src/test/unit/controllers/*.cpp"
	"src/test/unit/thread/*.cpp"
	"src/test/unit/view/*.cpp"
	"src/test/unit/view/qobjects/*.cpp"
	"src/test/unit/storage/*.cpp")
file(GLOB ACCEPTANCETEST_SOURCES
	"src/test/acceptance/features/step_definitions/*.cpp")

link_directories("lib/googletest-release-1.8.1/install/lib/")
include_directories("lib/googletest-release-1.8.1/install/include/")

link_directories("lib/cucumber-cpp-0.5/install/lib")
include_directories("lib/cucumber-cpp-0.5/install/include")

include_directories("src/main/")
include_directories("src/test/")

find_package(Qt5 5.7 COMPONENTS Widgets Qml Quick QuickControls2 REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES src/main/view/qml/qml.qrc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Boost 1.54 COMPONENTS
    system
	date_time
	thread
	serialization
	regex
	program_options
	filesystem
	REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_library(KegeratorDisplayImplementation STATIC ${TARGET_SOURCES} )

add_executable(kegeratorDisplay
    src/main/Main.cpp
    src/main/GuiKegerator.cpp
    ${QT_RESOURCES}
)
add_executable(kegeratorDisplayUnitTest
    ${UNITTEST_SOURCES}
)
#add_executable(kegeratorDisplayAcceptanceTest
#    ${ACCEPTANCETEST_SOURCES}
#)

target_link_libraries(kegeratorDisplay KegeratorDisplayImplementation ${Boost_LIBRARIES} Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::QuickControls2)
target_link_libraries(kegeratorDisplayUnitTest KegeratorDisplayImplementation ${Boost_LIBRARIES} Qt5::Quick gtest gmock pthread)
#target_link_libraries(kegeratorDisplayAcceptanceTest cucumber-cpp KegeratorDisplayImplementation gtest gmock ${Boost_LIBRARIES} pthread)

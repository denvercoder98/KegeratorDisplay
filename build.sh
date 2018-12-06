#!/bin/bash

CUCUMBER_DIR=lib/cucumber-cpp-0.5
if [ ! -d "$CUCUMBER_DIR/build" ]; then
	echo "Building cucumber-cpp"
#	pushd . > /dev/null
#	cd $CUCUMBER_DIR
#	CUCUMBER_DIR_ABSOLUTE="$(pwd)/build"
#	cmake -E make_directory build
#	cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=$CUCUMBER_DIR_ABSOLUTE ..
#	cmake --build build
#	cmake --build build --target install
#	popd > /dev/null
else
	echo "cucumber-cpp already built"
fi

GOOGLETEST_DIR=lib/googletest-release-1.8.1
if [ ! -d "$GOOGLETEST_DIR/build" ]; then
	echo "Building googletest"
#	pushd . > /dev/null
#	cd $GOOGLETEST_DIR
#	GOOGLETEST_DIR_ABSOLUTE="$(pwd)/build"
#	cmake -E make_directory build
#	cmake -E chdir build cmake ..
#	cmake --build build
#	popd > /dev/null
else
	echo "googletest already built"
fi

cmake -E make_directory build
cmake -E chdir build cmake -DQt5_DIR:PATH=/opt/Qt5.10.0/5.10.0/gcc_64/lib/cmake/Qt5 ..
cmake --build build -- "$@"

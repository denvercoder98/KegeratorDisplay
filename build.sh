#!/bin/bash

#CUCUMBER_DIR=lib/cucumber-cpp-0.5
#if [ ! -d "$CUCUMBER_DIR/install" ]; then
#	echo "Building cucumber-cpp"
#	pushd . > /dev/null
#	cd $CUCUMBER_DIR
#	CUCUMBER_INSTALL_DIR="$(pwd)/install"
#	cmake -E make_directory build
#	cmake -E chdir build cmake -DCUKE_ENABLE_EXAMPLES=on -DCMAKE_INSTALL_PREFIX=$CUCUMBER_INSTALL_DIR ..
#	cmake --build build
#	cmake --build build --target install
#	popd > /dev/null
#else
#	echo "cucumber-cpp already built"
#fi

GOOGLETEST_DIR=lib/googletest-release-1.8.1
if [ ! -d "$GOOGLETEST_DIR/install" ]; then
	echo "Building googletest"
	pushd . > /dev/null
	cd $GOOGLETEST_DIR
	GOOGLETEST_INSTALL_DIR="$(pwd)/install"
	cmake -E make_directory build
	cmake -E chdir build cmake -DCMAKE_INSTALL_PREFIX=$GOOGLETEST_INSTALL_DIR ..
	cmake --build build
	cmake --build build --target install
	popd > /dev/null
else
	echo "googletest already built"
fi

cmake -E make_directory build
QT5_DIR_DEFINE=""
if [ ! -z "$QT5_DIR" ]; then
	QT5_DIR_DEFINE="-DQt5_DIR:PATH=/opt/Qt5.10.0/5.10.0/gcc_64/lib/cmake/Qt5"
fi
cmake -E chdir build cmake $QT5_DIR_DEFINE ..
cmake --build build -- "$@"

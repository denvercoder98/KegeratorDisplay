#!/bin/bash

BUILD_DIR=$1
COVERAGE_DIR="test_coverage"

pushd .
cd $BUILD_DIR
mkdir -p $COVERAGE_DIR
lcov -c -i -d CMakeFiles -o $COVERAGE_DIR/app_base.info
bin/kegeratorDisplayUnitTest
lcov -c -d CMakeFiles -o $COVERAGE_DIR/app_cov.info
lcov -a $COVERAGE_DIR/app_base.info -a $COVERAGE_DIR/app_cov.info -o $COVERAGE_DIR/app_total.info
lcov -e $COVERAGE_DIR/app_total.info *main* -o $COVERAGE_DIR/app_main_only.info
#lcov --remove cov2.info Main.cpp -o cov3.info
genhtml $COVERAGE_DIR/app_main_only.info -o $COVERAGE_DIR/out

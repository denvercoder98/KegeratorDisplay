#!/bin/bash

COVERAGE_DIR="test_coverage"

cd build
mkdir -p $COVERAGE_DIR
lcov -c -i -d CMakeFiles -o $COVERAGE_DIR/app_base.info
bin/kegeratorDisplayUnitTest
lcov -c -d CMakeFiles -o $COVERAGE_DIR/app_cov.info
lcov -a $COVERAGE_DIR/app_base.info -a $COVERAGE_DIR/app_cov.info -o $COVERAGE_DIR/app_total.info
lcov -e $COVERAGE_DIR/app_total.info *main* -o $COVERAGE_DIR/app_main_src_only.info
lcov --remove $COVERAGE_DIR/app_main_src_only.info Main.cpp -o $COVERAGE_DIR/app_src_only.info
lcov --remove $COVERAGE_DIR/app_src_only.info view/* -o $COVERAGE_DIR/app_src_only_no_view.info
genhtml $COVERAGE_DIR/app_src_only_no_view.info -o $COVERAGE_DIR/out

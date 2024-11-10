#!/bin/bash

BUILD_TYPE=Release

cmake -B build -DCMAKE_BUILD_TYPE=$BUILD_TYPE
cmake --build build --config $BUILD_TYPE

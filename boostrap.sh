#!/bin/bash

rm -rf build 
mkdir build && cd $_

cmake .. && make && make test 
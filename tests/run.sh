#!/bin/bash

g++ main.cpp ../lib/shape/shape.cpp ../lib/line/line.cpp \
 	../lib/rectangle/rectangle.cpp -o test -lgtest -pthread && ./test

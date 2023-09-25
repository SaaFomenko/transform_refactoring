#!/bin/bash

g++ main.cpp ../lib/point/point.cpp ../lib/line/line.cpp -o test -lgtest -pthread && ./test

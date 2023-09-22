#!/bin/bash

g++ main.cpp ../lib/point/point.cpp -o test -lgtest -pthread && ./test

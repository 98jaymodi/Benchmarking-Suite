#!/bin/bash
export DISPLAY=:0.0
export NO_AT_BRIDGE=1

./vehicle cars.xml dataset/video2/video2.avi  dataset/video2/data2.txt dataset/video2/co2.txt 1.5 1 0 0

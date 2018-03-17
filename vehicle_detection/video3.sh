#!/bin/bash
export DISPLAY=:0.0
export NO_AT_BRIDGE=1

./vehicle cars.xml dataset/video3/video3.avi  dataset/video3/data3.txt dataset/video3/co3.txt 1.5 1 0 0

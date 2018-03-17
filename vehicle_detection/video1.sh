
#!/bin/bash
#order - scale factor(1.1, 1.5), min_neighbours(1, 2), pfactor(0,20,30), min_size(0,20,30)
export DISPLAY=:0.0
export NO_AT_BRIDGE=1

./vehicle cars.xml dataset/video1/video1.avi  dataset/video1/data1.txt dataset/video1/co1.txt 1.5 1 0 0

# Vehicle Detection Algorithm
Implementation in C++ of vehicle detection algorithm using OpenCV.

Examples of datasets are in "dataset" folder

Refrence from -https://github.com/andrewssobral/vehicle_detection_haarcascades

The implementation is in vehicle.cpp.

Each dataset contains three files:- 
1- A video in .avi format in which vehicles are detected.
2- A data file in .txt format (eg. data1.txt) which contains the number of cars in the video in each frame.
3- A coordinates file in .txt format(eg. co1.txt) which contains the coordinates of the cars in each frame.


To run the code you have to install latest version of OpenCV Library on your machine. This program has been checked for OpenCV version 3.3.1 and 3.3.0.


To run the code:-

1-  For RaspberryPi a Makefile is provided to compile the source code.
	
	Run the following commands to compile the source code:-
	~/cd vehicle
	~/make

	To run the demos, scrpit files have been provided:-
	To run the program for video1:-
	~/  ./video1.sh
	and similar command for video2 and video3.


2- For Ubuntu
	
	Run the following command to compile the source code:-
	~/g++ vehicle_detection.cpp -o program $(pkg-config --cflags --libs opencv)
	Now to run the demos run the scrpit files.
	~/ ./video1.sh
	and similar command for video2 and video3.

Parameters:- There are 4 parameters which could change the accuracy and runtime of program.
1-Scale Factor
2-Min_neighbours
3-Min_size
4-CV_size

which when varied results in variation in accuracy and runtime. These parameters could be easily changed by editing the script files (.sh files). The details of these parameters in given is script files.  



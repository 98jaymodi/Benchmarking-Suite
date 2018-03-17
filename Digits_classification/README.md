# Digit-classification algorithm
Implementation in C++ of Digit-classification algorithm

Refrence from : https://www.learnopencv.com/handwritten-digits-classification-an-opencv-c-python-tutorial/

The implementation is in the file train_digit3.cpp.
Original code is in train_digit.cpp.
The code is implemented using OPENCV Library.

Dataset for training and testing is present in the image digit.png in the same folder. It contains 5000 images in all — 500 images of each digit. Each image is 20×20 grayscale with a black background. 4500 of these digits will be used for training and the remaining 500 will be used for testing the performance of the algorithm.

For running the code, run the following command(keep the dataset in the same folder digits.png):
g++ -std=c++11 train_digits3.cpp `pkg-config --libs --cflags opencv` -o ol
./ol

The first command create an output "ol". then second command creates another file name "model4.yml" which are already present in the folder.

Also, we can set kernel type and value of gamma for different accuracy and time (example: kernel type(RBF or Linear) = 1 & gamma =0.50625).


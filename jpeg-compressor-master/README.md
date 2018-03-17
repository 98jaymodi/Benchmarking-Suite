# JPEG Compressor
Implementation in C++ of JPEG image compressor.

Dataset can be any image in .JPEG, .PNG, .BMP format.
Dataset is present in a folder namely "examples"

The output is a .JPEG image of less size depending on the quality factor.


Refrence from- https://github.com/kornelski/jpeg-compressor

The implementation is in encoder.cpp.

Makefile is provided to compile the source code.

Run the following commands to compile the source code:-

~/   cd jpeg-compressor-master
~/   make

~/   ./encoder.cpp examples/filename.jpg output.jpg 50 



Parameter:- Here 50 is quality factor which when varied results in variation in accuracy and runtime. This parameters could be easily changed at runtime. The value may range from 1-100 and more the quality factor, more is the quality of compressed image and hence more is the size and the time taken for compressing will be more.  



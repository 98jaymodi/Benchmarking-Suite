CC = g++
#CXXFLAGS = -g -Wall `pkg-config --cflags opencv`
#CFLAGS = -g -Wall
SRCS = vehicle_detection.cpp
#LDFLAGS = -L/usr/local/opencv-2.4.5/lib -lopencv_world -lboost_filesystem -lboost_filesystem-mt
#LDFLAGS = -L/usr/local/opencv-2.4.5/lib -lopencv_world -lboost_filesystem
PROG = vehicle
OPENCV = `pkg-config --cflags --libs opencv`
LIBS = $(OPENCV)
#SOURCE = $(TARGET).cpp feature.cpp recognizer.cpp

$(PROG):$(SRCS)
	$(CC) $(LIBS) $(SRCS) -o $(PROG)

.PHONY: clean
clean:
	rm -f *.o *~ $(PROG)

#include <opencv2/opencv.hpp>
#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <opencv2/core/types_c.h>
#include <opencv2/core/types.hpp>
const int KEY_SPACE = 32;
const int KEY_ESC = 27;

CvHaarClassifierCascade *cascade;
CvMemStorage            *storage;

std::vector<int> detect(IplImage *img, float scalefactor, float min_neighbours, float pfactor, float min_size);

int main(int argc, char** argv)
{
  float scalefactor;
  float min_neighbours;
  float pfactor;
  float min_size;
  float e=0;
  time_t time_start = time(0);
  scalefactor = atof(argv[5]);
  min_neighbours = atof(argv[6]);
  pfactor = atof(argv[7]);
  min_size = atof(argv[8]);

  std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << "\n";
    
  CvCapture *capture;
  IplImage  *frame;
  int input_resize_percent = 100;
  
  if(argc < 9)
  {
    std::cout << "Usage " << argv[0] << " cascade.xml video.avi data.txt coordinate_data.txt scale_factor min_neighbours p_factor min_size" << std::endl;
    return 0;
  }


  cascade = (CvHaarClassifierCascade*) cvLoad(argv[1], 0, 0, 0);
  storage = cvCreateMemStorage(0);
  capture = cvCaptureFromAVI(argv[2]);

  assert(cascade && storage && capture);

  cvNamedWindow("video", 1);
  
  IplImage* frame1 = cvQueryFrame(capture);
  frame = cvCreateImage(cvSize((int)((frame1->width*input_resize_percent)/100) , (int)((frame1->height*input_resize_percent)/100)), frame1->depth, frame1->nChannels);
  int key = 0;
  int index = 0;
  std::vector<int> data;
 ////////////////////////////////////////////////////////////////////////////////
  //reading no. of cars
  std::ifstream in1(argv[3]);
  int numbera;  //Variable to hold each number as it is read
  //Read number using the extraction (>>) operator
  while (in1 >> numbera) {
    //Add the number to the end of the array
    data.push_back(numbera);
  }
  in1.close();
  //---------------------------------------------------------------------------------------------------
  std::vector<cv::Rect2d> cars[data.size()];
  std::ifstream in2(argv[4]);
  int temp;
  for(int i=0;i<data.size();i++){
	int totalcars=data[i];
	int r=0;
	 for(int t=0;t<totalcars;t++){
	   	int c1,c2,c3,c4;
		  in2 >> c1;
		  in2 >> c2;
		  in2 >> c3;
		  in2 >> c4;
		  cars[i].push_back(cv::Rect2d(c1, c2, c3, c4));	
	 }

  }
  in2.close();
  // // ---------------------------------------------------------------------------------------------------------
  std::vector<int> result;
  std::vector<int> coordinates[data.size()];
  std::vector<cv::Rect2d> rectagles[data.size()];
  int tp[data.size()];
  int fp[data.size()];
  int fn[data.size()];
  int precision[data.size()];
  int recall[data.size()];
  for(int i=0;i<data.size();i++){
  	tp[i]=0;
  	fp[i]=0;
  	fn[i]=0;
  }
  
  do
  {
    frame1 = cvQueryFrame(capture);

    if(!frame1)
      break;

  	std::vector<int> framedata;
    cvResize(frame1, frame);
    framedata = detect(frame, scalefactor, min_neighbours, pfactor, min_size);
    result.push_back(framedata[0]);
    int carcount=framedata[0];
    int i=1;
    for(int t=1;t<=carcount;t++){
    	rectagles[index].push_back(cv::Rect2d(framedata[i],framedata[i+1],framedata[i+2],framedata[i+3]));	
    	i=i+4;
    }
   	
   	index++;
   
    key = cvWaitKey(33);

    if(key == KEY_SPACE)
      key = cvWaitKey(0);

    if(key == KEY_ESC)
      break;

  }while(1);

  cvDestroyAllWindows();
  cvReleaseImage(&frame);
  cvReleaseCapture(&capture);
  cvReleaseHaarClassifierCascade(&cascade);
  cvReleaseMemStorage(&storage);


  printf("Running time: %ldsec\n", (time(0) - time_start));
   for (int i=0; i<data.size(); i++) {
 	for(int a=0;a<cars[i].size();a++){
  		int detected=0;
	      for(int b=0;b<rectagles[i].size();b++){
     // std::cout << "car coordinates " << (cars[i][a]).x <<" "<<(cars[i][a].y)<<" "<<(cars[i][a].x+cars[i][a].width) <<" "<< (cars[i][a].y+cars[i][a].height)<<"\n"; 
     //    std::cout << "detect coordinates " << (rectagles[i][b]).x <<" "<<(rectagles[i][b].y)<<" "<<(rectagles[i][b].x+rectagles[i][b].width) <<" "<< (rectagles[i][b].y+rectagles[i][b].height)<<"\n";
     //    std::cout << "Area of car= "<<(cars[i][a]).area() <<"\n";
     //    std::cout << "Area of detect= "<<(rectagles[i][b]).area()<<"\n";        
     //    std::cout << "Area of intersection= "<<((cars[i][a])&(rectagles[i][b])).area() <<"\n";
     //    std::cout << "Area of union= "<<((cars[i][a])|(rectagles[i][b])).area()<<"\n";
     //    std::cout << "IoU= "<<(((cars[i][a])&(rectagles[i][b])).area()/((cars[i][a])|(rectagles[i][b])).area()) << "\n";
        if( ((cars[i][a])&(rectagles[i][b])).area()/((cars[i][a])|(rectagles[i][b])).area() >= 0.1){
            detected=1;
        }
  		}
      if(detected==1){
        tp[i]++;
      }
  	  else{
        fn[i]++;
      }

    }  	

    for(int a=0;a<rectagles[i].size();a++){
      int blank=1;
      for(int b=0;b<cars[i].size();b++){
      //  std::cout << (((cars[i][b])&(rectagles[i][a])).area()/((cars[i][b])|(rectagles[i][a])).area()) << "\n";
        if( ((cars[i][b])&(rectagles[i][a])).area()/((cars[i][b])|(rectagles[i][a])).area() >= 0.1){
            blank=0;
        }
      }
      if(blank==1){
        fp[i]++;
      }
      // else{
      //   fn[i]++;
      // }

    } 
  	if(data[i]==result[i]){
  		e++;
  	}

    if(tp[i]+fp[i]!=0){
      precision[i]=tp[i]/(tp[i]+fp[i]);
    }
    else{
      precision[i]=1;
    }

    recall[i]=tp[i]/(tp[i]+fn[i]);

    // std::cout<<"Truepositive= "<< tp[i] << "\n";
    // std::cout<<"Falsepositive= "<< fp[i] << "\n";
    // std::cout<<"Falsenegative= "<< fn[i] << "\n";
    // std::cout<<"Precision= "<< precision[i] << "\n";
    // std::cout<<"Recall= "<< recall[i] << "\n";

  }
  e=((float)e/data.size())*100;
  std::cout<<"Estimated Accuracy= "<< e << "%" <<"\n";
  float p=0;
  float r=0;
  for(int i=0;i<data.size();i++){
    p+=precision[i];
    r+=recall[i];
  } 

  std::cout << "Overall precision= " << ((float)p/data.size()) << "\n";
  std::cout << "Overall recall= " << ((float)r/data.size()) << "\n";
  // std::cout << "Detected:\n";
  // for (int i=0; i<result.size(); i++) {
  //   std::cout << "Detected cars="<< result[i] << '\n';
  // }

  return 0;
}

std::vector<int> detect(IplImage *img, float scalefactor, float min_neighbours, float pfactor, float min_size)
{
  std::vector<int> detections;
  CvSize img_size = cvGetSize(img);
  CvSeq *object = cvHaarDetectObjects(
    img,
    cascade,
    storage,
    scalefactor, //1.1,//1.5, //-------------------SCALE FACTOR
    min_neighbours, //2        //------------------MIN NEIGHBOURS
    pfactor, //CV_HAAR_DO_CANNY_PRUNING
    cvSize(min_size, min_size),//cvSize( 30,30), // ------MINSIZE
    img_size //cvSize(70,70)//cvSize(640,480)  //---------MAXSIZE
    );

  //std::cout << "Total: " << object->total << " cars detected." << std::endl;
  detections.push_back(object->total);
  for(int i = 0 ; i < ( object ? object->total : 0 ) ; i++)
  {
    CvRect *r = (CvRect*)cvGetSeqElem(object, i);
    detections.push_back(r->x);
    detections.push_back(r->y);
    detections.push_back(r-> width);
    detections.push_back(r->height);
    cvRectangle(img,
      cvPoint(r->x, r->y),
      cvPoint(r->x + r->width, r->y + r->height),
      CV_RGB(255, 0, 0), 2, 8, 0);
  }

  cvShowImage("video", img);
  
  return detections;
}

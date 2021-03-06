#include <iostream>
#include <iomanip>
//#include <ncurses.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
 	 clock_t tStart = clock();
	 int i, n;
	 float x, sum, t;
	 float pi = 3.14159;
	 
	 x = atof(argv[1]);
	 n = atoi(argv[2]);
	 x = x*3.14159/180;
	 t = x;
	 sum = x;
	 /* Loop to calculate the value of Sine */
	 for(i=1;i<=n;i++)
	 {
	  t=(t*(-1)*x*x)/(2*i*(2*i+1));
	  sum=sum+t;
	 }
	 printf("Time taken: %.8fms\n", (double)(clock() - tStart)*1000/CLOCKS_PER_SEC);
	
	 

	 float sum_1000 = x;
	 float err = 0.0;
	 t = x;
	for(i=1;i<=1000;i++)
	 {
	  t=float(t*(-1)*x*x)/(2*i*(2*i+1));
	  sum_1000=sum_1000+t;
	 }
	 if(sum > sum_1000){
	 	err = (sum - sum_1000)*100/sum_1000 ;
	 }
	 else{
	 	err = (sum_1000 - sum)*100/sum_1000 ;
	 }
	

	 x = x*180/pi ;	
	 //cout<<" The value of Sin("<<x<<") = "<<sum;
	printf("Value of Sin(%0.1f) corresponding to %d terms of series = %0.8f\n", x, n, sum);
	printf("Error = %0.7f %\n", err);
	 return 0;
}


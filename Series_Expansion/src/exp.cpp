#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
 clock_t tStart = clock();
 int i, n;
 float x, sum, t;
 x = atof(argv[1]);
 n = atoi(argv[2]);	

 t=1;
 sum=1;
 /* Loop to calculate the value of Sine */
 for(i=1;i<=n;i++)
 {
  t=float(t*x/i);
  sum=sum+t;
 }
 printf("Time taken: %.8fms\n", (double)(clock() - tStart)*1000/CLOCKS_PER_SEC);
 t = 1;

 float sum_1000 = 1;
 float err = 0.0;
for(i=1;i<=1000;i++)
 {
  t=float(t*x/i);
  sum_1000=sum_1000+t;
 }
 if(sum > sum_1000){
 	err = (sum - sum_1000)*100/sum_1000 ;
 }
 else{
 	err = (sum_1000 - sum)*100/sum_1000 ;
 }	
printf("Value of exp(%0.1f) corresponding to %d terms of series = %0.8f\n", x, n, sum);

printf("Error = %0.7f %\n", err);


 return 0;
}


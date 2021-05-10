#include <stdio.h>
#include <math.h>
    
double f(double x) {
	double y;
	y = x*x + 2*x -1;
	return y;
}              
    
int main(void){
 
double a = 0, b = 4, delta, x1, x2, x3;
double value1 = 0, value2 = 0;
int i,N;

	printf("何等分しますか。");
	scanf("%d",&N);
                               
        delta=(b-a)/N;

/*台形法-----------------------------------------------------------------------------------------------*/
        for(i=0; i<N; i++){
		x1 = a+i*delta;
		x2 = x1+delta;
        	value1 += (f(x1)+f(x2))*delta/2;
        }

/*シンプソン法-----------------------------------------------------------------------------------------*/
        for(i=0; i<N; i=i+2){
		x1 = a+i*delta;
		x2 = x1+delta;
		x3 = x2+delta;
        	value2 += (f(x1)+4*f(x2)+f(x3))*delta/3;
        }

/*結果-------------------------------------------------------------------------------------------------*/
        printf("ー結果ー\n 台形法のとき:%f\n シンプソン法のとき:%f\n", value1, value2);
     
        return 0;
}

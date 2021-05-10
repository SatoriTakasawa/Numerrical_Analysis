include <stdio.h>
#include <stdlib.h>

int main()
{
        double i,imax=100000000.0,n=0.0;
        double x,y,pi;

        for(i=0;i<=imax;i++) {

                x=rand()/(RAND_MAX+1.0);
                y=rand()/(RAND_MAX+1.0);        

                if((x*x+y*y)<=1.0) {                     
                        n++;                                 
                }
        }

        pi=n/imax*4.0;         

        printf("結果:%f\n",pi);
        printf("実際のπ:3.141592\n");
        printf("誤差:%f\n",pi-3.141592);
        return 0;
}

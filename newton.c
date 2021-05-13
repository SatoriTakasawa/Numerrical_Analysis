#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
  return x*x-3;
}

double d_f(double x){
  return 2*x;
}

int main(void){
 FILE *outputfile;
 int n_max;
// FILE *data, *gp;
// char *data_file;
 int n =0;
 double x,eps,del;

outputfile = fopen("graph.txt", "w");
if(outputfile == NULL){
printf("cannot open\n");
//data_file="out.dat";
//data = fopen(data_file,"w");
}

printf("初期値x,小さい数eps,最大繰り返し回数n_maxを入力\n");
printf("x =");
scanf("%lf", &x);
fprintf(outputfile,"%.lf 0\n",x);
printf("eps = ");
scanf("%lf",&eps);
printf("n_max = ");
scanf("%d", &n_max);

do{
  del = -f(x) / d_f(x);
  x = x + del;
  n++;
  printf("[round: %d], x = %.10lf\n", n, x);
  //fprintf
  fprintf(outputfile, "%.10lf 0\n",x);
 // fprintf(data_file, "%.10lf 0\n",x);   
}while(fabs(del) > eps && n <= n_max);

if(n == n_max){
  printf("失敗\n");
}else{
  printf("近似値は%.10lf\n試行回数は%d回\n",x,n);
}

return 0;

}

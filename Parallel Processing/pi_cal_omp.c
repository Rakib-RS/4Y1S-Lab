#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
double sum = 0.0;
int thread_count, n = 10000;
void pi_cal();
int main(int argc,char *argv[]){
    long thread;
    thread_count = strtol(argv[1], NULL, 10);
#pragma omp parallel num_threads(thread_count)
    pi_cal();
    sum = sum * 4.0;
    printf("%.8lf\n", sum);
    return 0;
}
void pi_cal(){
    long myrank = omp_get_thread_num();
    double local_n = n / thread_count;
    int start = myrank * local_n;
    int end = start + local_n;
    int i;
    double factor;
    if(start%2 == 0){
        factor = 1;
    }
    else
        factor = -1;
    for (i = start; i < end;i++,factor = -factor){
    #pragma omp critical  
        sum += factor / (2 * i + 1);
       
    }
}
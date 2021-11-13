#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
double sum = 0.0;
int thread_count, n = 10000;
pthread_mutex_t mutex;
void *pi_cal(void *rank);
int main(int argc,char *argv[]){
    long thread;
    thread_count = strtol(argv[1], NULL, 10);
    pthread_t *thread_handles;
    pthread_mutex_init(&mutex,NULL);
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    for (thread = 0; thread < thread_count;thread++){
        pthread_create(&thread_handles[thread], NULL, pi_cal, (void *)thread);
    }
    for (thread = 0; thread < thread_count;thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    sum = sum * 4.0;
    printf("%.8lf\n", sum);
    free(thread_handles);
    pthread_mutex_destroy(&mutex);
    return 0;
}
void *pi_cal(void *rank){
    long myrank = (long)rank;
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
        pthread_mutex_lock(&mutex);
        sum += factor / (2 * i + 1);
        pthread_mutex_unlock(&mutex);
    }
}
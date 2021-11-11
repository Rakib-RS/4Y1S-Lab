#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//parallel specific variables;
long thread_count = 8;
double a;
double b;
long int n;//number of trapezoidal
double h;
double global_sum;
//for busy-waiting
int wait_flag = 0;
//mutex dec
pthread_mutex_t mutex;

void *Trap(void* rank);
double f(double x);

int main(int argc, char *argv[])
{
    thread_count = strtol(argv[1], NULL, 10);
    long thread;
    pthread_t *thread_handles;
    //create thread handles and initialize mutex;
    pthread_mutex_init(&mutex, NULL);

    thread_handles = malloc(thread_count * sizeof(pthread_t));
    a = 0.0;
    b = 3.0;
    n = 100000;
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_create(&thread_handles[thread], NULL, Trap, (void *)thread);
    }
    //join all the thread handles;
    for (thread = 0; thread < thread_count; thread++)
    {
        pthread_join(thread_handles[thread],NULL);
    }

    //fre thread handles and mutex;

    free(thread_handles);
    pthread_mutex_destroy(&mutex);
    printf("With n = %ld trapezoids, our estimate\n", n);
    printf("of the integral from %f to %f = %.15f\n\n",
           a, b, global_sum);
    return 0;
}
void* Trap(void* rank){
    long thread_rank = (long)rank;
    double local_sum = 0.0,x;
    double local_a, local_b;
    int local_n,i;
    local_n = n / thread_count;
    h = (b - a) / n;
    local_a = a + thread_rank * h * local_n;
    local_b = a + h * local_n;
    local_sum = (f(local_a) + f(local_b)) / 2.0;
    for (i = 1; i <= local_n - 1;i++){
        x = local_a + h * i;

        local_sum += f(x);
    }
    local_sum = local_sum * h;
    //update the global_sum;
    while(wait_flag != thread_rank);
    global_sum += local_sum;
    wait_flag = (wait_flag + 1) % thread_count;

    return NULL;
}
double f(double x){
    return x * x;
}

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#define SIZE 4
int thread_count;
void *matrix_mul(void *rank);
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
void fillup_mat(int m[SIZE][SIZE])
{
    int i, j, a;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            scanf("%d", &a);
            m[i][j] = a;
        }
    }
}
void print_mat(int m[SIZE][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin);
    thread_count = strtol(argv[1], NULL, 10);
    long thread;
    pthread_t* thread_handles;
    thread_handles = malloc(thread_count * sizeof(pthread_t));
    double difference;
    clock_t start = clock();//start time
    //master thread to do this first
    fillup_mat(A);
    fillup_mat(B);
    print_mat(A);
    print_mat(B);
    for(thread = 0; thread<thread_count; thread++){
        pthread_create(&thread_handles[thread], NULL, matrix_mul, (void *)thread);
    }
    for(thread = 0; thread<thread_count; thread++){
        pthread_join(thread_handles[thread], NULL);
    }
    print_mat(C);
    free(thread_handles);
    clock_t end = clock(); //finished time;
    //printf("%f", (double)end);
    difference = (double)(end - start)*1.0/CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %e\n", difference * 1000.0);
    printf("program exits\n");

    return 0;
}
void *matrix_mul(void *rank)
{
    int  from, to, i, j, k;
    long myid;
    myid = (long)rank; // returns the unique identification number for each thread(core)
    printf("my id = %ld\n", myid);
    //printf("Hello World from thread %d out of %d thread\n",myid,thread_count);

    from = myid * SIZE / thread_count;
    to = (myid + 1) * SIZE / thread_count;
    for (i = from; i < to; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

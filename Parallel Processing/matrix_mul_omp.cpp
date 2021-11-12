#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define SIZE 4
int thread_count;
void matrix_mul();
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
void fillup_mat(int m[SIZE][SIZE])
{
    int i, j, a;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            cin >> a;
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
    int myid;
    fillup_mat(A);
    fillup_mat(B);
    print_mat(A);
    print_mat(B);
#pragma omp parallel num_threads(thread_count)
    {

        /*this function is standard library function provided by openmp which
          return the total no. of thread created for this particular code */
        matrix_mul();
    }
    print_mat(C);
    printf("program exits\n");

    return 0;
}
void matrix_mul()
{
    int myid, from, to, i, j, k;
    myid = omp_get_thread_num(); // returns the unique identification number for each thread(core)
    printf("my id = %d\n", myid);
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

#include <stdio.h>
#include <omp.h>

int main()
{

    int myid, total_thread;

#pragma omp parallel
    {
        total_thread = omp_get_num_threads();
        /*this function is standard library function provided by openmp which
           return the total no. of thread created for this particular code */

        myid = omp_get_thread_num(); // returns the unique identification number for each thread(core)

        printf("Hello World from thread %d out of %d thread\n", myid, total_thread);
    }
    printf("program exits\n");

    return 0;
}
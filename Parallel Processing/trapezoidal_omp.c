#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void Trap(double left_endpt, double right_endpt, int trap_count, double *global_result);
double f(double x);
int main(int argc, char *argv[])
{
    double global_result = 0.0;
    double a;
    double b;
    int n;
    int thread_count, id;
    //get number of thread from command line ./a.out 4
    thread_count = strtol(argv[1], NULL, 10);
    printf("enter a ,b,n:");
    scanf("%lf%lf%d", &a, &b, &n);
#pragma omp parallel num_threads(thread_count)
    Trap(a, b, n, &global_result);
    printf("with n = %d trapezoids,our estimate\n", n);
    printf("of the integral from %lf to %lf = %.14e\n", a, b, global_result);

    return 0;
}

void Trap(double left_endpt, double right_endpt, int trap_count, double *global_reslut)
{
    double h, x, my_result;
    double local_a, local_b;
    int i, local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    printf("caculate from thread %d out of %d\n", my_rank, thread_count);
    h = (right_endpt - left_endpt) * 1.0 / trap_count;
    local_n = trap_count / thread_count;
    local_a = left_endpt + my_rank * local_n * h;
    local_b = local_a + local_n * h;
    my_result = (f(local_a) + f(local_b)) / 2.0;
    for (i = 1; i <= local_n - 1; i++)
    {
        /* code */
        x = local_a + i * h;
        my_result += f(x);
    }
    my_result = my_result * h;

#pragma omp critical
    *global_reslut += my_result;
}
double f(double x)
{
    return x * x;
}
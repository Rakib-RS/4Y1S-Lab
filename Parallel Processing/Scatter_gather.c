#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
void read_array(int local_a[], local_n, int n, int my_rank, MPI_Comm com);
int main(){
    int my_rank, comm_sz, local_n, n,i,j;
    int *data, *temp,*local_data;
     printf("Enter n:");
        scanf("%d", &n);

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    local_n = n / comm_sz;
    data = malloc(n * sizeof(int));
    local_data = malloc(local_n * sizeof(int));

    //printf("%d %d\n", my_rank, comm_sz);
    //read data
    
    if(my_rank == 0){
        for ( i = 0; i < n; i++)
        {
            scanf("%d", &data[i]);
        }
        MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);
         MPI_Gather(local_data, local_n, MPI_INT,data, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else{
        MPI_Scatter(data, local_n, MPI_INT, local_data, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    }


    return 0;
}
void read_array(int local_a[], local_n, int n, int my_rank, MPI_Comm com){
    
}
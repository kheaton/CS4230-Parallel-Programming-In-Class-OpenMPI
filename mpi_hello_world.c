#include <mpi.h>
#include <stdio.h>

#define P 2
#define N 4

double A[N][N] = { { 1.1, 3.8, 8.2, 2.9 }
				 , { 0.4, 6.4, 2.5, 5.5 }
				 , { 3.2, 2.2, 0.5, 2.9 }
				 , { 0.2, 9.0, 0.6, 6,6 } };

double B[N][N] = { { 7.5, 2.9, 0.2, 1.4 }
				 , { 0.0, 2.4, 2.3, 3.6 }
				 , { 9.2, 2.8, 0.6, 4.2 }
				 , { 7.3, 1.2, 3.0, 2.7 } };

double C[N][N] = { { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 } };

int main(int argc, char** argv) {

  MPI_Init(NULL, NULL);

  //which processor am I?
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  //number of processors
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

  //What machine?
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int name_len;
  MPI_Get_processor_name(processor_name, &name_len);

  printf("Hello world from processor %s, rank %d out of %d processors\n",
         processor_name, world_rank, world_size);

  MPI_Finalize();
  /*
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < N; j++)
    {
      C[i][j] = 0;
      for(k = 0; k < N; k++)
      {
        C[i][j] = A[i][k * B[i][k];
      }
    }
  }
  */
}

// Create my a, temp a


// mpi scatter
//mpi i send	// source, if I am 1, its 0, if I am 0 it is 1
// mpi i receive
//calculation 1
// MPI wait
// calculation 2
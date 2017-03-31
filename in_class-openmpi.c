#include <mpi.h>
#include <stdio.h>

#define P 2
#define N 4

double A[N][N] = { { 5, 2, 6, 1 }
				 , { 0, 6, 2, 0 }
				 , { 3, 8, 1, 4 }
				 , { 1, 8, 5, 6 } };

double B[N][N] = { { 7, 5, 8, 0 }
				 , { 1, 8, 2, 6 }
				 , { 9, 4, 3, 8 }
				 , { 5, 3, 7, 9 } };

double C[N][N] = { { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 }
				 , { 0, 0, 0, 0 } };

double result = { { 96, 68, 69, 69 }
				, { 24, 56, 18, 52 }
				, { 58, 95, 71, 92 }
				, { 90, 107, 81, 142 } };

double myA[N][N] = { { 0, 0, 0, 0 }
				   , { 0, 0, 0, 0 }
				   , { 0, 0, 0, 0 }
				   , { 0, 0, 0, 0 } };

double tempA[N][N] = { { 0, 0, 0, 0 }
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


	// mpi scatter
	// mpi i send	// source, if I am 1, its 0, if I am 0 it is 1
	// mpi i receive
	// calculation 1
	// MPI wait
	// calculation 2

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

  MPI_Finalize();
}
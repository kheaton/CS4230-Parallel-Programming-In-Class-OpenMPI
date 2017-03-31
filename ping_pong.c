#include <mpi.h>
#include <stdio.h>

#define PING_PONG_LIMIT 10

int main(int argc, char ** argv) {
	MPI_Init(NULL, NULL);

	int world_rank, world_size;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	int ping_pong_count = 0;
	int partner_rank = (world_rank + 1) % 2;

	while(ping_pong_count < PING_PONG_LIMIT) {

		if(world_rank == ping_pong_count % 2) {
			ping_pong_count++;
			MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
			printf("Processor %d sent and incremented ping_pong_count %d to processor %d\n",
				world_rank, ping_pong_count, partner_rank);
		}
		else {
			MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("Processor %d received ping_pong_count %d from processor %d\n", 
				world_rank, ping_pong_count, partner_rank);
		}
	}

	MPI_Finalize();
}
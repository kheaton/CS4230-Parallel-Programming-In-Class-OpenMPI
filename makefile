
EXECS=mpi_hello_world send_and_receive ping_pong ring
MPICC?=mpicc

all: ${EXECS}

mpi_hello_world: mpi_hello_world.c
	${MPICC} -o mpi_hello_world.out mpi_hello_world.c

send_and_receive: send_and_receive.c
	${MPICC} -o send_and_receive.out send_and_receive.c

ping_pong: ping_pong.c
	${MPICC} -o ping_pong.out ping_pong.c

ring: ring.c
	${MPICC} -o ring.out ring.c

clean:
	rm -f ${EXECS}
	rm -f *.out
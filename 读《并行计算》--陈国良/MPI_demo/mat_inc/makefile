SRC1=mat_inc.c
SRC2=mat_inc_mpi.c

EXE1=mat_inc.out
EXE2=mat_inc_mpi.out

MPICC=mpicc

OBJ1=mat_inc.o
OBJ2=mat_inc_mpi.o

$(EXE1):$(OBJ1)
	gcc $^ -o $@
	
$(OBJ1):$(SRC1)
	gcc -c $< -o $@
	
$(EXE2):$(OBJ2)
	$(MPICC) $^ -o $@
	
$(OBJ2):$(SRC2)
	$(MPICC) -c $< -o $@
	
.PHONY:clean
clean:
	rm *.out -f
	rm *.o -f
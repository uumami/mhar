CUDADIR 			= /usr/local/cuda
MAGMADIR			= /app/magma-2.5.1
LSOLVER_LIB		    = ./lpsolve/liblpsolve55.a -ldl
PCG_GEN				= ./direction_creation/pcg-c-0.94/src/libpcg_random.a
OPENBLASDIR 	    = /usr/lib/x86_64-linux-gnu/openblas

# ----------------------------------------
# Flags and paths to MAGMA, CUDA, and LAPACK/BLAS
CC			= gcc
LDFLAGS = -Wall -lm -no-pie
# Flags and paths to MAGMA, CUDA, and LAPACK/BLAS
MAGMA_CFLAGS     := -DADD_ \
										-I$(MAGMADIR)/include \
										-I$(CUDADIR)/include

MAGMA_F90FLAGS   := -Dmagma_devptr_t="integer(kind=8)" \
										-I$(MAGMADIR)/include

# may be lib instead of lib64 on some systems
MAGMA_LIBS       := -L$(MAGMADIR)/lib   -lmagma_sparse -lmagma \
										-L$(CUDADIR)/lib64 -lcublas -lcudart -lcusparse \
										-L$(OPENBLASDIR)/lib -lopenblas
# ----------------------------------------
har:
	LD_LIBRARY_PATH=$MAGMADIR/lib:$CUDADIR/lib64:$OPENBLASDIR/lib
	$(CC) har.c -w -o har.o $(CFLAGS) $(MAGMA_F90FLAGS) $(LDFLAGS) $(MAGMA_CFLAGS) $(MAGMA_LIBS) $(LSOLVER_LIB) $(PCG_GEN)

clean:
	rm har.o

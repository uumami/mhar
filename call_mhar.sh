 #!/bin/bash
 export MAGMADIR=/app/magma-2.5.1
 export CUDADIR=/usr/local/cuda
 export OPENBLASDIR=/usr/lib/x86_64-linux-gnu/openblas
 export LD_LIBRARY_PATH=$MAGMADIR/lib:$CUDADIR/lib64:$OPENBLASDIR/lib
 gcc matrix_creation.c -w -o matrix_creation.o
./matrix_creation.o "$1" "$2"
make clean
make
./har.o "$1" "$3" "$4" "$5" "$2" "$6"

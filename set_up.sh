 #!/bin/bash
 mkdir output
 mkdir input_matrices
 tar -xf magma-2.5.1.tar.gz
 export CUDADIR=/usr/local/cuda
 export OPENBLASDIR=/usr/lib/x86_64-linux-gnu/openblas
 cp magma_make.inc /app/magma-2.5.1/make.inc
 cd /app/magma-2.5.1
 make

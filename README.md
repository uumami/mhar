# hit_and_run

Clone the repository, modify the ./docker_sh.sh file so the volume points to the github directory,
./set_up.sh
./call_mhar.sh type dim save padding iter

-type: {1:hypercube,  2:simplex,  3:simplex with more restrictions}
- dim: dimension of the space
- save: 0 just run, 1 print stuff, 2 actually save the the save file is specified by (output/test_type_dim_padding_iter.txt)
- padding: padding for the matrix
- iter: number of iterations
- verbose


Hit and Run algorithm for a regular polytope, using GPGPU. (MAGMA, LPSOLVER, PCG-c).

Most Investigation:
- Change the spath.sh in order to reflect the correct paths of the MAGMA libraries in the docker.
- Add a tutorial
- Fix the bug in the Chebyshev Routine (as of now is hardcoded to be able to replicate it)

Possible to do:
+ Modify the algorithm to support sparse matrices.
+ Add Strassen GPU
+ Add prototype functions to the headers to ease exposition

Nice to have:
+ Manage MAGAM threads via CUDA kernels in order to drastically reduce HOST-DEVICE communication.


Instructions, Dockerhub:
docker pull uumami/mhar:deploy_amazon
# Depends of you docker version (for amazon is runtime, vor newest docker version ise -gpus all)
docker run --gpus all -ti uumami/mhar:deploy_amazon
docker run --runtime=nvidia -ti uumami/mhar:deploy_amazon
	Inside the docker container:
	./call_mhar.sh $1 $2 $3 $4 $5 $6




Instructions, No Docker:
+ Clone the repository
+ Modify the .txt files in the input_matrices directory (columns separated by spaces, and rows by \n)
+ You need CUDA 6.0 or higher in order to run the routines so install it.
+ Modify the Makefile to refrect the correct paths for CUDA binaries and compilers in your computer.
+ Modify paths.sh to refeclec the correct directories of the libraries specified in the same file.
+ RUN:
  $ make
  $ ./har.o
+ Have Fun

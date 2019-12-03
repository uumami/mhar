/* ****************************************************************************
* This routines assume that the matrices were already allocated in the host memo
* ry. In particular with matrix routines
***************************************************************************** */
/***************************  count_rows *************************************
  * This function allocates matrices in the GPU
  * Requirements: None
  * Inputs:
      + h_matrix(* double): Pointer to host matrix (single array, no 2d). Must
      be previously allocated.
      + d_matrix(* double): Pointer to device matrix (single array not 2d)
      + m (unsigend): number of rows
      + n (unsigned): number of columns
      + Cuda contex variables
  * Output:
      + None (int), the matrix is allocated in GPU memory.
*******************************************************************************/
//int allocate_matrices_device(double * h_matrix, double ** d_matrix,
//unsigned m, unsigned n, cublasHandle_t handle, cudaError_t cudaStat,
//cublasStatus_t stat );

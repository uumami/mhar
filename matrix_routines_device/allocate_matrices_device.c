/* ----------------------- Compiler Libraries ------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* ----------------------- CUDA LIBRARIES ----------------------------------- */
#include <cuda_runtime.h>
#include "magma_v2.h"
#include <cuda.h>
#include "magma_lapack.h"
/* ------------------------------ Header ------------------------------------ */
#include "allocate_matrices_device.h"

double * pinned_transpose_host_matrix(double *h_matrix, unsigned m, unsigned n){
  // Recall: m->row, n->column
  magma_int_t m_m =  m;
  magma_int_t m_n =  n;

  magma_int_t err ; // error handler

  double *pinned_matrix;// Pin Matrix to device

  err = magma_dmalloc_pinned(&pinned_matrix, m_m*m_n);
  int l = 0; //index for new matrix
  for( int j=0; j < n; j++)
  {
    for(int i = 0; i < m; i++){
      pinned_matrix[l] = h_matrix[i*n + j];
      l++;
    }
  }
  return  pinned_matrix;
}

int allocate_matrices_device(double *h_matrix, double **d_matrix,
unsigned m, unsigned n, magma_queue_t queue, magma_int_t dev, int trans){

  // Recall: m->row, n->column
  magma_int_t m_m = m;
  magma_int_t m_n = n;

  magma_int_t err ; // error handler
  err = magma_dmalloc (&(*d_matrix) , m_m*m_n ); // allocate memory in device

  if(trans != 1){ // manage device pointer as transposed matrix
    // Remember the matrix are col-major, then we allocate the transpose
    magma_dsetmatrix (m_n, m_m, h_matrix, m_n, *d_matrix, m_n, queue);
  }else if(trans==1){ // manage device pointer as no transposed matrix
    double * t_h_matrix;
    // transposed host matrix to allow the device read it as transposed
    t_h_matrix = pinned_transpose_host_matrix(h_matrix, m, n);
    magma_dsetmatrix (m_m, m_n, t_h_matrix, m_m, *d_matrix, m_m, queue);
    magma_free_pinned(t_h_matrix);
  }
  return  0;
}

double * pin_matrices_host(double **h_matrix, unsigned m, unsigned n){
  // Recall: m->row, n->column
  magma_int_t m_m =  m;
  magma_int_t m_n =  n;

  magma_int_t err ; // error handler

  double *pinned_matrix;// Pin Matrix to device

  err = magma_dmalloc_pinned(&pinned_matrix, m_m*m_n);
  for( int i=0; i < m*n; i++)
  {
    pinned_matrix[i] = (*h_matrix)[i];
  }
  free(*h_matrix);
  return  pinned_matrix;
}

void print_matrices_in_routine(int m, int n, double * d_p, int transpose,
  magma_queue_t queue){
  double * h_p;
  h_p= malloc(m*n*sizeof(double));
  magma_dgetmatrix(m, n, d_p, m, h_p, m, queue);
  if (transpose){
    print_matrix_debug_transpose(h_p, m, n);
  }else{
    print_matrix_debug(h_p, m, n);
  }
  free(h_p);
}

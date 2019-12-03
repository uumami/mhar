/* ----------------------- Compiler Libraries ------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* -------------------------------------------------------------------------- */
// header
#include "allocate_matrices.h"

double * allocate_matrices_host(FILE *file, unsigned size){

  double *P;
  if (file == NULL){
    printf("The pointer to the file is invalid \n");
  }

  P = (double *)malloc(sizeof(double) * size);
  if (P == NULL){
    printf("The matrix pointer could not be genrated \n");
  }
  // Reads equality Matrices
  for (int j = 0; j < size; j++){
    fscanf(file, "%lf", &(P[j]));
  }

  return P;

}

int print_matrix_debug(double *P, unsigned n, unsigned m){
  // Recall (n,m) -> (rows,columns)
  // Print for
  for(int i = 0; i < n; i++){ // For over the rows
    for(int j = 0; j < m; j++){ // For over the columns
      printf("%.10lf ", P[j + i*m]);
    }
    printf("\n");
  }

  return 0;

}

int print_matrix_debug_transpose(double *P, unsigned n, unsigned m){
  // Recall (n,m) -> (rows,columns)
  // Print for
  for(int i = 0; i < n; i++){ // For over the rows
    for(int j = 0; j < m; j++){ // For over the columns
      printf("%.10lf ", P[j*n + i]);
    }
    printf("\n");
  }

  return 0;

}

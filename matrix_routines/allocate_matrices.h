/* ----------------------- Prototype functions ------------------------------ */

/***************************  count_rows *************************************
  * This function allocates the restriction matrices in the GPU
  * Requirements: None
  * Observations: Matrices will bew stored in an array fashion, no two Dimension
  al arrays used in this routines.
  * Inputs:
      + SIZE (unsigned): number of elements in the matrix
      + file (FILE *)Pointer to the txt File.
  * Output:
      + Returns the address where the matrix will live.
*******************************************************************************/
double * allocate_matrices_host(FILE *file, unsigned size);

/* *************************** Print Matrix Debug *************************** */
/*****************************************************************************
* This function prints the matrix or vector living in the pointer P
* Inputs:
  + double *P: Pointer to the matrix
  + unsigned n: Number of count_rows
  + unsigend m: NUmber of columns
* Output:
  + Int of success and prints the matrices
***************************************************************************** */
int print_matrix_debug(double *P, unsigned n, unsigned m);

/*
  The cuda handler is initialized in har.c main function. This handler is unsed
  during all the computation time.
*/

/***************** allocate_matrices_host_har ********************************
  * This function allocates and saves the matrices in memory.
  * Requirements: allocate_matrices
  * Inputs:
      + None
  * Output:
      + None, the matrices are allocated via the pointers defined in section
      Pointers to restrictions (at the beginning of this header file).
*******************************************************************************/
int allocate_matrices_host_har(int verbose);

/* *****************************************************************************
* This function calculates the Chebyshev center
* Requirements: allocated_matrices
* Inputs:
    + Double pointer to store the initial x
* Output:
    + A pointer where the Chebyshevcenter lives
***************************************************************************** */
double * interior_point(double * x_0,int verbose, int type);

/***************** allocate_matrices_host_har ********************************
  * This function allocates and saves the matrices in memory.
  * Requirements: allocate_matrices_host_har
  * Inputs:
      + None
  * Output:
      + Free allocated matrices in host
***************************************************************************** */
int free_host_matrices_har();

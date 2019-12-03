/*--------------------------- Standard Libraries -----------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*--------------------------------------------------------------------------- */

/*----------------------------- lp_solve library -----------------------------*/
#include "../lpsolve/lp_lib.h"
/*--------------------------------------------------------------------------- */

/******************************************************************************
  * Computes norm 2 of a vector
  + Input is the size of the vector and the vector.
  + Returns the norm 2 of the vector
*******************************************************************************/

double norm_2(int n, double *x, int r) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += pow(x[ r*n + i], 2.0);
  }
  return sqrt(sum);
}
/* ------------------------------------------------ */



double * get_initvalue(unsigned n, unsigned me, unsigned mi, \
  double * m_eq, double * b_eq, double * m_in, double * b_in) {

  double * x_0;
  x_0 = (double *)malloc(sizeof(double) * n);
  lprec *lp;
  lp = make_lp(0, 0);

  set_col_name(lp, (n+1), "R");

  // Objective function
  double obj_vector[n + 2];

  for (int i = 0; i < (n + 1); i++){
    obj_vector[i] = 0.0;
  }

  obj_vector[(n + 1)] = 1.0;

  // Set objective function
  set_obj_fn(lp, obj_vector);
  set_add_rowmode(lp, TRUE);

  // Set equality restrictions
  double aux[n + 2];

  for (int i = 0; i < me; i++){
    for (int j = 0; j < n; j++){
      aux[j + 1] = (m_eq[i*n + j]);
    }

    // ||a_i||_2
    aux[(n + 1)] = 0;
    add_constraint(lp, aux, EQ, b_eq[i]);
  }

    // Set inequality restrictions
  for (int i = 0; i < mi; i++){
    for (int j = 0; j < n; j++){
      aux[j + 1] = (m_in[i*n + j]);
    }

    // ||a_i||_2
    aux[(n + 1)] = norm_2(n, m_in, i);
    add_constraint(lp, aux, LE, b_in[i]);
  }

  // Positivity conditions
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
    {
      if(i == j){
        aux[j+1] = 1.0;
      } else{
        aux[j+1] = 0.0;
      }
    }

    aux[(n + 1)] = -1;
    add_constraint(lp, aux, GE, 0);
  }

  // End model definition
  set_add_rowmode(lp, FALSE);
  set_maxim(lp);

  // write_lp(lp,"lp.model");
  solve(lp);

  get_variables(lp, x_0);
  return x_0;
}

//int main(){
  //return 0;
//}

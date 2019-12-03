/* ----------------------- Compiler Libraries ------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/* -------------------------------------------------------------------------- */

// header
#include "read_matrix.h"


/****************************  count_rows *************************************/
/*----------------------------------------------------------------------------*/
unsigned count_rows(FILE *file){
// Reading character
  int ch    =   0;
// Flag for new line
  int aux_line   =  1;
// Number of lines
  unsigned lines =   0;

  // Warn about inexisting restrictions
  if(file == NULL){
    printf(" \n The program can not find the files containing the\
    restrictions in the folder input_matrices \n ");
  }

// Parsing the file
  while ((ch = fgetc(file)) != EOF){
    if (ch == '\n')         {aux_line = 1;}

  // 48 and 57 represents the ascii code for 0 and 9 respectibly
    if (ch <= 57 && ch >=48 && aux_line)  {lines++, aux_line=0;}
  }
  fclose(file);
  return lines;
}


/***************************  count_columns ***********************************/
unsigned count_columns(FILE *file)
{
// Reading character
  int ch    =   0;
//  Flag of new variable
  int aux_space  =  1;
// Number of vars
  unsigned vars  =   0;

// Debug for inexistent restrictions
if(file == NULL){
  printf(" \n The program can not find the files containing the\
  restrictions in the folder input_matrices \n ");
}

// Parsing the file to get the number of variables
  while ((ch = fgetc(file)) != EOF && ch != '\n')
  {
    if (ch == ' '){ // Values separeted by spaces
      aux_space = 1;
    } else if (ch == ','){ // Values separated by commas
      aux_space = 1;
    }
    // 48 and 57 represents the ascii code for 0 and 9 respectibly
    if (ch <= 57 && ch >=48 && aux_space)  {vars++, aux_space=0;}
  }
  fclose(file);
  return vars;
}

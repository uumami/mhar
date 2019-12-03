#include <stdlib.h>
#include <stdio.h>
#include <string.h>



/*
Create automatic restrictions for polytopes and hyper cubes and save them in in
put matrices
*/

int generate_restrictions(int type, unsigned dimm){

  FILE *fptr_AE;
  FILE *fptr_AI;
  FILE *fptr_bE;
  FILE *fptr_bI;

  // use appropriate location if you are using MacOS or Linux
  fptr_AE = fopen("input_matrices/A_equality.txt","w");
  fptr_AI = fopen("input_matrices/A_inequality.txt","w");
  fptr_bE = fopen("input_matrices/b_equality.txt","w");
  fptr_bI = fopen("input_matrices/b_inequality.txt","w");

  if((fptr_AE == NULL) | (fptr_AI == NULL) | (fptr_bE == NULL) | (fptr_bE == NULL))
  {
     printf("Error!");
     exit(1);
  }

  if (type==1){
  // Only inequality restrictions needed. I<1 and -I<1
    printf("Entered the loop");

    for(unsigned r=0; r<dimm; r++){
        for(unsigned c=0; c<dimm; c++){
          if(c==r){
            fprintf(fptr_AI,"%lf",1.0);
            fprintf(fptr_bI,"%lf",1.0);
          }else{
            fprintf(fptr_AI,"%lf",0.0);
          }
          if(c != (dimm -1)){fprintf(fptr_AI,"%s"," ");}
        }
        fprintf(fptr_AI,"%s","\n");
        fprintf(fptr_bI,"%s","\n");
    }

    for(unsigned r=0; r<dimm; r++){
        for(unsigned c=0; c<dimm; c++){
          if(c==r){
            fprintf(fptr_AI,"%lf",-1.0);
            fprintf(fptr_bI,"%lf",1.0);
          }else{
            fprintf(fptr_AI,"%lf",0.0);
          }
          if(c != (dimm -1)){fprintf(fptr_AI,"%s"," ");}
        }
        if(r != (dimm -1)){fprintf(fptr_AI,"%s","\n");}
        if(r != (dimm -1)){fprintf(fptr_bI,"%s","\n");}
    }

  }

  if (type==2){
  // Only inequality restrictions needed. -I<1

    for(unsigned c=0; c<dimm; c++){
      fprintf(fptr_AE,"%lf",(double)1.0);
      if(c != (dimm -1)){fprintf(fptr_AE,"%s"," ");}
    }
    fprintf(fptr_bE,"%lf",(double)1.0);


    for(unsigned r=0; r<dimm; r++){
        for(unsigned c=0; c<dimm; c++){
          if(c==r){
            fprintf(fptr_AI,"%lf",(double)-1.0);
            fprintf(fptr_bI,"%lf",(double)0.0);
          }else{
            fprintf(fptr_AI,"%lf",(double)0.0);
          }
          if(c != (dimm -1)){fprintf(fptr_AI,"%s"," ");}
        }
        if(r != (dimm -1)){fprintf(fptr_AI,"%s","\n");}
        if(r != (dimm -1)){fprintf(fptr_bI,"%s","\n");}
    }

  }
  
  
    if (type==3){
  // Only inequality restrictions needed. -I<1

    for(unsigned c=0; c<dimm; c++){
      fprintf(fptr_AE,"%lf",(double)1.0);
      if(c != (dimm -1)){fprintf(fptr_AE,"%s"," ");}
    }
    fprintf(fptr_bE,"%lf",(double)1.0);
    
    // Extra restrictions
    fprintf(fptr_AE,"%s","\n");
    fprintf(fptr_bE,"%s","\n");
    for(unsigned c=0; c<(dimm-2); c++){
      fprintf(fptr_AE,"%lf",(double)0.0);
      if(c != (dimm -1)){fprintf(fptr_AE,"%s"," ");}
    }
    fprintf(fptr_AE,"%lf",(double)1.0);
    fprintf(fptr_AE,"%s"," ");
    fprintf(fptr_AE,"%lf",(double)1.0);
    fprintf(fptr_bE,"%lf",(double).5);


    for(unsigned r=0; r<dimm; r++){
        for(unsigned c=0; c<dimm; c++){
          if(c==r){
            fprintf(fptr_AI,"%lf",(double)-1.0);
            fprintf(fptr_bI,"%lf",(double)0.0);
          }else{
            fprintf(fptr_AI,"%lf",(double)0.0);
          }
          if(c != (dimm -1)){fprintf(fptr_AI,"%s"," ");}
        }
        if(r != (dimm -1)){fprintf(fptr_AI,"%s","\n");}
        if(r != (dimm -1)){fprintf(fptr_bI,"%s","\n");}
    }

  }


  // Close all fill_matrix_zeros
     fclose(fptr_AE);
     fclose(fptr_AI);
     fclose(fptr_bE);
     fclose(fptr_bI);
     return 0;
}


void main(int argc,char *argv[]){

    int type = atoi(argv[1]);
    unsigned dimm=atoi(argv[2]);

    generate_restrictions(type, dimm);


}

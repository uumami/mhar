#include "random_normal_sample.h"
#include "pcg-c-0.94/include/pcg_variants.h"

/****************************** init_random_seeds *************************** */
void init_random_seeds(){
	srand(time(NULL));   // Initialization, should only be called once.
	int r = rand();
  	pcg64_srandom((double)r, (double)1.0);
}

double box_muller()	/* normal random variate generator */
{				        /* mean m, standard deviation s */
	double x1, x2, w, y1, e1, e2;
	static double y2;
	static int use_last = 0;

	if (use_last)		        /* use value from previous call */
	{
		y1 = y2;
		use_last = 0;
	}
	else
	{
		do {
      e1= (double) ldexp(pcg64_random(), -64);
      e2= (double) ldexp(pcg64_random(), -64);
			x1 = 2.0 * e1 - 1.0;
			x2 = 2.0 * e2 - 1.0;
			w = x1 * x1 + x2 * x2;
		} while ( w >= 1.0 );

		w = (double) sqrt( (-2.0 * log( w ) ) / w );
		y1 = (double)(x1 * w);
		y2 = (double)(x2 * w);
		use_last = 1;
	}

	return( 0.0 + y1 * 1.0 );
}

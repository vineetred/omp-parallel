#include <omp.h>
#include <stdio.h>
double step;
static long num_steps = 100000000;


int main() {

	int i, nthreads;
	double pi;
	omp_set_num_threads(7);
	step = 1.0/(double)num_steps;
	double start=omp_get_wtime();
	#pragma omp parallel 

	{

		int i, id, nthrds;
		double x,sum;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) {
			nthreads = nthrds;
		}

		for(i=id,sum=0.0; i<num_steps; i = i+nthrds){
			x =(i+0.5)*step;
			sum+=4.0/(1.0+x*x);
		}

		#pragma omp critical 
			pi+=sum*step;

	}
	double end=omp_get_wtime();
	printf("Time Taken: %f ",end-start);
	printf("Pi: %f",pi);
	}
#include <omp.h>
#include <stdio.h>
double step;
static long num_steps = 100000000;
#define PAD  8


int main() {

	int i, nthreads;
	double pi, sum[7][PAD];
	omp_set_num_threads(7);
	step = 1.0/(double)num_steps;
	double start=omp_get_wtime();
	#pragma omp parallel 

	{

		int i, id, nthrds;
		double x;
		id = omp_get_thread_num();
		nthrds = omp_get_num_threads();
		if (id == 0) {
			nthreads = nthrds;
		}

		for(i=id,sum[id][0]=0.0; i<num_steps; i = i+nthrds){
			x =(i+0.5)*step;
			sum[id][0]+=4.0/(1.0+x*x);
		}

	}
	double end=omp_get_wtime();
	for(i =0,pi=0.0;i<7;i++){
		pi+=sum[i][0]*step;
	}
	printf("Time Taken: %f",end-start);
	printf("Pi: %f",pi);
	}
#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
static long num_steps = 100000000;
int arr[100000000];
int arr2[100000000];
void main(){

	//randomising integers
	for(int i =0;i<num_steps;i++){

		arr[i] = rand();
		arr2[i] = rand();
	}

 	double start=omp_get_wtime();
 	int sum=0;
 	int j;

 	#pragma omp parallel 
 		{

 			#pragma omp for reduction(+:sum)
 			for(j=0;j<num_steps;j++){

 				sum = sum + arr[j] + arr2[j];
 			}

 		}

 	double end=omp_get_wtime();
 	printf("<==PARALLEL==>\n" );
	printf("Time Taken: %f \n",end-start);
	printf("Sum is: %d \n", sum);




}
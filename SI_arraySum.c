#include<omp.h>
#include<stdio.h>
#include <stdlib.h>
static long num_steps = 100000000;
int arr[100000000];
void main(){

	//randomising integers
	for(int i =0;i<num_steps;i++){

		arr[i] = rand();
	}

 	double start=omp_get_wtime();
 	int sum=0;
 	int j;

 		

 			for(j=0;j<num_steps;j++){

 				sum = sum + arr[j];
 			}

 		

 	double end=omp_get_wtime();
 	printf("<==SEQUENTIAL==>\n" );
	printf("Time Taken: %f \n",end-start);
	printf("Sum is: %d \n", sum);




}
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
static int number = 10000;
    
int Arr[10000];

void swap(int a, int b);
void selectionSort(int A[number], int n);

void main() {

    for(int i = 0;i<number;++i){

        Arr[i] = rand();
    }

    selectionSort(Arr, number);
}

void selectionSort(int A[number], int n){
    double start=omp_get_wtime();

    for(int startpos =0; startpos < n; startpos++){
        int maxpos = startpos;
        for(int i=startpos +1; i< n; ++i){
            if(A[i] < A[maxpos]){
                maxpos = i;
            }
        }
        int e1 = A[startpos];
        int e2 = A[maxpos];
        int e3=0;
        e3 = e1;
        e1 = e2;
        e2 = e3;
   
    }
     double end=omp_get_wtime();
    printf("<==SEQUENTIAL==>\n" );
    printf("Time Taken: %f \n",end-start);
}

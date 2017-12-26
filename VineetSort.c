#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

struct Compare { int val; int index; };
#pragma omp declare reduction(maximum : struct Compare : omp_out = omp_in.val > omp_out.val ? omp_in : omp_out)

void selectionsort(int* arr, int size)
{   double start=omp_get_wtime();
    int ele;

    for (int i = size - 1; i > 0; --i)
    {
        struct Compare max;
        max.val = arr[i];
        max.index = i;
        //parallelisation
        #pragma omp parallel for reduction(max:ele)
        for (int j = i - 1; j >= 0; --j)
        {   ele = arr[i];
            if (arr[j] > ele)
            {
                ele = arr[j];
                i = j;
            }
        }
        int tmp = arr[i];
        arr[i] = max.val;
        arr[max.index] = tmp;
    }
    double end=omp_get_wtime();
    printf("<==PARALLEL==>\n" );
    printf("Time Taken: %f \n",end-start);
}

int main()
{
        int x[500000];
        for(int j =0;j<500000;j++){
            x[j] = rand();
        }
        selectionsort(x, 500000);

        for (int i = 0; i < 10; i++)
                printf("%d\n", x[i]);
        return 0;
    }
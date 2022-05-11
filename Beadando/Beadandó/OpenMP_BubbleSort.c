#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2)
{

    int temp = *num1;
    *num1 =  *num2;
    *num2 = temp;
}

int main (int argc, char *argv[]) {
    int SIZE =400000;
    int A[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        A[i]=rand()%SIZE;
    }
    int N = SIZE;
    int i=0, j=0;
    int first;
    double start,end;
    start=omp_get_wtime();
    omp_set_dynamic(0);
    omp_set_num_threads(1);

    #pragma omp parallel reduction( +:first )

    for( i = 0; i < N; i++ )
    {

        first = i % 2;

        #pragma omp parallel for default(none),shared(A,first,N)

        for( j = first; j < N-1; j += 2 )
        {

            if( A[ j ] > A[ j+1 ] )
            {
                swap( &A[ j ], &A[ j+1 ] );
            }


        }

    }


    end=omp_get_wtime();
    /*for(i=0;i<N;i++)
    {
        printf(" %d",A[i]);
    }*/

    printf("\n-------------------------\n Time Parallel= %f",(end-start));
}

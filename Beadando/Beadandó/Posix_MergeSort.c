#include <pthread.h>
#include <time.h>
#include <stdlib.h>


#define MAX 120000000

#define THREAD_MAX 8


int a[MAX];
int part = 0;


void merge(int low, int mid, int high)
{
    int* left = (int*) malloc( (mid - low + 1) * sizeof(int));
    int* right = (int*) malloc( (high - mid) * sizeof(int));



    int n1 = mid - low + 1,
    n2 = high - mid,
    i, j;


    for (i = 0; i < n1; i++)
        left[i] = a[i + low];


    for (i = 0; i < n2; i++)
        right[i] = a[i + mid + 1];

    int k = low;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }


    while (i < n1) {
        a[k++] = left[i++];
    }

    while (j < n2) {
        a[k++] = right[j++];
    }

    free(left);
    free(right);
}

void merge_sort(int low, int high)
{
    int mid = low + (high - low) / 2;
    if (low < high) {

        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

void* merge_sort123(void* arg)
{

    int thread_part = part++;


    int low = thread_part * (MAX / THREAD_MAX);
    int high = (thread_part + 1) * (MAX / THREAD_MAX) - 1;


    int mid = low + (high - low) / 2;
    if (low < high) {
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
    return 0;
}

int main()
{

    for (int i = 0; i < MAX; i++){
        a[i] = rand() % 100;

    }


    pthread_t threads[THREAD_MAX];
    clock_t start, end;
    double runtime;


    start = clock();
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[i], NULL, merge_sort123,(void*)NULL);


    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);

    end = clock();
    runtime = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Threads were running for : %f\n", runtime);


    merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
    merge(MAX / 2, MAX/2 + (MAX-1-MAX/2)/2, MAX - 1);
    merge(0, (MAX - 1)/2, MAX - 1);

    return 0;
}

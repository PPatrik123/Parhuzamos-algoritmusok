#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

void varegyet(void * args);
void id(int thread_id);

pthread_mutex_t value_mutex = PTHREAD_MUTEX_INITIALIZER;
int main()
{
    pthread_t szalak[60];
    for(int i = 0; i < 60; i++)
    {

        pthread_create(&szalak[i],NULL,varegyet,i);
    }
    for(int i = 0; i < 60; i++)
    {
        pthread_join(szalak[i],NULL);
    }
    return 0;
}

void varegyet(void * args)
{
    Sleep(1000);
    id(args);
}
void id(int thread_id)
{
    pthread_mutex_lock(&value_mutex);
    printf("szal %d Kesz!\n", thread_id);
    pthread_mutex_unlock(&value_mutex);
}

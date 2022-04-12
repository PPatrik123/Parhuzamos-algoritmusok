#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

void var(void * args);
void var2(void * args);

int main()
{
    pthread_t szal;
    pthread_create(&szal,NULL,var,NULL);
    printf("Fo-szal : 8mp szamitas!\n");
    Sleep(8000);
    printf("Fo-szal : Kesz!\n");
    pthread_join(szal,NULL);


    pthread_create(&szal,NULL,var2,NULL);
    printf("Fo-szal : 4mp szamitas!\n");
    Sleep(4000);
    printf("Fo-szal : Kesz!\n");
    pthread_join(szal,NULL);
    return 0;
}
void var(void * args)
{
    printf("Szal : 4mp szamitas!\n");
    Sleep(4000);
    printf("Szal : Kesz!\n");
}

void var2(void * args)
{
    printf("Szal : 8mp szamitas!\n");
    Sleep(8000);
    printf("Szal : Kesz!\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
void eltolas();
void sleepT();
int main(int argc, char *argv[])
{
    printf("Hello world!\n");
    eltolas();
    sleepT();


    printf("Random szam 500 es 1000 kozott\n");
    srand(time(NULL));
    int randomNumber = rand() % ((1000 + 1) - 500) + 500;
    printf("%d\n", randomNumber);



void sleepT()
{
    printf("10 masodpercet varunk!\n");
    Sleep(10000);
    printf("Kesz!\n");
}

void eltolas()
{
    printf("eltolas elott\n");
    printf("%d\n",0);
    printf("eltolas utan\n");
    printf("%*d\n",8,0);


}


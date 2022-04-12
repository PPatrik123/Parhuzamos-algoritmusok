#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 20
float random(float min, float max);

int main(int arc, char **argv)
{
    srand(time(NULL));
    float tomb[K];
    float szorzo = 1.0;

    for (int i=0; i<K; i++)
        tomb[i] = random(0.0,100.0);
    for (int i=0; i<K; i++)
        szorzo = szorzo * tomb[i];
    printf("Osszeszorozva : %d ", szorzo);
}

float random(float min, float max)
{
    float ran = ((float)rand()) / RAND_MAX;
    float szam = ran * (max - min) + min;
    return szam;
}

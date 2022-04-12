#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 20
float random(float min, float max);
float rekmult(float * tomb, int size);

int main(int arc, char **argv)
{
    srand(time(NULL));
    float tomb[K];
    float szorzo = 1.0;

     for (i=0; i<K; i++)
        tomb[i] = RNG_Double(0.0,100.0);
    printf("Osszeszorozva: %.2f\n", rekmult(tomb, K));
}
}

float random(float min, float max)
{
    float ran = ((float)rand()) / RAND_MAX;
    float szam = ran * (max - min) + min;
    return szam;
}

float rekmult(float * tomb, int size)
{
    float lhalf = 1;
    float rhalf = 1;
    if (size == 1){
        return tomb[0];
    }
    else
    {
        lhalf = recursive_multi(tomb, size/2);
        rhalf = recursive_multi(tomb+(size/2), size-(size/2));
        return lhalf*rhalf;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define tomb 3

void szekvencialis_szorzas(double pDouble[tomb]);
void redukcios_szorzas_openMP(double pDouble[tomb]);
void for_szorzas_openMP(double pDouble[tomb]);

int main() {
    srand(time(NULL));

    double randomtomb[tomb];

    for (int i = 0; i < tomb; i++) {
        randomtomb[i] = (float)rand()/(float)(1000);
    }

    for (int i = 0; i < tomb; i++) {
        printf("%f\n", randomtomb[i]);
    }

    szekvencialis_szorzas(randomtomb);
    redukcios_szorzas_openMP(randomtomb);
    for_szorzas_openMP(randomtomb);
    return 0;
}

void redukcios_szorzas_openMP(double pDouble[tomb]) {
    double eredmeny = 1;

    for (int i = 0; i < tomb; i++) {
        eredmeny *= pDouble[i];
    }
    printf("OpenMP redukcios szorzas eremenye: %f\n", eredmeny);
}

void szekvencialis_szorzas(double pDouble[tomb]) {
    double eredmeny = 1;
    for (int i = 0; i < tomb; i++) {
        eredmeny *= pDouble[i];
    }
    printf("Szekvencialis szorzas eredmenye: %f\n", eredmeny);
}

void for_szorzas_openMP(double pDouble[tomb]){
    double eredmeny = 1;

    for (int i = 0; i < tomb; i++) {
        eredmeny *= pDouble[i];
    }
    printf("OpenMP For szorzasanak eredmenye: %f\n", eredmeny);
}

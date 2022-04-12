#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int osszeg(int tomb[],int meret);
int maxx(int tomb[],int meret);
int minn(int tomb[],int meret);
int addNumbers(int tomb[], int meret);
int maxx2(int tomb[], int meret);
int minn2(int  tomb[], int meret);
int main(){

    clock_t begin;
    double time_spent_min = 0;
    double time_spent_max = 0;
    double time_spent_rekmax = 0;
    double time_spent_rekmin = 0;
    srand(time(0));
    int meret = 20;
    int tomb[meret];
    int b;
    for ( b = 0; b < meret; b++)
    {
        tomb[b] = rand() % 36;
    }

    for ( b = 0; b < meret; b++)
    {
        printf("%d\n",tomb[b]);
    }
    for(int j = 1000; j <= 50000; j = j + 1000)
    {
        for(int i = 0; i < j; i++)
        {
        begin = clock();
        maxx2(tomb,meret);
        begin = clock() - begin;
        time_spent_rekmax = ((double)begin / CLOCKS_PER_SEC) + time_spent_rekmax;
        begin = clock();
        maxx(tomb,meret);
        begin = clock() - begin;
        time_spent_max = ((double)begin / CLOCKS_PER_SEC) + time_spent_max;
        begin = clock();
        minn(tomb,meret);
        begin = clock() - begin;
        time_spent_min = ((double)begin / CLOCKS_PER_SEC) + time_spent_min;
        begin = clock();
        minn2(tomb,meret);
        begin = clock() - begin;
        time_spent_rekmin = ((double)begin / CLOCKS_PER_SEC) + time_spent_rekmin;



        }


            printf("Maximum Rekurziv Meres: %f mp %d eseten\n", time_spent_rekmax, j);
            printf("Minimum Rekurziv Meres: %f mp %d eseten\n", time_spent_rekmin, j);
            printf("Maximum Manualis Meres: %f mp %d eseten\n", time_spent_max, j);
            printf("Minimum Manualis Meres: %f mp %d eseten\n", time_spent_min, j);
            printf("\n");

    }

    printf("osszeg = %d\n",osszeg(tomb,meret));
    printf("maximum = %d\n",maxx(tomb,meret));
    printf("minimum = %d\n",minn(tomb,meret));
    printf("osszeg 2 = %d\n",addNumbers(tomb,meret));
    printf("maximum 2 = %d\n",maxx2(tomb,meret));
    printf("minimum 2 =%d",minn2(tomb,meret));

    return 0;
}


int osszeg(int tomb[],int meret)
{
    int i,sum = 0;
    for (i = 0; i < meret; i++)
    {
        sum = tomb[i] + sum;
    }

    return sum;
}
int maxx(int tomb[],int meret)
{
    int i;
    int max = 0;
    for (i = 0; i < meret; i++)
    {
        if(tomb[i] > max)
        {
            max = tomb[i];
        }

    }
    return max;
}

int minn(int tomb[],int meret)
{
    int min = tomb[0];
    for (int i = 0; i < meret; i++)
    {
        if(min > tomb[i])
        {
            min = tomb[i];
        }
    }

    return min;
}
int addNumbers(int tomb[], int meret)
{

   if(meret == 0)
   {
       return 0;
   }
   else
   {
       return tomb[meret-1]+addNumbers(tomb, meret-1);
   }

}
int maxx2(int tomb[], int meret)
{
   int m_max;
    if(meret==1){
        return tomb[0];
    }
    m_max=maxx2(tomb,meret-1);
    if(tomb[meret-1]>m_max)
        m_max=tomb[meret-1];
    return m_max;

}
int minn2(int  tomb[], int meret)
{
    int m_min;
    if(meret==1){
        return tomb[0];
    }
    m_min=minn2(tomb,meret-1);
    if(tomb[meret-1]<m_min)
        m_min = tomb[meret-1];
    return m_min;
    }




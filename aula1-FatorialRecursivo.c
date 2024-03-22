#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int Fatorial(int N);

int Fatorial(int N){
    if(N == 0) return(1);
    else if (N > 0) return(N * Fatorial(N - 1));
    else return 
}
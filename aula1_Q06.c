#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define ERRO -1234

int g(int N);

void main(){
    system("cls");
    int X = g(3);
    printf("Resposta: %d\n", X);

}

int g(int N){
    if(N == 0) return (-1);
    else if (N > 0) return (4 * g(N - 1) + 6);
}
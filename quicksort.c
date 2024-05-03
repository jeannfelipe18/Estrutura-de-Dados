#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define TAMANHO 400000
#define VERDADEIRO 1
#define FALSO 0

void swap (int *A, int *B);

void main(){
    system("cls");
    int X = 10;
    int Y = 20;
    printf("Original: X = %d e Y = %d \n",X, Y);
    swap(&X,&Y);
    printf("Original: X = %d e Y = %d \n",X, Y);
}


void swap (int *A, int *B){
    int temp = *A;  //*A: valor apontado por A
    *A = *B;
    *B = temp;
    printf("Teste: %d %d %d %d \n", A, *A, B, *B);
}
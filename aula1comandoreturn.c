#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char minusculo();

int main(){
    system("cls");
    char letra = minusculo();
    printf("\n%c", letra);
    return 0;
}

char minusculo() {
    char ch = getche(); // ler um caractere, apenas.
    if((ch >= 'A') && (ch <= 'Z')) return(ch + 32);
    else return (ch);
}
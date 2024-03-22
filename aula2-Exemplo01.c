#include<conio.h>
#include<string.h>

#define ERRO -1234

//String: cadeira de caracteres terminada com\0
//VASCO tem \0 na posição 5

int MyStrlen(char *str);

void main(){
    char Frase[] = "Meu nome e Eneias!!!";
    printf("%s - %d caracteres.\n", Frase, MyStrlen(Frase));
}

int MyStrlen(char *str){
    int Tamanho;
    for(Tamanho = 0; str[Tamanho] != '\0'; Tamanho++);
    return(Tamanho);
}
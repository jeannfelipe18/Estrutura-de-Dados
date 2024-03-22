#include<stdio.h>
#include<stdlib.h>

char f(int x);

int main(){
    char x = f('D' - 64);
    printf("Resposta: %c.\n", x);
    return 0;
}
char f(int x){
    if(x == 1) return('C');
    else if (x == 2) return('D');
    else if (x == 3) return('E');
    else if (x == 4) return('B');
    else if (x == 5) return('E');
    else {
        printf("A função não está definida para x = %d", x);
        exit(1);
    }
}
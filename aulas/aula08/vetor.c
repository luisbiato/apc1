#include <stdio.h>

int main (){

    int numeros[10];

    numeros[0] = 3;
    numeros[1] = 5;
    numeros[2] = 2;
    numeros[3] = 8;
    numeros[4] = 1;
    numeros[5] = 4;
    numeros[6] = 6;
    numeros[7] = 9;
    numeros[8] = 7;
    numeros[9] = 10;

    for (int i = 0; i<10; i++){
        printf("%i, ", numeros[i]);
    }


    return 0;
}
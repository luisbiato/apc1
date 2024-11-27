#include <stdio.h>

int main (){

int numeros[10];
int numero;
int achou = -1;
for(int i=0;i<10;i++){
    printf("Entre com o valor do numero %i.\n", i+1);
    scanf("%i", &numeros[i]);
}

scanf("%i", &numero);
for(int i = 0;i<10;i++){
    if (numeros[i] == numero) {
  achou = i;
}}

if(achou <0){
    printf("O numero nao foi encontrado!");
} else{
    printf("O numero foi encontrado na posição %i\n",achou);
}





    return 0;
}
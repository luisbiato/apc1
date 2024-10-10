#include<stdio.h>
#include<stdlib.h>
#include <string.h>


struct extrato
{
    char operacao[10];
    float valor;

};
typedef struct extrato extrato;

int main(){
int i = 0;
int j = 0;
extrato operacoes[10];

for (i=0;i<5;i++)
{
    strcpy(operacoes[i].operacao,"Deposito");
    operacoes[i].valor = i+1;
}


for (j=0;j<i;j++)
{
   printf("%s\t",operacoes[j].operacao);
    printf("%f\n",operacoes[j].valor);

}





    return 0;
}
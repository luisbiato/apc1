#include <stdio.h>
#include<string.h>

int main (){

const int DOMINGO = 1;
const int SEGUNDA = 2;
const int TERCA = 3;
const int QUARTA = 4;
const int QUINTA=5;
const int SEXTA=6;
const int SABADO=7;


enum dias_da_semana_e {
    dom,
    seg,
    ter,
    qua,
    qui,
    sex,
    sab
};

enum boolean {false,true};

int dia;
printf("Entre com o dia da semana: ");
scanf("%i", &dia);

switch(dia){
    case dom: printf("Domingo\n");break;
    case seg: printf("Segunda\n");break;
    case ter: printf("Terca\n");break;
    case qua: print("Quarta\n");break;
    case qui: printf("Quinta\n");break;
    case sex: printf("Sexta\n");break;
    case sab: printf("Sabado\n");break;
    default: printf("Dia invalido\n");break;
    }




    return 0;
}
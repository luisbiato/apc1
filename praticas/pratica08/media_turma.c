#include <stdio.h>

int main (){

    float notas[10];
    float soma = 0;
    float media=0;
    int qtde_acima_media=0;

    for(int i=0;i<10;i++){
        printf("Entre com a nota do aluno %i: ", i+1);
        scanf("%f", &notas[i]);
        soma = soma + notas[i];
    }
    media = soma /10;

    for(int i=0;i<10;i++){
        if(notas[i]>media){
            qtde_acima_media++;
        }
    }
printf("Media = %f\n", media);
printf("Alunos acima da media = %i\n", qtde_acima_media);




    return 0;
}
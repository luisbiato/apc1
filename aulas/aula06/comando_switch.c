#include<stdio.h>

int main(){

    int nota = 0;

    printf("Entre com uma nota de 1 a 5: ");
    scanf("%i", &nota);

    // if (nota == 1)
    // {
    //     printf( "Você ganhou 1 estrela!\n");
    // } else if (nota == 2)
    // {
    //     printf( "Você ganhou 2 estrela!\n");
    // } else if (nota == 3)
    // {
    //     printf( "Você ganhou 3 estrela!\n");
    // } else if (nota == 4)
    // {
    //     printf( "Você ganhou 4 estrela!\n");
    // } else if (nota == 5)
    // {
    //     printf( "Você ganhou 5 estrela!\n");
    // } else 
    // {
    //     printf("Nota invalida!\n");
    // }
    
    switch (nota)
    {
    case 1:
       printf( "Você ganhou 1 estrela!\n");
        break;
    case 2:
       printf( "Você ganhou 2 estrela!\n");
        break;
    case 3:
       printf( "Você ganhou 3 estrela!\n");
        break;
    case 4:
       printf( "Você ganhou 4 estrela!\n");
        break;
    case 5:
       printf( "Você ganhou 5 estrela!\n");
       break;
    default:

        break;
    }



    return 0;
}
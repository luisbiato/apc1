#include <stdio.h>

int main()
{

    char frase[31] = "";
    char matriz[6][5] = {"","","","","",""};
    int k = 0;
    scanf("%[^\n]s", frase);
    while(getchar() != '\n');
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j]= frase[k];
            k++;
        }
    }
    printf("A transposicao da frase eh ");
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("%c", matriz[i][j]);
        }
    }

    printf("\n\n");
    return 0;
}
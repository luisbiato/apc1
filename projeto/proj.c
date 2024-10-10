#include <stdio.h>
#include <string.h>
#include <locale.h>

struct extrato
{
    char operacao[10];
    float valor;
    // float saldo;
};
typedef struct extrato extrato;

int main() {
    //Correção de acentuação
    setlocale(LC_ALL, "Portuguese");

    //criacao de variaveis
    char menu[] = "\n\tBANCO APC1\n\nMENU(Escolha a opção desejada):\n[d] = Depositar\n[s] = Sacar\n[e] = Extrato\n[q] = Sair\n[a] = Ajuda\n";

    float saldo = 0.0f;
    int limite = 500;
    int limite_saques = 3;
    extrato operacoes[20];
    int numero_saque = 0;
    char operacao = '\0';
    int i = 0;
        // memset(operacoes,'1',sizeof(operacoes));


    while (1) {
        //entrada de dados com escolha do menu
        printf("%s", menu);
        scanf("%c",&operacao);
        while (getchar() != '\n') {getchar();}
        
        switch (operacao){
            case 'd':
                float deposito = 0.0f;
                printf("Valor a ser depositado: ");
                scanf("%f", &deposito);
                while (getchar() != '\n') {getchar();}
                        
                if (deposito <= 0) {
                    printf("O valor é invalido. Operação não realizada!\n");

                } else if (deposito > 9999999999999) {
                    printf("O valor é muito alto. Vá na sua agencia!\n");
                
                }else if (deposito > 0) {
                    saldo += deposito;
                    strcpy(operacoes[i].operacao,"Deposito: ");
                    operacoes[i].valor = deposito;

                    // char buffer[100];
                    // snprintf(buffer, sizeof(buffer), "Depósito:\tR$ %.2f\n", deposito);
                    // printf("%s", buffer);
                    // strcat(extrato, buffer);      


                    i++; 
                }break;

            case 's':
                float saque = -1.0f;
                printf("Valor a ser sacado: ");
                scanf("%f", &saque);
                while (getchar() != '\n') {getchar();}
                
                if (saque > saldo) {
                    printf("Saldo insuficiente. Operação não realizada!\n");
                }else if (saque > limite) {
                    printf("Valor máximo de saque é de R$500,00. Operação não realizada!\n");
                }else if (numero_saque >= limite_saques) {
                    printf("Número máximo de saques diário atingido. Operação não realizada!\n");
                }else if (saque > 0) {
                    numero_saque++;
                    saldo -= saque;
                    // char buffer[100];
                    // snprintf(buffer, sizeof(buffer), "Saque:\t\tR$ %.2f\n", saque);
                    // strcat(extrato, buffer);
                    strcpy(operacoes[i].operacao,"Saque: ");
                    operacoes[i].valor = saque;
                    i++ ;
                } else {
                printf("O valor é inválido. Operação não realizada!\n");
                } break;

            case 'e':
                int j = 0;
                printf("%i", i);
                printf("\n================ EXTRATO ================\n");
                if (i == 0) {
                    printf("Não foram realizadas movimentações.\n");
                } else {
                    for (j=0;j<i;j++)
                    {
                        printf("%-11s\t\t",operacoes[j].operacao);
                        printf("R$ %.2f\n",operacoes[j].valor);
                    }

                }
                printf("Saldo:\t\t\tR$ %.2f\n", saldo);
                printf("==========================================\n");
                break;

            case 'q':
            return 0;
            break;


            case 'a':
            printf("\n\033[1mDepositar\033[0m: O depósito deve ser feito com um valor decimal positivo, não serão aceitos valores negativos.\n\n");

            printf("\033[1mSacar\033[0m: Para sua segurança, nosso banco impõe um limite de R$500,00 por saque e no máximo 3 saques por dia.\n");
            printf("Para poder efetuar o saque, o valor de saque desejado de saque deverá ser positivo e o seu saldo não poderá ficar negativo\n\n");

            printf("\033[1mExtrato\033[0m: Mostra todas as operações realizadas pelo usuário e o saldo atual\n");
            break;

            default:
            printf("\033[1mOperação inválida\033[0m, por favor selecione novamente a operação desejada.\n");
        } 
        
    }
    return 1;
}
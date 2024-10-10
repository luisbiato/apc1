#include <stdio.h>
#include <string.h>

struct extrato
{
    char operacao[10];
    float valor;
};
typedef struct extrato extrato;


int main() {
    char menu[] = "\n\tBANCO APC1\n\nMENU(Escolha a opção desejada):\n[d] = Depositar\n[s] = Sacar\n[e] = Extrato\n[q] = Sair\n[a] = Ajuda\n";
    float saldo = 0.0f;
    int limite = 500;
    int limite_saques = 3;
    char extrato[1000] = "";
    int numero_saque = 0;
    char operacao = '\n';
    
    while (1) {
        fflush(stdin);
        printf("%s", menu);
        scanf("%c",&operacao);
        getchar();
        fflush(stdin);

        
        if (operacao == 'd') {
            float deposito = 0.0f;
            printf("Valor a ser depositado: ");
            scanf("%f", &deposito);
            printf("%f\n",deposito);
            getchar();
            fflush(stdin);
            
            if (deposito <= 0) {
                printf("O valor é invalido. Operação não realizada!\n");
                getchar();
                fflush(stdin);
            }
            else if (deposito > 0) {
                saldo += deposito;
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Depósito:\tR$ %.2f\n", deposito);
                strcat(extrato, buffer);
                
            } 
        } 
        
        else if (operacao == 's') {
            float saque = -1.0f;
            printf("Valor a ser sacado: ");
            scanf("%f", &saque);
            getchar();
            fflush(stdin);
            
            if (saque > saldo) {
                printf("Saldo insuficiente. Operação não realizada!\n");
                getchar();
                fflush(stdin);
            } 
            else if (saque > limite) {
                printf("Valor máximo de saque é de R$500,00. Operação não realizada!\n");
                getchar();
                fflush(stdin);
            } 
            else if (numero_saque >= limite_saques) {
                printf("Número máximo de saques diário atingido. Operação não realizada!\n");
                getchar();
                fflush(stdin);
            } 

            else if (saque > 0) {
                numero_saque++;
                saldo -= saque;
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Saque:\t\tR$ %.2f\n", saque);
                strcat(extrato, buffer);
            } else {
                printf("O valor é inválido. Operação não realizada!\n");
                fflush(stdin);
            }
        } 
        
        else if (operacao == 'e') {
            fflush(stdin);
            printf("\n================ EXTRATO ================\n");
            if (strlen(extrato) == 0) {
                printf("Não foram realizadas movimentações.\n");
            } else {
                printf("%s", extrato);
            }
            printf("Saldo:\t\tR$ %.2f\n", saldo);
            printf("==========================================\n");
        } 
        
        else if (operacao == 'q') {
            printf("Volte Sempre\n");
            break;
        } 

        else if (operacao == 'a'){
            printf("\n\033[1mDepositar\033[0m: O depósito deve ser feito com um valor decimal positivo, não serão aceitos valores negativos.\n\n");

            printf("\033[1mSacar\033[0m: Para sua segurança, nosso banco impõe um limite de R$500,00 por saque e no máximo 3 saques por dia.\n");
            printf("Para poder efetuar o saque, o valor de saque desejado de saque deverá ser positivo e o seu saldo não poderá ficar negativo\n\n");

            printf("\033[1mExtrato\033[0m: Mostra todas as operações realizadas pelo usuário e o saldo atual\n");
        }
        
        else {
            printf("Operação inválida, por favor selecione novamente a operação desejada.\n");
        }
    }
    
    return 1;
}

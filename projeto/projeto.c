#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct extrato
{
    char operacao[10];
    float valor;
} extrato;

typedef struct conta
{
    float saldo;
    int limite;
    int limite_saques;
    extrato operacoes[20];
    int numero_saque;
    int i; // índice para operações
} Conta;

int main() {
    // Correção de acentuação
    setlocale(LC_ALL, "Portuguese");

    // Criando uma conta e inicializando os valores
    Conta minhaConta = {0.0f, 500, 3, {{""}}, 0, 0};

    // Criação do menu
    char menu[] = "\n\tBANCO APC1\n\nMENU(Escolha a opção desejada):\n[d] = Depositar\n[s] = Sacar\n[e] = Extrato\n[q] = Sair\n[a] = Ajuda\n";

    char operacao = '\0';

    while (1) {
        // Entrada de dados com escolha do menu

        printf("%s", menu);
        scanf("%c", &operacao);
        while (getchar() != '\n') {getchar();} // Limpa o buffer
        
        switch (operacao) {
            case 'd': {
                system("clear");
                float deposito = 0.0f;
                printf("Valor a ser depositado: ");
                scanf("%f", &deposito);
                while (getchar() != '\n') {getchar();}  // Limpa o buffer
                        
                if (deposito <= 0) {
                    printf("O valor é inválido. Operação não realizada!\n");
                } else if (deposito > 999999) {
                    printf("O valor é muito alto. Vá na sua agência!\n");
                } else {
                    minhaConta.saldo += deposito;
                    strcpy(minhaConta.operacoes[minhaConta.i].operacao, "Depósito");
                    minhaConta.operacoes[minhaConta.i].valor = deposito;
                    printf("\033[1mOperação realizada com sucesso!\033[0m\n");
                    minhaConta.i++;
                }
                break;
            }
            
            case 's': {
                system("clear");
                float saque = 0.0f;
                printf("Valor a ser sacado: ");
                scanf("%f", &saque);
                while (getchar() != '\n') {getchar();} // Limpa o buffer
                
                if (saque > minhaConta.saldo) {
                    printf("Saldo insuficiente. Operação não realizada!\n");
                } else if (saque > minhaConta.limite) {
                    printf("Valor máximo de saque é de R$500,00. Operação não realizada!\n");
                } else if (minhaConta.numero_saque >= minhaConta.limite_saques) {
                    printf("Número máximo de saques diário atingido. Operação não realizada!\n");
                } else if (saque > 0) {
                    minhaConta.numero_saque++;
                    minhaConta.saldo -= saque;
                    strcpy(minhaConta.operacoes[minhaConta.i].operacao, "Saque");
                    minhaConta.operacoes[minhaConta.i].valor = saque;
                    printf("\033[1mOperação realizada com sucesso!\033[0m\n");
                    minhaConta.i++;
                } else {
                    printf("O valor é inválido. Operação não realizada!\n");
                }
                break;
            }

            case 'e': {
                system("clear");
                printf("\n================ EXTRATO ================\n");
                if (minhaConta.i == 0) {
                    printf("Não foram realizadas movimentações.\n");
                } else {
                    for (int j = 0; j < minhaConta.i; j++) {
                        printf("%-11s\t\t", minhaConta.operacoes[j].operacao);
                        printf("R$ %.2f\n", minhaConta.operacoes[j].valor);
                    }
                }
                printf("Saldo:\t\t\tR$ %.2f\n", minhaConta.saldo);
                printf("==========================================\n");
                break;
            }

            case 'q':
                return 0;

            case 'a':
                printf("\n\033[1mDepositar\033[0m: O depósito deve ser feito com um valor decimal positivo, não serão aceitos valores negativos.\n\n");
                printf("\033[1mSacar\033[0m: Para sua segurança, nosso banco impõe um limite de R$500,00 por saque e no máximo 3 saques por dia.\n");
                printf("Para poder efetuar o saque, o valor de saque desejado deverá ser positivo e o seu saldo não poderá ficar negativo.\n\n");
                printf("\033[1mExtrato\033[0m: Mostra todas as operações realizadas pelo usuário e o saldo atual.\n");
                break;

            default:
                printf("\033[1mOperação inválida\033[0m, por favor selecione novamente a operação desejada.\n");
        }
        printf("\nTecle \033[1mENTER\033[0m para voltar ao menu principal.");
        while (getchar() != '\n') {getchar();} // Limpa o buffer
        system("clear");
        
        
    }
    return 1;
}

#include <stdio.h>
#include <string.h>

int main() {
    char menu[] = "\n[d] = Depositar\n[s] = Sacar\n[e] = Extrato\n[q] = Sair\n\n";
    float saldo = 0.0;
    int limite = 500;
    int limite_saques = 3;
    char extrato[1000] = "";
    int numero_saque = 0;
    char operacao;
    
    while (1) {
        printf("%s", menu);
        scanf(" %c", &operacao);
        
        if (operacao == 'd') {
            float deposito;
            printf("Valor a ser depositado: ");
            scanf("%f", &deposito);
            
            if (deposito > 0) {
                saldo += deposito;
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Depósito: R$ %.2f\n", deposito);
                strcat(extrato, buffer);
            } else {
                printf("O valor é invalido. Operação não realizada!\n");
            }
        } 
        
        else if (operacao == 's') {
            int saque;
            printf("Valor a ser sacado: ");
            scanf("%d", &saque);
            
            if (saque > saldo) {
                printf("Saldo insuficiente. Operação não realizada!\n");
            } 
            else if (saque > limite) {
                printf("Valor máximo de saque é de R$500,00. Operação não realizada!\n");
            } 
            else if (numero_saque >= limite_saques) {
                printf("Número máximo de saques diário atingido. Operação não realizada!\n");
            } 
            else if (saque > 0) {
                numero_saque++;
                saldo -= saque;
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "Saque: R$ %d\n", saque);
                strcat(extrato, buffer);
            } else {
                printf("O valor é inválido. Operação não realizada!\n");
            }
        } 
        
        else if (operacao == 'e') {
            printf("\n================ EXTRATO ================\n");
            if (strlen(extrato) == 0) {
                printf("Não foram realizadas movimentações.\n");
            } else {
                printf("%s", extrato);
            }
            printf("Saldo: R$ %.2f\n", saldo);
            printf("==========================================\n");
        } 
        
        else if (operacao == 'q') {
            break;
        } 
        
        else {
            printf("Operação inválida, por favor selecione novamente a operação desejada.\n");
        }
    }
    
    return 1;
}

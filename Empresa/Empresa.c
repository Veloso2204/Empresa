#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[60];
    char dataNascimento[15];
    float vencimento;
} funcionario;

void SalCimaMedia(funcionario funcionarios[], int numFuncionarios, float media) {
    printf("Funcionários com vencimento acima da média:\n");

    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].vencimento > media) {
            printf("Nome: %s, Vencimento: %.2f\n", funcionarios[i].nome, funcionarios[i].vencimento);
        }
    }
}

int compararPorNome(const void* a, const void* b) {
    return strcmp(((funcionario*)a)->nome, ((funcionario*)b)->nome);
}

void ListOrdem(funcionario funcionarios[], int numFuncionarios) {
    printf("Listagem em ordem alfabética:\n");

    qsort(funcionarios, numFuncionarios, sizeof(funcionario), compararPorNome);

    for (int i = 0; i < numFuncionarios; i++) {
        printf("Nome: %s, Data de Nascimento: %s\n", funcionarios[i].nome, funcionarios[i].dataNascimento);
    }
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    int numFuncionarios = 5;
    float somaVencimentos = 0;

    funcionario funcionarios[5];

    for (int i = 0; i < numFuncionarios; i++) {
        printf("Digite o nome do %dº Funcionario: \n", i + 1);
        getchar();
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);

        printf("Digite a data de nascimento do %dº Funcionario: (__/__/____) \n", i + 1);
        scanf("%s", funcionarios[i].dataNascimento);

        printf("Digite o vencimento do %dº Funcionario: \n", i + 1);
        scanf("%f", &funcionarios[i].vencimento);

        somaVencimentos += funcionarios[i].vencimento;
    }

    float mediaVencimentos = somaVencimentos / numFuncionarios;

    SalCimaMedia(funcionarios, numFuncionarios, mediaVencimentos);
    ListOrdem(funcionarios, numFuncionarios);

    return 0;
}

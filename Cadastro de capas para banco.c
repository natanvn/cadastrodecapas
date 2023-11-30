#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPAS 100
#define NOME_ARQUIVO "capas_banco.txt"

struct CapaBanco {
    char modeloCarro[100];
    char cor[50];
    float preco;
    int quantidade;
};

void cadastrarCapaBanco(struct CapaBanco *capas, int *numCapas) {
    if (*numCapas >= MAX_CAPAS) {
        printf("Limite de capas de banco atingido.\n");
        return;
    }

    struct CapaBanco novaCapa;

    printf("Digite o modelo do carro: ");
    fgets(novaCapa.modeloCarro, sizeof(novaCapa.modeloCarro), stdin);

    printf("Digite a cor da capa de banco: ");
    fgets(novaCapa.cor, sizeof(novaCapa.cor), stdin);

    printf("Digite o preço da capa de banco: ");
    scanf("%f", &novaCapa.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novaCapa.quantidade);

    getchar();

    novaCapa.modeloCarro[strcspn(novaCapa.modeloCarro, "\n")] = '\0';
    novaCapa.cor[strcspn(novaCapa.cor, "\n")] = '\0';

    capas[*numCapas] = novaCapa;
    (*numCapas)++;

    printf("Cadastro de capa de banco realizado com sucesso!\n");
}

void visualizarCapasBanco(const struct CapaBanco *capas, int numCapas) {
    printf("=== Capas de Banco Cadastradas ===\n");

    for (int i = 0; i < numCapas; i++) {
        printf("Modelo do Carro: %s\n", capas[i].modeloCarro);
        printf("Cor: %s\n", capas[i].cor);
        printf("Preço: %.2f\n", capas[i].preco);
        printf("Quantidade em estoque: %d\n\n", capas[i].quantidade);
    }
}

void salvarEmArquivo(const struct CapaBanco *capas, int numCapas) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar ou abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "=== Capas de Banco Cadastradas ===\n");

    for (int i = 0; i < numCapas; i++) {
        fprintf(arquivo, "Modelo do Carro: %s\n", capas[i].modeloCarro);
        fprintf(arquivo, "Cor: %s\n", capas[i].cor);
        fprintf(arquivo, "Preço: %.2f\n", capas[i].preco);
        fprintf(arquivo, "Quantidade em estoque: %d\n\n", capas[i].quantidade);
    }

    fclose(arquivo);
    printf("Dados salvos em %s.\n", NOME_ARQUIVO);
}

int main() {
    struct CapaBanco capas[MAX_CAPAS];
    int numCapas = 0;
    char opcao;

    do {
        printf(" -- System AutoXtreme --\n\n");
        printf("Bem-vindo ao sistema de cadastro AutoXtreme!\n\n");
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar nova capa de banco\n");
        printf("2 - Visualizar capas de banco cadastradas\n");
        printf("3 - Salvar em arquivo\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);
        getchar();

        switch (opcao) {
            case '1':
                cadastrarCapaBanco(capas, &numCapas);
                break;
            case '2':
                visualizarCapasBanco(capas, numCapas);
                break;
            case '3':
                salvarEmArquivo(capas, numCapas);
                break;
            case '4':
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}

//Desenvolvido por: Arthur Carvalho; Guilherme Borges; Pablo Henrique; Breno Borges.

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
} contatos;

void pesquisarcontato(contatos *contato, int numContatos);
void editarcontato(contatos *contato, int numContatos);
void exibircontato(contatos *contato, int numContatos);

int main() {
    contatos contato[100];
    int numContatos = 0;
    int finalizador = 0, IC;

    while(finalizador != 1) {
        int opcao = 0;
        printf("O que deseja fazer:\n\n");
        printf("1. Adicionar Contato\n");
        printf("2. Pesquisar Contato\n");
        printf("3. Exibir Contatos\n");
        printf("4. Editar Contato\n");
        printf("5. Sair\n\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                do {
                    if (numContatos < 100) {
                        printf("Digite seu nome: ");
                        scanf(" %[^\n]", contato[numContatos].nome);

                        printf("Digite seu telefone (somente números): ");
                        scanf(" %[^\n]", contato[numContatos].telefone);

                        printf("Digite seu email: ");
                        scanf(" %[^\n]", contato[numContatos].email);

                        numContatos++; 
                        printf("\n\nDeseja adicionar mais algum contato?\n\nSim = 1\n\nNão = 2: ");
                        scanf("%d", &IC);
                    } else {
                        printf("\n\nLimite de contatos atingido!\n\n");
                        IC = 2; // Sair do loop
                    }
                } while(IC == 1);
                break;

            case 2:
                pesquisarcontato(contato, numContatos);
                break;

            case 3:
                exibircontato(contato, numContatos);
                break;

            case 4:
                editarcontato(contato, numContatos);
                break;

            case 5:
                finalizador = 1;
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
    return 0;
}

// Função para pesquisar um contato
void pesquisarcontato(contatos *contato, int numContatos) {
    char nome[50];
    printf("\nDigite o nome do contato a ser pesquisado: ");
    scanf(" %[^\n]", nome);

for (int i = 0; i < numContatos; i++) {
        if (strcmp(contato[i].nome, nome) == 0) {
            printf("Nome: %s\n", contato[i].nome);
            printf("Telefone: %s\n", contato[i].telefone);
            printf("Email: %s\n", contato[i].email);
            return;
        }
    }

    printf("\n\nContato não encontrado!\n");
}

// Função para editar um contato
void editarcontato(contatos *contato, int numContatos) {
    char nome[50];
    printf("Digite o nome do contato a ser editado: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < numContatos; i++) {
        if (strcmp(contato[i].nome, nome) == 0) {
            printf("Digite o novo telefone: ");
            scanf(" %[^\n]", contato[i].telefone);
            printf("\nDigite o novo email: ");
            scanf(" %[^\n]", contato[i].email);
            printf("\nContato editado com sucesso!\n");
            return;
        }
    }

    printf("\nContato não encontrado para edição!\n");
}

// Função para exibir todos os contatos
void exibircontato(contatos *contato, int numContatos) {
    if (numContatos == 0) {
        printf("\nNenhum contato cadastrado!\n");
        return;
    }
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s\n", contato[i].nome);
        printf("Telefone: %s\n", contato[i].telefone);
        printf("Email: %s\n", contato[i].email);
        printf("------------------------\n");
    }
}

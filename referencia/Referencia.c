#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_QUARTOS 50
#define MAX_TAM_NOME 50


typedef struct {
    char nome[MAX_TAM_NOME];
    char cpf[12];
    char senha[20];
} Usuario;


typedef struct {
    int numero;
    int disponivel;
} Quarto;


void cadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    printf("Cadastro de novo usuario:\n");
    if (*numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]s", usuarios[*numUsuarios].nome);
    printf("CPF: ");
    scanf("%s", usuarios[*numUsuarios].cpf);
    printf("Senha: ");
    scanf("%s", usuarios[*numUsuarios].senha);

    (*numUsuarios)++;
    printf("Usuario cadastrado com sucesso!\n");
}


int fazerLogin(Usuario usuarios[], int numUsuarios) {
    char cpf[12];
    char senha[20];
    printf("Login:\n");
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Senha: ");
    scanf("%s", senha);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login realizado com sucesso!\n");
            return i;
        }
    }

    printf("CPF ou senha incorretos. Tente novamente.\n");
    return -1;
}


void reservarQuarto(Usuario usuarios[], Quarto quartos[], int usuarioIndex, int numQuartos) {
    int numQuarto;
    printf("Quartos disponiveis:\n");
    int quartosDisponiveis = 0;
    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].disponivel) {
            printf("Quarto %d\n", quartos[i].numero);
            quartosDisponiveis++;
        }
    }

    printf("Total de quartos disponiveis: %d\n", quartosDisponiveis);

    if (quartosDisponiveis == 0) {
        printf("Nao ha quartos disponiveis para reserva.\n");
        return;
    }

    printf("Digite o numero do quarto que deseja reservar: ");
    scanf("%d", &numQuarto);

    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].numero == numQuarto) {
            if (quartos[i].disponivel) {
                quartos[i].disponivel = 0;
                printf("Quarto %d reservado com sucesso para %s!\n", numQuarto, usuarios[usuarioIndex].nome);
                return;
            } else {
                printf("Quarto nao disponivel. Escolha outro quarto.\n");
                return;
            }
        }
    }

    printf("Numero de quarto invalido.\n");
}






void removerReserva(Quarto quartos[], int numQuartos) {
    int numQuarto;
    printf("Digite o numero do quarto que deseja liberar: ");
    scanf("%d", &numQuarto);

    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].numero == numQuarto) {
            quartos[i].disponivel = 1;
            printf("Reserva do quarto %d removida com sucesso!\n", numQuarto);
            return;
        }
    }

    printf("Numero de quarto invalido.\n");
}

int main() {
    Usuario usuarios[MAX_USUARIOS];
    Quarto quartos[MAX_QUARTOS];

    int numUsuarios = 0;
    int numQuartos = 0;
    int usuarioLogado = -1;

    int opcao;


    for (int i = 0; i < 5; i++) {
        quartos[numQuartos].numero = i + 1;
        quartos[numQuartos].disponivel = 1;
        numQuartos++;
    }

    do {
        printf("\n### Menu ###\n");
        printf("1. Cadastrar novo usuario\n");
        printf("2. Login\n");
        printf("3. Reservar quarto\n");
        printf("4. Remover reserva de quarto\n");
        printf("5. Verificar quartos disponiveis\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case 2:
                usuarioLogado = fazerLogin(usuarios, numUsuarios);
                break;
            case 3:
                if (usuarioLogado != -1) {
                    reservarQuarto(usuarios, quartos, usuarioLogado, numQuartos);
                } else {
                    printf("Nenhum usuario logado. Por favor, faca o login primeiro.\n");
                }
                break;
            case 4:
                if (usuarioLogado != -1) {
                    removerReserva(quartos, numQuartos);
                } else {
                    printf("Nenhum usuario logado. Por favor, faca o login primeiro.\n");
                }
                break;
            case 5:
                printf("Quartos disponiveis:\n");
                int quartosDisponiveis = 0;
                for (int i = 0; i < numQuartos; i++) {
                    if (quartos[i].disponivel) {
                        printf("Quarto %d\n", quartos[i].numero);
                        quartosDisponiveis++;
                    }
                }
                printf("Total de quartos disponiveis: %d\n", quartosDisponiveis);
                break;
            case 6:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
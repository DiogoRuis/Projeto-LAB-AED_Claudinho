#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"


//Cadastrar novos usuarios
void cadastra(FILE *arq, Usuario cliente[], int *numUsuario)
{
    printf("\n\nCadastrar Usuario:\n");

    printf("Nome: ");
    scanf("%s", cliente[*numUsuario].nome);

    printf("\nCPF: ");
    scanf("%s", cliente[*numUsuario].cpf);

    printf("\nSenha: ");
    scanf("%s", cliente[*numUsuario].senha);

    printf("\n\nUsuario cadastrado com sucesso!\n");

    arq = fopen("cliente.txt", "a");
    if(arq == NULL) //Verifica se abriu o arquivo corretamente.
    {
        printf("\n\nErro ao armazenar os dados!");
        exit(-1);
    }

    fwrite(cliente, sizeof(Usuario), 1, arq);

    fclose(arq);
}


//Verificar Login de usuarios ja cadastrados
int login(FILE *arq, Usuario cliente[])
{
    char cpf[12];
    char senha[8];
    int n = 0, i;
    
    printf("\n\n---     FAZER LOGIN     ---\n");
    printf("CPF: ");
    scanf("%s", cpf);
    
    printf("\nSenha: ");
    scanf("%s",senha);

    arq = fopen("cliente.txt", "r");
    if(arq == NULL) //Verifica se abriu o arquivo corretamente
    {
        printf("\n\nErro ao abrir o arquivo!");
        exit(-1);
    }

    //recebe os dados do arquivo de login
    n = fread(cliente, sizeof(Usuario), 10, arq);

    //percorre todo os dados para verificar se os dados de login estao corretos.
    for(i = 0; i < n; i++)
    {
        if(strcmp(cliente[i].cpf, cpf) == 0 && strcmp(cliente[i].senha, senha) == 0)
        {
            printf("\n\nLogin realizado com sucesso!");
            return 1;    
        }        
    }
    
    printf("CPF ou SENHA incorretos. Tente novamente.\n");
    fclose(arq);

    return -1;
}


//Funcao para a reserva de quartos.
void reservaQuarto(FILE *arqQuarto)
{
    int i, n;
    int quartoReservar;

    arqQuarto = fopen("quartos.txt", "r");
    if(arqQuarto == NULL)//Verifica se o arquivo ja existe.
    {
        fclose(arqQuarto);

        arqQuarto = fopen("quartos.txt", "w");
        if(arqQuarto == NULL) //Verifica se o arquivo abriu corretamente.
        {
            printf("\nErro ao criar o arquivo dos quartos...\n");
            exit(-1);
        }

        //Inicializa o arquivo com todos os quartos disponíveis.
        for(i = 0; i < 5; i++)
        {
            quartos[i].numero = i + 1;
            quartos[i].disponivel = 1;
            fwrite(&quartos[i], sizeof(Quarto), 1, arqQuarto);
            
        }
        fclose(arqQuarto);
    
    }

    arqQuarto = fopen("quartos.txt", "r");
    if(arqQuarto == NULL) //Verifica se o arquivo abriu corretamente.
    {
        printf("\nErro ao abrir o arquivo!");
        exit(-1);
    }

    //Recebe os dados dos quartos.
    n = fread(quartos, sizeof(Quarto), 10, arqQuarto);

    //Imprime os quartos disponíveis.
    for(i = 0; i < n; i++)
    {
        if(quartos[i].disponivel == 1){
            printf("\nQuarto numero: %d\n", quartos[i].numero);
            printf("Quarto disponivel: %d\n", quartos[i].disponivel);
        }
    }
    fclose(arqQuarto);

    printf("Digite o numero do quarto que deseja reservar: \n");
    scanf("%d", &quartoReservar);

    arqQuarto = fopen("quartos.txt", "r+");
    if(arqQuarto == NULL) //Verifica se o arquivo abriu corretamente.
    {
        printf("\nErro ao abrir o arquivo!");
        exit(-1);
    }

    //Percorre os quartos para fazer a reserva.
    for(i = 0; i < 5; i++)
    {
        if(quartos[i].numero == quartoReservar)
        {
            if(quartos[i].disponivel == 1)
            {
                quartos[i].numero = i + 1;
                quartos[i].disponivel = 0;
                printf("\nQuarto %d reservado com sucesso!", quartoReservar);
                fseek(arqQuarto, i * 4, SEEK_SET);
                fwrite(&quartos[i], sizeof(Quarto), 1, arqQuarto);
            }
            else
            {
                printf("\nQuarto nao disponivel. Escolha outro!\n");
            }
        }
    }
    fclose(arqQuarto);
}

/*
    Sistema para reserva de quarto de hotéis.

    Integrantes: José Ulisses, Diogo Ruis, Cauan Reis, Mateus militão;

    Sistema de Arquivo feito por jose ulisses;
    Sistema do Menu feito por Diogo Ruis;

    GitHub: 

    Modificado em: 02/12/2023
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"

int main()
{
    FILE arq;
    FILE arqQuarto;

    int numUsuario = 0;    
    int opcao;
    int loginRealizado = -1;

    do
    {
        printf("\n\n---    LOGIN    ---\n\n");
        printf("[1] - Realizar Cadastro\n");
        printf("[2] - Realizar Login\n");
        printf("[3] - sair\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao)
        {
            case 1:
                cadastra(&arq, cliente, &numUsuario);
                break;

            case 2:
                loginRealizado = login(&arq, cliente);
                break;

            case 3:
            printf("\n\nsaindo do programa...\n\n");
                exit(-1);

            default:
                printf("\n\nopcao invalida!");
                break;
        }
    }while(loginRealizado != 1); //Repete enquanto o usuario não realizar o login.

    opcao = 0;

    printf("\n\n---    MENU    ---\n\n");
    printf("[1] - Reservar um  quarto\n");
    printf("[2] - Remover reserva de um quarto\n");
    printf("[3] - Verificar quartos disponiveis\n");
    printf("[4] - Sair\n");
    scanf("%d", &opcao);
    fflush(stdin);

    switch(opcao)
    {
        case 1:
            reservaQuarto(&arqQuarto);
            break;
    }
}

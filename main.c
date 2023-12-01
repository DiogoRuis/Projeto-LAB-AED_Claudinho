#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliares.h"


// Modificado em: 30/11/2023

/*
    ...
*/


int main()
{
    int op;

    do
    {
        printf("---     LOGIN       ---\n\n");
        printf("[1] - Registrar-se\n");
        printf("[2] - Efetuar Login\n");
        printf("[3] - Sair\n");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            Registra();
            break;

        case 2:
            login();
            op = 3;
            break;

        case 3:
            exit(-1);
            break;

        default:
            printf("\n\n---     opcao invalida!!    ---\n\n");
            break;
        }
    } while (op != 3);

    op = 0;

    do
    {
        // limpaTela();

        printf("\n\n---     MENU    ---\n\n");
        printf("[1] - Reservar um quarto\n");
        printf("[2] - Gerenciar quartos reservados\n");
        printf("[3] - Sair\n");
        scanf("\n%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            reserva();
            break;

        case 2:
            gerencia();
            break;

        case 3:
            exit(-1);
            break;

        default:
            printf("\n\nopcao invalida!");
            break;
        }
    } while (op != 3);
}

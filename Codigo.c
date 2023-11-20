#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Modificado em: 20/11/2023

/*
    Substituir todos os gets e scanf.(foi usado apenas para teste);
    Arrumar todos os warnings
*/


struct cliente
{
    char usuario[10];
    char senha[8];
};

struct cliente dados;
struct cliente aux;

struct dadosCliente
{
    char nome[20];
    char email[20];
    int telefone;
    char diaEntra[10];
    int periodo;
    int numQuarto;
} s;

void limpaTela()
{
    printf("\033c");
    printf("\033[H\033[J");
}

int Registra()
{
    FILE *arq;

    limpaTela();

    arq = fopen("Dados_login.txt", "w");
    if (arq == NULL)
    {
        printf("\n---    Falha ao inicializar o arquivo de Login     ---");
        exit(1);
    }

    printf("\nInforme o seu nome de usuario:\n");
    gets(dados.usuario);
    fflush(stdin);

    printf("\n\ninforme a sua senha:\n");
    gets(dados.senha);
    fflush(stdin);

    fwrite(&dados, sizeof(dados), 1, arq);

    fclose(arq);

    printf("Registro realizado com sucesso, pressione qualquer tecla para continuar...\n");
    getch();

    return 0;
}

void login()
{
    int sucesso = 0;
    int compUsu, compPass;
    FILE *arq;

    do
    {
        limpaTela();

        printf("Informe o seu nome de usuario:\n");
        gets(dados.usuario);
        fflush(stdin);

        printf("\n\ninforme a sua senha:\n");
        gets(dados.senha);
        fflush(stdin);

        arq = fopen("Dados_login.txt", "r");

        fread(&aux, sizeof(aux), 1, arq);

        //printf("\nusuario dados: %s", dados.usuario);
        //printf("\nusuario aux: %s", aux.usuario);

        //printf("\nsenha dados: %s", dados.senha);
        //printf("\nsenha aux: %s", aux.senha);

        // Verifica os dados de Login
        compUsu = strcmp(aux.usuario, dados.usuario);
        compPass = strcmp(aux.senha, dados.senha);

        if (compUsu == 0 && compPass == 0)
            {
                printf("\n\nLogin realizado com sucesso!\n\n");
                sucesso = 1;
            }
        else
            printf("\n\nUsuario ou senha invalidos!\n\n");

    }while(sucesso == 0);


        fclose(arq);
    }

    void reserva()
    {
        FILE *arq;

        limpaTela();

        printf("\nNome:\n");
        scanf("%s", &s.nome);
        //fflush(stdin);

        printf("\nE-mail:\n");
        scanf("%s", &s.email);
        //fflush(stdin);

        printf("\nNumero de telefone:\n");
        scanf("%d", &s.telefone);
        //fflush(stdin);

        printf("\nQual o dia ira entrar:\n");
        scanf("%s", &s.diaEntra);
        //fflush(stdin);

        printf("\nQuantos dias ira ficar:\n");
        scanf("%d", &s.periodo);
        //fflush(stdin);

        printf("\n\nEscolha um quarto a ser reservado:\n");
        scanf("%d", &s.numQuarto);
        //fflush(stdin);

        arq = fopen("dados_cliente.txt", "w");
        if (arq == NULL)
        {
            printf("\n\nErro ao armarzenar dados do usuario!!\n\n");
            exit(1);
        }

        fwrite(&s, sizeof(s), 1, arq);
        //fflush(stdin);
        fclose(arq);
    }

    void gerencia()
    {
        FILE *arq;        
        int op;

        limpaTela();

        arq = fopen("dados_cliente.txt", "r");
        if(arq == NULL)
        {
            printf("\n\nErro ao ler os dados do cliente!!\n\n");
            exit(1);
        }

        printf("\n\n---     Gerenciar quartos   ---\n\n");
        printf("[1] - Visualizar quartos reservados\n");
        scanf("\n%d", &op);

        switch (op)
        {
        case 1:
            printf("\nQuartos reservados no seu nome:\n\n");
            printf("\n----------------------------------------------------------------------------------------\n");
            printf("NOME");
            printf("\tE-MAIL");
            printf("\t\tTELEFONE");
            printf("\tDIA DE CHEGADA");
            printf("\t\tPERIODO");
            printf("\t\tQUARTO");
            printf("\n----------------------------------------------------------------------------------------\n");

            while(fread(&s, sizeof(s), 1, arq) == 1)
            {
                printf("%s\t %s\t %d\t %s\t\t %d\t\t %d\t", s.nome, s.email, s.telefone,
                       s.diaEntra, s.periodo, s.numQuarto);
            }
            fclose(arq);
        }
    }

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
        }
        while(op != 3);

        op = 0;

        do
        {
            limpaTela();
            
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
        }while(op != 3);
    }


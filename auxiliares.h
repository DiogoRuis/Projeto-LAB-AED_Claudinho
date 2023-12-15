#ifndef AUXILIARES_H
#define AUXILIARES_H

//struct para os dados do Usuario
typedef struct{
    char nome[30];
    char cpf[12];
    char senha[8];
}Usuario;

Usuario cliente[5];

//Struct para os Quartos
typedef struct{
    short int numero;
    short int disponivel;
}Quarto;

Quarto quartos[5];

//FUNÇÕES
void cadastra(FILE *arq, Usuario cliente[], int *numUsuario);
int login(FILE *arq, Usuario cliente[]);
void reservaQuarto(FILE *arqQuarto);
void removeReserva(FILE *arqQuarto);
void verificaQuartosDisponiveis(FILE *arqQuarto);

#endif

#ifndef AUXILIARES_H
#define AUXILIARES_H

struct cliente
{
    char usuario[10];
    int senha;
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

void limpaTela();
int Registra();
void login();
void reserva();
void gerencia();

#endif

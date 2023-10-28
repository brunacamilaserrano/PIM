#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

struct st_Usuario{
    char nome[255];
    char senha[255];
    char cpf[255];
    int perfil;
};

struct st_Reserva{
    char cpf_hospede[255];
    int cki;
    int cko;
    char hotel[255];
    char tipo_quarto[255];
    int numero_quarto;
    int id_reserva;
    char status[255];
};

struct st_Quarto{
    int id_dia;
    char hotel[255];
    char tipo_quarto[255];
    int numero_quarto;
    float tarifa;
    char disponivel[30];
};

struct st_Consumo{
    int id_consumo;
    int id_reserva;
    char item[255];
    float valor;
};

int count_id_reserva;
int count_id_usuario;
int count_id_consumo;
char cpfLogado[255];

typedef struct st_Usuario st_Usuario;
typedef struct st_Reserva st_Reserva;
typedef struct st_Quarto st_Quarto;
typedef struct st_Consumo st_Consumo;

st_Usuario vetUsuarios[500];
st_Reserva vetReservas[6480];

st_Quarto vetRJSTD1[361];
st_Quarto vetRJSTD2[361];

st_Quarto vetRJLX1[361];
st_Quarto vetRJLX2[361];

st_Quarto vetRESTD1[361];
st_Quarto vetRESTD2[361];

st_Quarto vetRELX1[361];
st_Quarto vetRELX2[361];

st_Consumo vetConsumo[10000];

void iniciaQuartos();

void relatorioReceitas();

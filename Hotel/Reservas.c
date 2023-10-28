#include "globais.h"
#include "cadastroUsuarios.h"
#include "Reservas.h"

int criarReserva(){

    char id_hotel[255];
    char tipo_quarto[255];
    int id_quarto;
    int cki;
    int cko;
    int user;
    int ret;


    //Valida Usuario
    user=buscaUsuario();

    if (user==-1){
        return -1;
    }

    printf("\n--> Escolha o Hotel. [RJ]-Rio de Janeiro | [RE]-Recife: ");
    scanf("%s", &id_hotel);
    fflush(stdin);

    printf("\n--> Escolha o tipo de Quarto. Standard | Luxo: ");
    scanf("%s", &tipo_quarto);
    fflush(stdin);

    printf("\n--> Escolha o numero do Quarto. 1 | 2: ");
    scanf("%d", &id_quarto);
    fflush(stdin);

    printf("\n--> Escolha o dia do Check-in. (1 a 365): ");
    scanf("%d", &cki);
    fflush(stdin);

    printf("\n--> Escolha o dia do Check-out. (1 a 365): ");
    scanf("%d", &cko);
    fflush(stdin);

    ret=verificaDisponibilidade(cki, cko, id_hotel, tipo_quarto, id_quarto);

    if (ret==0){
    strcpy(vetReservas[count_id_reserva].hotel,id_hotel);

    strcpy(vetReservas[count_id_reserva].tipo_quarto,tipo_quarto);

    strcpy(vetReservas[count_id_reserva].cpf_hospede,vetUsuarios[user].cpf);

    strcpy(vetReservas[count_id_reserva].status,"Pendente");

    vetReservas[count_id_reserva].numero_quarto=id_quarto;

    vetReservas[count_id_reserva].cki=cki;

    vetReservas[count_id_reserva].cko=cko;

    vetReservas[count_id_reserva].id_reserva=count_id_reserva;

    count_id_reserva++;

    printf("\n\n----------Reserva realizada com sucesso!----------\n\n");

    }else{
    printf ("\n\n----------Realize uma nova reserva----------\n\n");
    }

    system("pause");

    return 0;
}

void visualizarReservas(){

int i=0;

system("cls");

for(i=0;i<count_id_reserva;i++){
printf("----------------------------------------");
printf("\nID Reserva: %d",vetReservas[i].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[i].cpf_hospede);
printf("\nHotel: %s",vetReservas[i].hotel);
printf("\nTipo do Quarto: %s",vetReservas[i].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[i].numero_quarto);
printf("\nCheck-in: %d",vetReservas[i].cki);
printf("\nCheck-out: %d",vetReservas[i].cko);
printf("\nStatus Pagamento: %s",vetReservas[i].status);
printf("\n----------------------------------------\n\n");
}
system("pause");
}

void visualizarReservasH(){

int i=0;

system("cls");

for(i=0;i<count_id_reserva;i++){
if(strcmp(vetReservas[i].cpf_hospede,cpfLogado)==0){
printf("----------------------------------------");
printf("\nID Reserva: %d",vetReservas[i].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[i].cpf_hospede);
printf("\nHotel: %s",vetReservas[i].hotel);
printf("\nTipo do Quarto: %s",vetReservas[i].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[i].numero_quarto);
printf("\nCheck-in: %d",vetReservas[i].cki);
printf("\nCheck-out: %d",vetReservas[i].cko);
printf("\nStatus Pagamento: %s",vetReservas[i].status);
printf("\n----------------------------------------\n\n");
}}
system("pause");
}

void modificarReserva(int idReserva){

if(strcmp(vetReservas[idReserva].cpf_hospede, cpfLogado)==0){
int confirmacao;

printf("\n\n----------Reserva Atual----------");
printf("\nID Reserva: %d",vetReservas[idReserva].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[idReserva].cpf_hospede);
printf("\nHotel: %s",vetReservas[idReserva].hotel);
printf("\nTipo do Quarto: %s",vetReservas[idReserva].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[idReserva].numero_quarto);
printf("\nCheck-in: %d",vetReservas[idReserva].cki);
printf("\nCheck-out: %d",vetReservas[idReserva].cko);
printf("\nStatus Pagamento: %s",vetReservas[idReserva].status);
printf("\n---------------------------------\n\n");


    printf("\n--> Escolha o Hotel. [RJ]-Rio de Janeiro | [RE]-Recife: ");
    scanf("%s", &vetReservas[idReserva].hotel);
    fflush(stdin);

    printf("\n--> Escolha o tipo de Quarto. Standard | Luxo: ");
    scanf("%s", &vetReservas[idReserva].tipo_quarto);
    fflush(stdin);

    printf("\n--> Escolha o numero do Quarto. 1 | 2: ");
    scanf("%d", &vetReservas[idReserva].numero_quarto);
    fflush(stdin);

    printf("\n--> Escolha o dia do Check-in. (1 a 365): ");
    scanf("%d", &vetReservas[idReserva].cki);
    fflush(stdin);

    printf("\n--> Escolha o dia do Check-out. (1 a 365): ");
    scanf("%d", &vetReservas[idReserva].cko);
    fflush(stdin);

    printf("\n\n----------Reserva Alterada----------\n\n");
    system("pause");

    }else{
    printf("\n\n----------Esta Reserva não pertence a você.----------\n\n");
    system("pause");
}

}

void cancelarReserva(int idReserva){

if(strcmp(vetReservas[idReserva].cpf_hospede, cpfLogado)==0){
int confirmacao;

printf("\n\n----------Reserva----------------");
printf("\nID Reserva: %d",vetReservas[idReserva].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[idReserva].cpf_hospede);
printf("\nHotel: %s",vetReservas[idReserva].hotel);
printf("\nTipo do Quarto: %s",vetReservas[idReserva].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[idReserva].numero_quarto);
printf("\nCheck-in: %d",vetReservas[idReserva].cki);
printf("\nCheck-out: %d",vetReservas[idReserva].cko);
printf("\nStatus Pagamento: %s",vetReservas[idReserva].status);
printf("\n---------------------------------\n\n");

    printf("\n--> Confirmar Cancelamento. [1]-Sim | [2]-Não: ");
    scanf("%d", &confirmacao);
    fflush(stdin);

    if(confirmacao==1){
        printf("\n\n----------Reserva Cancelada----------\n\n");

        strcpy(vetReservas[idReserva].status, "Cancelada");

        system("pause");
    }else{

    printf("\n\n----------Cancelamento não realizado----------\n\n");
    system("pause");

    }
}else{
    printf("\n\n----------Esta Reserva não pertence a você.----------\n\n");
    system("pause");
}

}

void listarQuartos(){

int i=0;
char hotel[255];
int numero_quarto;
char tipo_quarto[255];

    printf("\n--> Escolha o Hotel. [RJ]-Rio de Janeiro | [RE]-Recife: ");
    scanf("%s", &hotel);
    fflush(stdin);

    printf("\n--> Escolha o tipo de Quarto. Standard | Luxo: ");
    scanf("%s", &tipo_quarto);
    fflush(stdin);

    printf("\n--> Escolha o numero do Quarto. 1 | 2: ");
    scanf("%d", &numero_quarto);
    fflush(stdin);

if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==1){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRJSTD1[i].id_dia);
    printf("\nStatus: %s",vetRJSTD1[i].disponivel);
    printf("\nHotel: %s",vetRJSTD1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJSTD1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJSTD1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJSTD1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==2){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRJSTD2[i].id_dia);
    printf("\nStatus: %s",vetRJSTD2[i].disponivel);
    printf("\nHotel: %s",vetRJSTD2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJSTD2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJSTD2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJSTD2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==1){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRJLX1[i].id_dia);
    printf("\nStatus: %s",vetRJLX1[i].disponivel);
    printf("\nHotel: %s",vetRJLX1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJLX1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJLX1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJLX1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==2){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRJLX2[i].id_dia);
    printf("\nStatus: %s",vetRJLX2[i].disponivel);
    printf("\nHotel: %s",vetRJLX2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJLX2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJLX2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJLX2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==1){//
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRESTD1[i].id_dia);
    printf("\nStatus: %s",vetRESTD1[i].disponivel);
    printf("\nHotel: %s",vetRESTD1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRESTD1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRESTD1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRESTD1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==2){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRESTD2[i].id_dia);
    printf("\nStatus: %s",vetRESTD2[i].disponivel);
    printf("\nHotel: %s",vetRESTD2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRESTD2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRESTD2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRESTD2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==1){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRELX1[i].id_dia);
    printf("\nStatus: %s",vetRELX1[i].disponivel);
    printf("\nHotel: %s",vetRELX1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRELX1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRELX1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRELX1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==2){
for(i=0;i<361;i++){

    printf("----------------------------");
    printf("\nDia: %d",vetRELX2[i].id_dia);
    printf("\nStatus: %s",vetRELX2[i].disponivel);
    printf("\nHotel: %s",vetRELX2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRELX2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRELX2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRELX2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
}
}else{
printf("\n\n---------Tipo de quarto não encontrado---------\n\n");
}
    system("pause");
}

int verificaDisponibilidade(int cki, int cko, char hotel[255], char tipo_quarto[255], int numero_quarto){

int i=0;
int ret=0;

if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==1){
for(i=cki;i<cko;i++){

    if(strcmp(vetRJSTD1[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRJSTD1[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==2){
for(i=cki;i<cko;i++){

    if(strcmp(vetRJSTD2[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRJSTD2[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==1){
for(i=cki;i<cko;i++){

    if(strcmp(vetRJLX1[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRJLX1[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RJ")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==2){
for(i=cki;i<cko;i++){

    if(strcmp(vetRJLX2[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRJLX2[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==1){
for(i=cki;i<cko;i++){

    if(strcmp(vetRESTD1[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRESTD1[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Standard")==0 && numero_quarto==2){
for(i=cki;i<cko;i++){

    if(strcmp(vetRESTD2[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRESTD2[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==1){
for(i=cki;i<cko;i++){

    if(strcmp(vetRELX1[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRELX1[i].disponivel, "Ocupado");

    }
}

return ret;
}else if(strcmp(hotel,"RE")==0 && strcmp(tipo_quarto,"Luxo")==0 && numero_quarto==2){
for(i=cki;i<cko;i++){

    if(strcmp(vetRELX2[i].disponivel, "Ocupado")==0){

    printf("\-->Dia: %d Ocupado.",i);
    printf("\n");
    ret++;

    }
}

if(ret==0){

    for(i=cki;i<cko;i++){

        strcpy(vetRELX2[i].disponivel, "Ocupado");

    }
}

return ret;

}else{
    ret=-1;
printf("\n\n---------Tipo de quarto não encontrado---------\n\n");
}
    return ret;
    system("pause");
}

void relatorioOcupacao(){

int i=0;



for(i=0;i<361;i++){

    if(strcmp(vetRJSTD1[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRJSTD1[i].id_dia);
    printf("\nStatus: %s",vetRJSTD1[i].disponivel);
    printf("\nHotel: %s",vetRJSTD1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJSTD1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJSTD1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJSTD1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRJSTD2[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRJSTD2[i].id_dia);
    printf("\nStatus: %s",vetRJSTD2[i].disponivel);
    printf("\nHotel: %s",vetRJSTD2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJSTD2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJSTD2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJSTD2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRJLX1[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRJLX1[i].id_dia);
    printf("\nStatus: %s",vetRJLX1[i].disponivel);
    printf("\nHotel: %s",vetRJLX1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJLX1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJLX1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJLX1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRJLX2[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRJLX2[i].id_dia);
    printf("\nStatus: %s",vetRJLX2[i].disponivel);
    printf("\nHotel: %s",vetRJLX2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRJLX2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRJLX2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRJLX2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRESTD1[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRESTD1[i].id_dia);
    printf("\nStatus: %s",vetRESTD1[i].disponivel);
    printf("\nHotel: %s",vetRESTD1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRESTD1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRESTD1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRESTD1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRESTD2[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRESTD2[i].id_dia);
    printf("\nStatus: %s",vetRESTD2[i].disponivel);
    printf("\nHotel: %s",vetRESTD2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRESTD2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRESTD2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRESTD2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRELX1[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRELX1[i].id_dia);
    printf("\nStatus: %s",vetRELX1[i].disponivel);
    printf("\nHotel: %s",vetRELX1[i].hotel);
    printf("\nNumero do Quarto: %d",vetRELX1[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRELX1[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRELX1[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}

for(i=0;i<361;i++){
    if(strcmp(vetRELX2[i].disponivel, "Ocupado")==0){
    printf("----------------------------");
    printf("\nDia: %d",vetRELX2[i].id_dia);
    printf("\nStatus: %s",vetRELX2[i].disponivel);
    printf("\nHotel: %s",vetRELX2[i].hotel);
    printf("\nNumero do Quarto: %d",vetRELX2[i].numero_quarto);
    printf("\nTarifa(R$): %2.f",vetRELX2[i].tarifa);
    printf("\nTipo do Quarto: %s",vetRELX2[i].tipo_quarto);
    printf("\n----------------------------\n\n");
    }
}
    system("pause");
}


int validaReserva(int idReserva){

int i;
int ret=-1;

for(i=0;i<6481;i++){

    if (vetReservas[i].id_reserva==idReserva && (strcmp(vetReservas[i].status, "Pendente")==0 || strcmp(vetReservas[i].status, "Pendente Check-out")==0)){

        ret=1;
    }

}
return ret;
}

void realizaCheckin(){

int ret;
int reserva;

printf("\n--> Digite a reserva que deseja fazer Check-in: ");
scanf("%d", &reserva);
fflush(stdin);

ret=validaReserva(reserva);

if(ret==1){
int confirmacao;

printf("\n\n----------Reserva----------------");
printf("\nID Reserva: %d",vetReservas[reserva].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[reserva].cpf_hospede);
printf("\nHotel: %s",vetReservas[reserva].hotel);
printf("\nTipo do Quarto: %s",vetReservas[reserva].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[reserva].numero_quarto);
printf("\nCheck-in: %d",vetReservas[reserva].cki);
printf("\nCheck-out: %d",vetReservas[reserva].cko);
printf("\nStatus Pagamento: %s",vetReservas[reserva].status);
printf("\n---------------------------------\n\n");

    printf("\n--> Confirmar Check-in. [1]-Sim | [2]-Não: ");
    scanf("%d", &confirmacao);
    fflush(stdin);

    if(confirmacao==1){
        printf("\n\n----------Check-in Realizado----------\n\n");

        strcpy(vetReservas[reserva].status, "Pendente Check-out");

        system("pause");
    }else{

    printf("\n\n----------Check-in não Realizado----------\n\n");
    system("pause");

    }
}else{
    printf("\n\n----------Esta Reserva não existe.----------\n\n");
    system("pause");
}

}


void realizaCheckout(){

int ret;
int reserva;
float totalConsumo=000000.00;
int tipo_pagamento;
float valor_quarto;
int dias;
float valor_diarias;
float valor_total;

printf("\n--> Digite a reserva que deseja fazer Check-out: ");
scanf("%d", &reserva);
fflush(stdin);

ret=validaReserva(reserva);

if(ret==1){
int confirmacao;

printf("\n\n----------Reserva----------------");
printf("\nID Reserva: %d",vetReservas[reserva].id_reserva);
printf("\nCPF Hospede: %s",vetReservas[reserva].cpf_hospede);
printf("\nHotel: %s",vetReservas[reserva].hotel);
printf("\nTipo do Quarto: %s",vetReservas[reserva].tipo_quarto);
printf("\nNumero do Quarto: %d",vetReservas[reserva].numero_quarto);
printf("\nCheck-in: %d",vetReservas[reserva].cki);
printf("\nCheck-out: %d",vetReservas[reserva].cko);
printf("\nStatus Pagamento: %s",vetReservas[reserva].status);
printf("\n---------------------------------\n\n");

printf("----------Lista de Consumo----------");
printf("\n");
int x;
float total=000000.00;

   for(x=0;x<count_id_consumo;x++){

       if(vetConsumo[x].id_reserva==reserva){

                printf("\n----------------------------");
                printf("\nID Reserva: %d",vetConsumo[x].id_reserva);
                printf("\nServiço: %s",vetConsumo[x].item);
                printf("\nValor: %6.2f",vetConsumo[x].valor);
                printf("\n----------------------------\n");

                total=total+vetConsumo[x].valor;

       }
    }

printf("\nValor total de consumo: R$ %6.2f", total);
printf("\n\n");

if(strcmp(vetReservas[reserva].tipo_quarto,"Standard")==0){

valor_quarto=1500.00;

}else if(strcmp(vetReservas[reserva].tipo_quarto,"Luxo")==0){

valor_quarto=2500.00;

}else{

valor_quarto=1500.00;

}

dias=vetReservas[reserva].cko-vetReservas[reserva].cki;

valor_diarias=valor_quarto*dias;

printf("\nValor total de reservas: R$ %6.2f", valor_diarias);
printf("\n\n");

valor_total=valor_diarias+total;

printf("\nValor total a ser pago: R$ %6.2f", valor_total);
printf("\n\n");

printf("------------------------------------\n\n");

    printf("\n--> Confirmar Check-out. [1]-Sim | [2]-Não: ");
    scanf("%d", &confirmacao);
    fflush(stdin);

    if(confirmacao==1){


        printf("\n\n-----Escolha a forma de pagamento-----");
        printf("\n-->[1]Pix;");
        printf("\n-->[2]Debito;");
        printf("\n-->[3]Credito;");
        printf("\n\nEscolha:");
        scanf("%d", &tipo_pagamento);

        if(tipo_pagamento== 1 || tipo_pagamento== 2){

            printf("\n\nDesconto de 5 porcento aplicado.\n\n");
        }

        printf("\n\n----------Check-out Realizado----------\n\n");

        strcpy(vetReservas[reserva].status, "Pago");

        system("pause");
    }else{

    printf("\n\n----------Check-out não Realizado----------\n\n");
    system("pause");

    }
}else{
    printf("\n\n----------Esta Reserva não existe.----------\n\n");
    system("pause");
}

}

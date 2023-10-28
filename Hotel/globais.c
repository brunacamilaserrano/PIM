#include "globais.h"

int count_id_reserva=0;
int count_id_usuario=1;
int count_id_consumo=0;
char cpfLogado[255];

st_Usuario vetUsuarios[500];

void iniciaQuartos(){

int i=0;

for(i=0;i<=360;i++){
    vetRJSTD1[i].id_dia=i;

    strcpy(vetRJSTD1[i].disponivel, "Disponivel");

    strcpy(vetRJSTD1[i].hotel, "RJ");

    vetRJSTD1[i].numero_quarto=1;
    vetRJSTD1[i].tarifa=1500.00;

    strcpy(vetRJSTD1[i].tipo_quarto, "Standard");

}

for(i=0;i<361;i++){
    vetRJSTD2[i].id_dia=i;

    strcpy(vetRJSTD2[i].disponivel, "Disponivel");

    strcpy(vetRJSTD2[i].hotel, "RJ");

    vetRJSTD2[i].numero_quarto=2;
    vetRJSTD2[i].tarifa=1500.00;

    strcpy(vetRJSTD2[i].tipo_quarto, "Standard");

}

for(i=0;i<361;i++){
    vetRJLX1[i].id_dia=i;

    strcpy(vetRJLX1[i].disponivel, "Disponivel");

    strcpy(vetRJLX1[i].hotel, "RJ");

    vetRJLX1[i].numero_quarto=1;
    vetRJLX1[i].tarifa=2500.00;

    strcpy(vetRJLX1[i].tipo_quarto, "Luxo");

}

for(i=0;i<361;i++){
    vetRJLX2[i].id_dia=i;

    strcpy(vetRJLX2[i].disponivel, "Disponivel");

    strcpy(vetRJLX2[i].hotel, "RJ");

    vetRJLX2[i].numero_quarto=2;
    vetRJLX2[i].tarifa=2500.00;

    strcpy(vetRJLX2[i].tipo_quarto, "Luxo");

}

for(i=0;i<361;i++){
    vetRESTD1[i].id_dia=i;

    strcpy(vetRESTD1[i].disponivel, "Disponivel");

    strcpy(vetRESTD1[i].hotel, "RE");

    vetRESTD1[i].numero_quarto=1;
    vetRESTD1[i].tarifa=1500.00;

    strcpy(vetRESTD1[i].tipo_quarto, "Standard");

}

for(i=0;i<361;i++){
    vetRESTD2[i].id_dia=i;

    strcpy(vetRESTD2[i].disponivel, "Disponivel");

    strcpy(vetRESTD2[i].hotel, "RE");

    vetRESTD2[i].numero_quarto=2;
    vetRESTD2[i].tarifa=1500.00;

    strcpy(vetRESTD2[i].tipo_quarto, "Standard");

}

for(i=0;i<361;i++){
    vetRELX1[i].id_dia=i;

    strcpy(vetRELX1[i].disponivel, "Disponivel");

    strcpy(vetRELX1[i].hotel, "RE");

    vetRELX1[i].numero_quarto=1;
    vetRELX1[i].tarifa=2500.00;

    strcpy(vetRELX1[i].tipo_quarto, "Luxo");

}

for(i=0;i<361;i++){
    vetRELX2[i].id_dia=i;

    strcpy(vetRELX2[i].disponivel, "Disponivel");

    strcpy(vetRELX2[i].hotel, "RE");

    vetRELX2[i].numero_quarto=2;
    vetRELX2[i].tarifa=2500.00;

    strcpy(vetRELX2[i].tipo_quarto, "Luxo");

}

}

void relatorioReceitas(){

    int i;
    int receita;
    float total=000000.00;
    int o;
    int dias;
    float valor_diarias=0.0;
    float valor_total=0.0;
    float valor_quarto=0.0;

    RECEITA:
    system("cls");
    puts("\n");
    puts("---------Receitas----------");
    puts("[1]-A receber");
    puts("[2]-Recebidas");
    puts("[3]-Voltar");
    puts("------------------------");
    printf("\n");
    printf("Escolha a opção: ");
    scanf("%d", &receita);
    fflush(stdin);

    switch (receita)
                {
               case 1:
                system("cls");



        for(i=0;i<count_id_reserva;i++){
                    if (strcmp(vetReservas[i].status, "Pendente")==0 || strcmp(vetReservas[i].status, "Pendente Check-out")==0){

                        if(strcmp(vetReservas[i].tipo_quarto,"Standard")==0){

                        valor_quarto=1500.00;
                        }

                        if(strcmp(vetReservas[i].tipo_quarto,"Luxo")==0){

                        valor_quarto=2500.00;

                        }

                        dias=vetReservas[i].cko-vetReservas[i].cki;

                        valor_diarias=valor_quarto*dias;

                        total=total+valor_diarias;

                            for(o=0;o<count_id_consumo;o++){

                                if(vetConsumo[o].id_reserva==vetReservas[i].id_reserva){

                                    total=total+vetConsumo[o].valor;
                                }

                            }
                    }

                }
                    printf("\n---> Total a receber: %6.2f",total);
                    printf("\n");
                    system("pause");
                 goto RECEITA;
               break;

               case 2:
                                system("cls");

               for(i=0;i<count_id_reserva;i++){
                    if (strcmp(vetReservas[i].status, "Pago")==0){

                        if(strcmp(vetReservas[i].tipo_quarto,"Standard")==0){

                        valor_quarto=1500.00;
                        }

                        if(strcmp(vetReservas[i].tipo_quarto,"Luxo")==0){

                        valor_quarto=2500.00;

                        }

                        dias=vetReservas[i].cko-vetReservas[i].cki;

                        valor_diarias=valor_quarto*dias;

                        total=total+valor_diarias;

                            for(o=0;o<count_id_consumo;o++){

                                if(vetConsumo[o].id_reserva==vetReservas[i].id_reserva){

                                    total=total+vetConsumo[o].valor;
                                }

                            }
                    }

                }
                    printf("\n---> Total Pago: %6.2f",total);
                    printf("\n\n");
                    system("pause");
                 goto RECEITA;
               break;

               case 3:
                system("cls");

                 break;
               break;

              default:
             goto RECEITA;
        }
}

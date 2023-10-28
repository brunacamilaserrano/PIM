#include "globais.h"
#include "cadastroUsuarios.h"
#include "Reservas.h"
#include "servicos.h"

void cadastrarServico(){

int id_Reserva;
char servico[4000];
float valor;
int ret;

    printf("\n--> Digite o ID da Reserva: ");
    scanf("%d", &id_Reserva);
    fflush(stdin);

    printf("\n--> Digite a descrição do Servico: ");
    scanf("%s", &servico);
    fflush(stdin);

    printf("\n--> Digite o valor do Serviço. Não use ponto, use virgula ex: 128,50: ");
    scanf("%f", &valor);
    fflush(stdin);

    ret=validaReserva(id_Reserva);

    if(ret>-1){
        vetConsumo[count_id_consumo].id_consumo =count_id_consumo;
        vetConsumo[count_id_consumo].id_reserva =id_Reserva;
        strcpy(vetConsumo[count_id_consumo].item, servico);
        vetConsumo[count_id_consumo].valor = valor;

        count_id_consumo++;
        printf("\n-----Consumo Registrado-----\n\n");
    }else{
        printf("\n-----Reserva não cadastrada ou já encerrada-----\n\n");
    }
system("pause");
}

float listarConsumo(int id_reserva){

int x;
float total=000000.00;

   for(x=0;x<count_id_consumo;x++){

       if(vetConsumo[x].id_reserva==id_reserva){

                printf("\n----------------------------");
                printf("\nID Reserva: %d",vetConsumo[x].id_reserva);
                printf("\nServiço: %s",vetConsumo[x].item);
                printf("\nValor: %6.2f",vetConsumo[x].valor);
                printf("\n----------------------------\n");

                total=total+vetConsumo[x].valor;

       }
    }
return total;
}


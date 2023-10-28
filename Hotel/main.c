#include "globais.h"
#include "cadastroUsuarios.h"
#include "Reservas.h"
#include "servicos.h"



void main(void) {
setlocale (LC_ALL, "Portuguese");

int menuLogin;
int menuFuncionario;
int menuHospede;
int idReserva;
int ret;

strcpy(vetUsuarios[0].nome, "Brenda");
strcpy(vetUsuarios[0].senha, "brenda");
strcpy(vetUsuarios[0].cpf, "431");
vetUsuarios[0].perfil=0;

iniciaQuartos();

ESCOLHALOGIN:
system("cls");
puts("\n");
puts("--------------------------------------------------------------------------------------------------------------------");
puts("|  Professor, para o primeiro acesso, utilize o cpf e senha master das linhas 18 e 19 do main.c.                    |");
puts("---------------------------------------------------------------------------------------------------------------------");
puts("|  *Este programa é Case Sensitive. Portanto, nos momentos de escolhas siga os exemplos para correto funcionamento. |");
puts("---------------------------------------------------------------------------------------------------------------------");
puts("\n");
puts("---------Login----------");
puts("[1]-Funcionario");
puts("[2]-Hospede");
puts("[3]-Verificar disponibilidade e valores");
puts("------------------------");
printf("\n");
printf("Escolha a opção: ");
scanf("%d", &menuLogin);
fflush(stdin);

int cod_usr;

switch (menuLogin)
{
   case 1:
       LOGINFUNCIONARIO:
        system("cls");
        cod_usr=realizarLogin(0);
        system("cls");

        if(cod_usr == -2){
           goto ESCOLHALOGIN;
        }

        if(cod_usr == -1){
           goto LOGINFUNCIONARIO;
        }

        MENUFUNCIONARIO:
        system("cls");
        printf("Logado com: %s",cpfLogado);
        puts("\n\n---------Funcionario----------");
        puts("\n");
        puts("[1]-Cadastro de Usuários");
        puts("[2]-Realizar Reserva");
        puts("[3]-Realizar Check-In");
        puts("[4]-Realizar Check-Out");
        puts("[5]-Adicionar Serviços");
        puts("[6]-Relatório de Ocupação");
        puts("[7]-Relatório de Receitas");
        puts("[8]-Visualizar Reservas");
        puts("[9]-Visualizar Usuários");
        puts("[10]-Sair");
        puts("\n");
        puts("------------------------------");
        puts("\n");
        printf("Escolha a opção: ");
        scanf("%d", &menuFuncionario);
        fflush(stdin);


        switch (menuFuncionario)
        {
           case 1:
             cadastroUsuario();
             goto MENUFUNCIONARIO;
           break;

           case 2:
            system("cls");
            puts("-----Reserva de Quartos-----");

                criarReserva();

            goto MENUFUNCIONARIO;
           break;

           case 3:
               system("cls");
             realizaCheckin();
             goto MENUFUNCIONARIO;
           break;

           case 4:
               system("cls");
             realizaCheckout();
             goto MENUFUNCIONARIO;
           break;

           case 5:
             system("cls");
             cadastrarServico();
             goto MENUFUNCIONARIO;
           break;

           case 6:
               system("cls");
               printf("---------Quartos Ocupados / dia---------\n\n");
             relatorioOcupacao();
             goto MENUFUNCIONARIO;
           break;

           case 7:
             system("cls");
             relatorioReceitas();
             goto MENUFUNCIONARIO;
           break;

           case 8:
            system("cls");
            visualizarReservas();
            goto MENUFUNCIONARIO;
           break;

           case 9:
            system("cls");
            listarUsuarios();
            system("pause");
            goto MENUFUNCIONARIO;
           break;

           case 10:
             goto ESCOLHALOGIN;
           break;

           default:
             goto ESCOLHALOGIN;
        }

   break;

   case 2:
       LOGINHOSPEDE:
        system("cls");
        cod_usr=realizarLogin(1);
        system("cls");

        if(cod_usr == -2){
           goto ESCOLHALOGIN;
        }

        if(cod_usr == -1){
           goto LOGINHOSPEDE;
        }

        MENUHOSPEDE:
        system("cls");
        printf("Logado com: %s",cpfLogado);
        puts("\n\n---------Hospede----------");
        puts("\n");
        puts("[1]-Visualizar minhas Reservas");
        puts("[2]-Modificar Reserva");
        puts("[3]-Cancelar Reserva");
        puts("[4]-Sair");
        puts("\n");
        puts("--------------------------");
        puts("\n");
        printf("Escolha a opção: ");
        scanf("%d", &menuHospede);

        switch (menuHospede)
                {
               case 1:
                 visualizarReservasH();
                 goto MENUHOSPEDE;
               break;

               case 2:
                system("cls");
                printf("\n--> Digite o ID da reserva que deseja alterar:");
                scanf("%d", &idReserva);
                fflush(stdin);

                modificarReserva(idReserva);
                goto MENUHOSPEDE;
               break;

               case 3:
                system("cls");
                printf("\n--> Digite o ID da reserva que deseja cancelar:");
                scanf("%d", &idReserva);
                fflush(stdin);

                cancelarReserva(idReserva);
                 goto MENUHOSPEDE;
               break;

               case 4:

                 goto ESCOLHALOGIN;
               break;

              default:
             goto ESCOLHALOGIN;
        }
        case 3:
        system("cls");
        puts("---------Quartos----------\n\n");

        listarQuartos();

        system("cls");
        goto ESCOLHALOGIN;
        break;
   default:
     puts("A opção escolhida não é uma opção válida.");
     goto ESCOLHALOGIN;
}
}

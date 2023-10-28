#include "globais.h"
#include "cadastroUsuarios.h"

void cadastroUsuario(){

system("cls");
puts("----------Cadastro de Usuário----------\n");

printf("Digite o Nome: ");
scanf("%255[^\n]s", &vetUsuarios[count_id_usuario].nome);
fflush(stdin);

printf("\n\nDigite a Senha: ");
scanf("%255[^\n]s", &vetUsuarios[count_id_usuario].senha);
fflush(stdin);

printf("\n\nDigite o CPF: ");
scanf("%255[^\n]s", &vetUsuarios[count_id_usuario].cpf);
fflush(stdin);

printf("\n\nDigite o Perfil [0]-Funcionario | [1]-Cliente: ");
scanf("%d", &vetUsuarios[count_id_usuario].perfil);
fflush(stdin);

puts("\n---------------------------------------");
count_id_usuario++;

}

int buscaUsuario(){

    int i=0;
    char cpf[255];

     printf("\n\nDigite o CPF do Hospede: ");
     scanf("%s", &cpf);
     fflush(stdin);

    for(i=0;i<count_id_usuario;i++){

    if(strcmp(vetUsuarios[i].cpf,cpf)==0){
        puts("\n-------------------Hospede Encontrado-------------------");
        printf("ID: %d",i);
        printf("\nNome: %s",vetUsuarios[i].nome);
        printf("\nSenha: %s",vetUsuarios[i].senha);
        printf("\nCPF: %s",vetUsuarios[i].cpf);
        printf("\nPerfil: %d",vetUsuarios[i].perfil);
        puts("\n--------------------------------------------------------\n");
        return i;
    }
    }
    puts("\n-------------------Hospede não Encontrado-------------------\n");
 return -1;

}

int realizarLogin(int perfil){

int i=0;
char logind[255];
char senhad[255];

puts("----------Login----------\n");

printf("Digite o CPF: ");
scanf("%s", &logind);
fflush(stdin);

printf("\n\nDigite a Senha: ");
scanf("%s", &senhad);
fflush(stdin);

puts("-------------------------\n");

    for(i=0;i<count_id_usuario;i++){
       if (vetUsuarios[i].perfil==perfil && strcmp(vetUsuarios[i].cpf, logind)==0 && strcmp(vetUsuarios[i].senha, senhad)==0){
        printf("Login Realizado com sucesso\n\n");
        strcpy(cpfLogado,vetUsuarios[i].cpf);
        system("pause");
        return i;
        }
    }

    int retry;

    printf("Usuário/Senha inválido. Deseja tentar novamente? [1]-Sim | [2]-Não: ");
    scanf("%d", &retry);
    fflush(stdin);

    if (retry==2){
        return -2;
    }
    return -1;
}

void listarUsuarios(){

int i=0;

    for(i=0;i<count_id_usuario;i++){

    puts("------------------------------------------");
    printf("ID: %d",i);
    printf("\nNome: %s",vetUsuarios[i].nome);
    printf("\nSenha: Dado protegido pela LGPD");
    printf("\nCPF: %s",vetUsuarios[i].cpf);
    printf("\nPerfil: %d",vetUsuarios[i].perfil);
    puts("\n------------------------------------------\n");

    }

}


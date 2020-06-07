#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#define maxTam 12


typedef struct Reserva{

    int codigo_aviao;
    char nome[50];

}Reserva;

typedef struct Aviao{

    int codigo, assentos, vagas;

}Aviao;

typedef struct ListaReserva{

    int primeiro, ultimo;
    Reserva reserva[1000];

}ListaReserva;

typedef struct ListaAvioes{

    int primeiro, ultimo;
    Aviao avioes[maxTam];
    ListaReserva reserva;

}ListaAvioes;

void CriarListaVazia(ListaAvioes *listaA){

    listaA->primeiro = 0;
    listaA->ultimo = 0;

    listaA->reserva.primeiro = 0;
    listaA->reserva.ultimo = 0;

}

bool VerificarAviaoExiste(ListaAvioes avioes, Reserva reserva){

    int i, cont = 0;

    for(i = avioes.primeiro; i < avioes.ultimo; i++){

        if(avioes.avioes[i].codigo == reserva.codigo_aviao){
            cont = 1;
            break;
        }
    }
    if(cont == 1)
        return true;
    else
        return false;

}

void insereListaReserva(ListaAvioes *aviao, Reserva reserva){

    int i, cont = 0;

    for (i = 0; i < aviao->ultimo; i++){

        if(aviao->avioes->codigo == reserva.codigo_aviao){}
          cont = i;

    }

    if(aviao->avioes->vagas == 0){
        printf("Limite de passageiros excedido");
        return;
    }
    else{

        aviao->reserva.reserva[aviao->reserva.ultimo] = reserva;
        aviao->avioes->vagas--;
        aviao->reserva.ultimo++;
        Sleep(600);
        printf("Reserva efeituada com sucesso");
    }

}

void insereListaAviao(ListaAvioes *lista, Aviao aviao){


    if(lista -> ultimo == maxTam){

        printf("Limite de avioes excedido");
        return;
    }
    else{

        lista->avioes[lista->ultimo] = aviao;
        lista->ultimo++;
        printf("Aviao adicionado com sucesso !\n");
    }
}

void ExibirListaAvioes(ListaAvioes aviao, int veri){

    int i, j;

    printf("Quantidade de vagas disponiveis : %d \n", aviao.avioes->vagas);

    for(i = 0; i < aviao.ultimo; i++){
        if(aviao.avioes[i].codigo == veri){
            for(j = 0; j < aviao.reserva.ultimo; j++){
                printf("Nome do passageiro : %s\n", aviao.reserva.reserva[j].nome);
            }

        }
    }

}

void InformarReservas(ListaAvioes aviao){

    int i, cont = 0;
    char nomeP[50];

    printf("Nome do passageiro : ");
    scanf("%s", nomeP);

    for (i = 0; i < aviao.ultimo; i++){
        if(strcmp(aviao.reserva.reserva[i].nome, nomeP) == 0){
            printf("Reserva no Avião de codigo = %d\n", aviao.reserva.reserva[i].codigo_aviao);
            cont++;
        }
    }
    if(cont == 0)
        printf("Não há reservas para ninguem com este nome\n");
}

int main(){

setlocale(LC_ALL, "");

Aviao aviao;

int veri = 0, cont = 0;

char nomeP[30];

Reserva reserva;
ListaAvioes listaA;


CriarListaVazia(&listaA);

int escolha = 0;

do{

printf("Olá, o que desejas fazer ? \n\n");
printf("1 - Cadastrar avião\n");
printf("2 - Reservar passagem\n");
printf("3 - Mostrar quantidade de vagas disponiveis e assentos ocupados\n");
printf("4 - Exibir reservas de certo passageiro\n");
printf("5 - Sair do progama\n\n");

scanf("%d", &escolha);




switch(escolha){

case 1 :{

    printf("Qual o codigo do aviao a ser cadastrado : ");
    scanf("%d", &aviao.codigo);

    printf("Qual a quantidade de assentos deste aviao : ");
    scanf("%d", &aviao.assentos);

    aviao.vagas = aviao.assentos;

    insereListaAviao(&listaA, aviao);

    printf("\n");
    system("pause");
    printf("\n");
    system("cls");

    break;

}

case 2 :{

    printf("Nome do passageiro : ");
    scanf("%s", reserva.nome);

    printf("Código do avião : ");
    scanf("%d", &reserva.codigo_aviao);

    if(VerificarAviaoExiste(listaA, reserva)){

    printf("O avião existe, processando reserva . . .\n");

    insereListaReserva(&listaA, reserva);
    }
    else{
        printf("O avião não exite, retornando ao menu . . . ");
    }

    printf("\n");
    system("pause");
    printf("\n");
    system("cls");

    break;
}

case 3 :{

    if(listaA.ultimo == 0){
        printf("Não há aviões registrados ! \n");
        Sleep(1000);
        system("cls");
        break;
    }
    else{

    printf("Codigo do avião : ");
    scanf("%d", &veri);

    ExibirListaAvioes(listaA, veri);

    printf("\n");
    system("pause");
    printf("\n");
    system("cls");

    break;
    }
}

case 4 :{

    InformarReservas(listaA);

    system("pause");
    system("cls");

    break;
}

case 5 :{

    printf("\n Encerrando progama . . . ");
    Sleep(900);
    system("cls");
    cont = 1;

    break;
}

default : {

    printf("Opção incorreta, retornando ao menu . . .");
    Sleep(600);
    system("cls");

    break;
}
}
}while (cont == 0);
}

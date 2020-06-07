#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#define maxTam 100

typedef struct TipoAviao{

    int id;
    int combustivel;

}TipoAviao;

typedef struct TipoLista{

    int primeiro, ultimo;

    TipoAviao avioes[maxTam];

}TipoLista;

void CriarListaVazia(TipoLista *lista){

    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}

void insereLista(TipoLista *lista, TipoAviao item){

    if(lista -> ultimo == maxTam){
        return;
    }

    else{

        lista->avioes[lista->ultimo] = item;
        lista->ultimo++;
        printf("\n");
    }
}

void removeLista(TipoLista *lista, TipoAviao aviao){

    int i, pos=-1;

    for(i = 0; i < lista->ultimo; i++){

        if(lista->avioes[i].id == aviao.id){
            pos = i;
    }
}
    if(pos != -1){

    for(i = pos; i < lista -> ultimo -1; i++){

        lista -> avioes[i] = lista -> avioes[i+1];

}
     lista -> ultimo--;

}
}

void gerarAvioes(TipoAviao *aviao){

    aviao->combustivel = (rand()%9 + 2);
    aviao->id = rand() % 1000;

}

void DiminuirCombustivel(TipoLista *aterr, TipoLista *emer){

    int i;
    TipoAviao item;

    for(i = aterr->primeiro; i < aterr->ultimo; i++){
        aterr->avioes[i].combustivel--;
    }
    for(i = emer->primeiro; i < emer->ultimo; i++){
        emer->avioes[i].combustivel--;
    }

    for(i = 0; i < aterr->ultimo; i++){

        if(aterr->avioes[i].combustivel < 3){
            item = aterr->avioes[i];
            insereLista(emer, item);
        }
    }

}

bool vazia(TipoLista lista){
    if(lista.ultimo == lista.primeiro){
        return true;
    }
    else{
        return false;
    }
}

bool Nvazia(TipoLista lista){

    if(lista.ultimo == lista.primeiro){
        return false;
    }
    else{
        return true;
    }
}

void ExibeLista(TipoLista lista){
    int i;
    for(i = lista.primeiro; i < lista.ultimo; i++)
    {
        printf("============================\n");
        printf("Id: %d\n", lista.avioes[i].id);
        printf("combustivel: %d\n", lista.avioes[i].combustivel);
        printf("----------------------------\n");
    }
}

void Controle(TipoLista aterr, TipoLista decolagem, TipoLista emergencia, TipoLista p1, TipoLista p2, TipoLista p3){

        TipoAviao item;
        TipoAviao avia1;
        int caiu = 0;
        int ContadorDeTempo = 2000, i;

    do{

        int Aterr = 0, Deco = 0;

        Aterr = rand() % 3;
        Deco = rand() % 3;

        for(i = 0; i < Aterr; i++){

            gerarAvioes(&avia1);

            if(avia1.combustivel < 3){
                insereLista(&emergencia, avia1);
            }
            else{
                insereLista(&aterr, avia1);
            }
}
        for(i = 0; i < Deco; i++){

            avia1.combustivel = 10;
            avia1.id = rand() % 1000;

            insereLista(&decolagem, avia1);

}

        for(i = decolagem.primeiro; i < decolagem.ultimo; i++){
            printf("||------------------------------Prateleira Decolagem-------------------------------||\n");
            printf("ID do avião = %d\n", decolagem.avioes[i].id);
            printf("Combustivel do avião = %d\n\n\n", decolagem.avioes[i].combustivel);
        }
        for(i = aterr.primeiro; i < aterr.ultimo; i++){
            printf("||------------------------------Prateleira Aterrisagem-------------------------------||\n");
            printf("ID do avião = %d\n", aterr.avioes[i].id);
            printf("Combustivel do avião = %d\n\n\n", aterr.avioes[i].combustivel);
        }
        for(i = emergencia.primeiro; i < emergencia.ultimo; i++){
            printf("||------------------------------Prateleira Emergencia-------------------------------||\n");
            printf("ID do avião = %d\n", emergencia.avioes[i].id);
            printf("Combustivel do avião = %d\n\n\n", emergencia.avioes[i].combustivel);
        }

        if(vazia(p1)){
            if(Nvazia(emergencia)){
                item = emergencia.avioes[emergencia.primeiro];
                removeLista(&emergencia, item);
                insereLista(&p1, item);
        }
            else if(Nvazia(aterr)){
                item = aterr.avioes[aterr.primeiro];
                removeLista(&aterr, item);
                insereLista(&p1, item);
            }
            else if(Nvazia(decolagem)){
                item = decolagem.avioes[decolagem.primeiro];
                removeLista(&decolagem, item);
                insereLista(&p1, item);
            }
}

        if(vazia(p2)){
            if(Nvazia(emergencia)){
                item = emergencia.avioes[emergencia.primeiro];
                removeLista(&emergencia, item);
                insereLista(&p2, item);
        }
            else if(Nvazia(aterr)){
                item = aterr.avioes[aterr.primeiro];
                removeLista(&aterr, item);
                insereLista(&p2, item);
            }
            else if(Nvazia(decolagem)){
                item = decolagem.avioes[decolagem.primeiro];
                removeLista(&decolagem, item);
                insereLista(&p2, item);
            }
}

        if(vazia(p3)){
            if(Nvazia(emergencia)){
                item = emergencia.avioes[emergencia.primeiro];
                removeLista(&emergencia, item);
                insereLista(&p3, item);
            }
            else if(Nvazia(aterr)){
                item = aterr.avioes[aterr.primeiro];
                removeLista(&aterr, item);
                insereLista(&p3, item);
            }
            else if(Nvazia(decolagem)){
                item = decolagem.avioes[decolagem.primeiro];
                removeLista(&decolagem, item);
                insereLista(&p3, item);
            }
}

        for(i = 0; i < emergencia.ultimo; i++){
            if(emergencia.avioes[i].combustivel < 0){
                caiu++;
            }

        }
            printf("||------------------------------------- = Pistas = ------------------------------------||\n");
        if(Nvazia(p1))
            printf("Pista 1 = %d\nAviao id = %d\nCombustivel = %d\n\n", p1.ultimo, p1.avioes[p1.primeiro].id, p1.avioes[p1.primeiro].combustivel);
        if(Nvazia(p2))
            printf("Pista 2 = %d\nAviao id = %d\nCombustivel = %d\n\n", p2.ultimo, p2.avioes[p2.primeiro].id, p2.avioes[p2.primeiro].combustivel);
        if(Nvazia(p3))
            printf("Pista 3 = %d\nAviao id = %d\nCombustivel = %d\n\n", p3.ultimo, p3.avioes[p3.primeiro].id, p3.avioes[p3.primeiro].combustivel);
            printf("||------------------------------------- ========== ------------------------------------||\n");

            printf("Aviões caidos = %d\n", caiu);

            item = p1.avioes[p1.primeiro];
            removeLista(&p1, item);
            item = p2.avioes[p2.primeiro];
            removeLista(&p2, item);
            item = p3.avioes[p3.primeiro];
            removeLista(&p3, item);

            DiminuirCombustivel(&aterr, &emergencia);
            Sleep(10000);
            system("cls");

} while(ContadorDeTempo);


}

int main(){

    setlocale(LC_ALL, "");

    srand(time(NULL));

    TipoLista Aterrisagem, Decolagem, Emergencia, Pista1, Pista2, Pista3;


    CriarListaVazia(&Aterrisagem);
    CriarListaVazia(&Decolagem);
    CriarListaVazia(&Emergencia);
    CriarListaVazia(&Pista1);
    CriarListaVazia(&Pista2);
    CriarListaVazia(&Pista3);


    Controle(Aterrisagem, Decolagem, Emergencia, Pista1, Pista2, Pista3);



}

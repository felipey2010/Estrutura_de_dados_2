#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include "arvbin.h"

using namespace std;

void iter_inorderm(Arv_bin* arv){
    //Incompleto
    system("cls"); //Limpar a tela
    stack<Nodo *> pilha;

    Nodo* ar = NULL;

    pilha.push(arv->raiz);

    while(!pilha.empty()){
        ar = pilha.top();

        if(ar->esq != NULL){
            if(ar->dir != NULL)
                pilha.push(ar->dir);

            pilha.push(ar->esq);
        }
        else{
            printf("%c ", ar->info);
            pilha.pop();
            if(ar->dir != NULL)
                pilha.push(ar->dir);
        }
    }
}
void iter_preordem(Arv_bin* arv){
    system("cls");
    stack<Nodo *> pilha;

    Nodo* ar = NULL;

    pilha.push(arv->raiz);

    while(!pilha.empty()){
        ar = pilha.top();
        printf("%c ", ar->info);

        pilha.pop();
        if(ar->dir != NULL)
            pilha.push(ar->dir);
        if(ar->esq != NULL)
            pilha.push(ar->esq);
    }
}
void iter_postordem(Arv_bin* arv){
    system("cls");
}

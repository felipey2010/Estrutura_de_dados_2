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
    int aux = 0; //Ponto de controle
    Nodo* corr = arv->raiz;

    while(corr != NULL || aux > 0){
        if(corr != NULL){
            pilha.push(corr);
            corr = corr->esq;
            aux++;
        }
        else{
            aux--;
            corr = pilha.top();

            printf("%c ", corr->info);
            pilha.pop();
            corr = corr->dir;
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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "arvbbb.h"

Nodo* cria(){
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    scanf("%d", &no->dado);
    no->esq = no->dir = NULL;

    return no;
}

//Imprimir arvore em inordem
void imprime_inordem(Nodo* nodo){
    if(nodo != NULL){
        imprime_inordem(nodo->esq);

        printf("%d ", nodo->dado);

        imprime_inordem(nodo->dir);
    }
}

//Busca iterativa
Nodo* busca_no(Arv_bbb* arv, int k){
    while(arv->raiz != NULL && arv->raiz->dado != k){
        if(k > arv->raiz->dado)
            arv->raiz = arv->raiz->esq;
        else
            arv->raiz = arv->raiz->dir;
    }
    return arv->raiz;
}
/*
//Busca recursiva
Nodo* busca_no(Arv_bbb* raiz, int k){
    if(raiz == NULL || raiz->dado == k)
        return raiz;
    else if(k < raiz->dado)
        return busca_no(raiz->esq, k);
    else
        return busca_no(raiz->dir, k);
}*/
//Inserir na arvore
void insere(Nodo* raiz, Nodo* temp){
    if(raiz == NULL) //Se o nodo for vazio, insere o novo nodo
        raiz = temp;
    else{
        if(temp->dado > raiz->dado){ //Se o valor a ser inserido for maior que o da raiz, entao insere na direita da arvore
            if(raiz->dir != NULL)
                insere(raiz->dir, temp);
            else
                raiz->dir = temp;
        }

        if(temp->dado < raiz->dado){ //Se o valor for menor, entao insere na esquerda
            if(raiz->esq != NULL)
                insere(raiz->esq, temp);
            else
                raiz->esq = temp;
        }
        if(temp->dado == raiz->dado)
            printf("\nValor ja existe!\n");
    }
}
//Remove um no da arvore
Nodo* remove_arvbbb(Nodo* no, int v){
    if(no == NULL)
        return NULL;
    else if(v < no->dado)
        no->esq = remove_arvbbb(no->esq, v);
    else if(v > no->dado)
        no->dir = remove_arvbbb(no->dir, v);
    else{
        if(no->esq == NULL && no->dir == NULL){ //Nao tem filho
            free(no);
            return NULL;
        }
        else if(no->dir == NULL){ //tem um filho
            Nodo* aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL){ //tem um filho
            Nodo* aux = no;
            no = no->dir;
            free(aux);
        }
        else{ //sub arvore tem dois filhos
            Nodo* p = no->esq;
            while(p->dir != NULL)
                p = p->dir;

            no->dado = p->dado;
            p->dado = v;
            no->esq = remove_arvbbb(no->esq, v);
        }
    }
    return no;
}
//Liberar a arvore
void arv_libera(Nodo* nodo){
    if(nodo == NULL) //Se o no for vazio, volte
        return;
    arv_libera(nodo->esq);
    arv_libera(nodo->dir);
    free(nodo);
    nodo = NULL;
}

/* TO-DO
 *Criar INT_MAX e INT_MIN
*/
int teste_arvore(Nodo* no){
    if(no == NULL)
        return 1;
    else if(no->esq != NULL && no->esq->dado > no->dado)
        return 0;
    else if(no->dir != NULL && no->dir->dado < no->dado)
        return 0;
    else if(!teste_arvore(no->esq) || !teste_arvore(no->dir))
        return 0;
    else
        return 1;
}
//Testar se arvore eh completa ou nao
int eh_completa(Nodo* no){
    if(no != NULL && no->esq != NULL && no->dir != NULL){
        return 1;
    }
    else
        return 0;

    return(eh_completa(no->esq) && eh_completa(no->dir));
}


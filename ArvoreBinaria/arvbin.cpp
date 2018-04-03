#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "arvbin.h"

using namespace std;

//Criar uma arvore
Arv_bin* arv_cria(Nodo* arv){
    Arv_bin* no = (Arv_bin*) malloc(sizeof(Arv_bin));
    no->raiz = arv;
    return  no;
}
//Criar um no de uma arvore
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir){
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));
    no->esq = esq;
    no->dir = dir;
    no->info = c;

    return no;
}
//Imprimir arvore em preordem
void imprime_preordem(Nodo* nodo){
    if(nodo != NULL){ //Se o no nao for vazio, entao imprime a informacao na raiz
        printf("%c ", nodo->info);
    //Recursivamente imprime a informacao na esquerda da raiz se tiver
    imprime_preordem(nodo->esq);
    //Recursivamente imprime a informacao na direita da raiz se tiver
    imprime_preordem(nodo->dir);
    }
}
//Imprimir arvore em inordem
void imprime_inordem(Nodo* nodo){
    if(nodo != NULL){
        imprime_inordem(nodo->esq);

        printf("%c ", nodo->info);

        imprime_inordem(nodo->dir);
    }
}
//Imprimir arvore em postordem
void imprime_postordem(Nodo* nodo){
    if(nodo != NULL){
        imprime_postordem(nodo->esq);

        imprime_postordem(nodo->dir);

        printf("%c ", nodo->info);
    }
}

//Fazer escolha da ordem em que imprimir a arvore
void imprime_escolhendo_ordem(Arv_bin* arv, int n){
    system("cls");
    if(n == 1){
        printf("PREORDEM: ");
        imprime_preordem(arv->raiz); //imprimir preordem
    }
    else if(n == 2){
        printf("INORDEM: ");
        imprime_inordem(arv->raiz);//imprimir inordem
    }
    else if(n == 3){
        printf("POSTORDEM: ");
        imprime_postordem(arv->raiz);//imprimir postordem
    }
    else
        printf("ESCOLHA INVALIDA!\n");
}

int arv_pertence_no(Nodo* nodo, char c){
    if(nodo == NULL)
        return 0;
    if(nodo->info == c)
        return 1;

    return (arv_pertence_no(nodo->esq, c) || arv_pertence_no(nodo->dir, c));
}
int arv_pertence(Arv_bin* arv, char c){
    if(arv == NULL)
        return 0;
    return arv_pertence_no(arv->raiz, c);
}

void arv_libera_no(Nodo* nodo){
    if(nodo == NULL) //Se o no for vazio, volte
        return;
    arv_libera_no(nodo->esq);
    arv_libera_no(nodo->dir);
    free(nodo);
    nodo = NULL;
}

void arv_libera(Arv_bin* arv){
    if(arv->raiz == NULL) //Se a raiz for NULL, volte
        return;
    arv_libera_no(arv->raiz); //Passando a raiz para liberar os nos
    free(arv); //Liberar a arvore
}

int arv_altura(Nodo* nodo){
    if(nodo == NULL)
        return -1;
    int alt_sae = 1 + arv_altura(nodo->esq);
    int alt_sad = 1 + arv_altura(nodo->dir);

    return (alt_sad>alt_sae?alt_sad:alt_sae);
}

Nodo* busca_no(Nodo* nodo, char c){
    Nodo* no_esq, *no_dir;
    if(nodo == NULL)
        return NULL;
    else{
        if(nodo->info == c)
            return nodo;
    }
    no_esq = busca_no(nodo->esq, c);
    no_dir = busca_no(nodo->dir, c);

    if(no_esq != NULL){
        printf("'%c' SE ENCONTRA NA ESQUERDA DA ARVORE\n", c);
        return no_esq;
    }
    if(no_dir != NULL){
        printf("'%c' SE ENCONTRA NA DIREITA DA ARVORE\n", c);
        return no_dir;
    }

    return NULL;
}
int tamanho_no(Nodo* nodo){
    if(nodo == NULL)
        return -1; //se no for vazio, nao conte +1
    int no_sae =1 + tamanho_no(nodo->esq);
    int no_sad = 1 + tamanho_no(nodo->dir);
    return (no_sae+no_sad);
}
int tamanho(Arv_bin* arv){
    if(arv == NULL)
        return 0;
    return (1 + tamanho_no(arv->raiz));//Conte +1 por causa da raiz principal
}

Nodo* espelho_no(Nodo* nodo){
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));
    if(nodo == NULL)
        return NULL;
    else{
        no->info = nodo->info;
        no->dir = espelho_no(nodo->esq);
        no->esq = espelho_no(nodo->dir);
    }

    return no;
}
Arv_bin* espelho(Arv_bin* arv){
    Arv_bin* a = (Arv_bin*) malloc(sizeof(Arv_bin));

    if(arv->raiz != NULL){
        a->raiz = espelho_no(arv->raiz);
    }
    return a;
}



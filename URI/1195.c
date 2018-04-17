#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dado;
    struct nodo* esq;
    struct nodo* dir;
}Nodo;

typedef struct arvbbb{
    Nodo* raiz;
}Arv_bbb;

Nodo* cria(int v);

void imprime_preordem(Nodo* nodo);
void imprime_inordem(Nodo* nodo);
void imprime_posordem(Nodo* nodo);

void insere(Nodo* raiz, Nodo* temp);

//Liberar a arvore
void arv_libera(Nodo* nodo);

int main(){
    //Declaracao da arvore vazia e um nodo temporario
    Nodo* arv = NULL, *temp;
    int C, i = 1, N, aux;

    scanf("%d", &C);

    if(C <= 1000){ //Test case must not exceed 1000
        while(C > 0){ //Number of test cases
            scanf("%d", &N); //Number of nodes to enter value
            while(N > 0){
                scanf("%d",&aux);
                if(aux >= 0){
                    temp = cria(aux);
                    if(arv == NULL)
                        arv = temp;
                    else
                        insere(arv, temp);
                }
                N--;
            }
            printf("Case %d:\n", i);
            printf("Pre.: ");
            imprime_preordem(arv);
            printf("\nIn.: ");
            imprime_inordem(arv);
            printf("\nPost.: ");
            imprime_posordem(arv);
            printf("\n");
            i++;
            C--;
        arv_libera(arv);
        }
    }
    return 0;
}

Nodo* cria(int v){
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));
    no->dado = v;
    no->esq = no->dir = NULL;

    return no;
}
//Imprimir arvore em preordem
void imprime_preordem(Nodo* nodo){
    if(nodo != NULL){
        printf("%d ", nodo->dado);
        imprime_preordem(nodo->esq);
        imprime_preordem(nodo->dir);
    }
}
//Imprimir arvore em inordem
void imprime_inordem(Nodo* nodo){
    if(nodo != NULL){
        imprime_inordem(nodo->esq);
        printf("%d ", nodo->dado);
        imprime_inordem(nodo->dir);
    }
}
//Imprimir arvore em posordem
void imprime_posordem(Nodo* nodo){
    if(nodo != NULL){
        imprime_posordem(nodo->esq);
        imprime_posordem(nodo->dir);
        printf("%d ", nodo->dado);
    }
}
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
    }
}
//Liberar a arvore
void arv_libera(Nodo* nodo){
    if(nodo != NULL){ //Se o no for vazio, volte
        arv_libera(nodo->esq);
        arv_libera(nodo->dir);
        free(nodo);
        nodo = NULL;
    }
}

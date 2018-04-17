#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int preInd = 0; //Index comecando de zero

typedef struct node{
    char dado;
    struct node* esq;
    struct node* dir;
}Nodo;

//Funcao para busca a indice de um array de caracteres
int busca(char ch[], int ini, int fim, char v);

Nodo* novoNodo(char v);

Nodo* criaArv(char in[], char pre[], int ini, int fim);

void imprimir_posOrdem(Nodo* no);

void arv_libera(Nodo* nodo);

int main(){
    char in[53], pre[53];
    int c, i;
    int tam;
    //Numero de casos de teste
    scanf("%d", &c);
    if(c <= 2000){
        for(i = 0; i < c; i++){
            int n;
            Nodo* arv;
            //Numero de letras a pegar
            scanf("%d", &n);

            if(n >= 1 && n <= 52){
                getchar();
                scanf(" %s", pre);
                getchar();
                scanf(" %s", in);

                tam = strlen(pre);
                //if(strlen(pre) == strlen(in)){
                    arv = criaArv(in, pre, 0, (tam-1));

                    imprimir_posOrdem(arv);
                    printf("\n");
                    arv_libera(arv);
                //}
                preInd = 0;
            }
        }
    }
    return 0;
}
//Buscar o index de uma caracter numa array de caracteres
int busca(char ch[], int ini, int fim, char v){
    int i;
    for(i = ini; i <= fim; i++){
        if(ch[i] == v)
            return i;
    }
}
//Funcao para alocar novo nodo e atribuir NULL para sae e sad
Nodo* novoNodo(char v){
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));
    no->dado = v;
    no->esq = no->dir = NULL;

    return no;
}

//A funcao onde comeca todo o trabalho principal de criar uma arvore
Nodo* criaArv(char in[], char pre[], int ini, int fim){
    Nodo* no;

    if(ini > fim)
        return NULL;

    //Se index do inicio for igual ao fim, entao a arvore nao tem nenhum no entao retorna no
    if(ini == fim){
        //Pegando o primeiro elemento da preOrdem que sera a raiz da arvore
        no = novoNodo(pre[preInd++]);
        return no;
    }

    no = novoNodo(pre[preInd]);
    //Buscar o index do caracter da raiz no inOrdem
    int inStart = busca(in, ini, fim, pre[preInd++]);

    no->esq = criaArv(in, pre, ini, (inStart-1));
    no->dir = criaArv(in, pre, (inStart+1), fim);

    return no;
}

void imprimir_posOrdem(Nodo* nodo){
    if(nodo != NULL){
        imprimir_posOrdem(nodo->esq);

        imprimir_posOrdem(nodo->dir);

        printf("%c", nodo->dado);
    }
}
void arv_libera(Nodo* nodo){
    if(nodo != NULL){ //Se o no for vazio, volte
    arv_libera(nodo->esq);
    arv_libera(nodo->dir);
    free(nodo);
    nodo = NULL;
    }
}

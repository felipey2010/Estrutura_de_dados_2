typedef struct nodo{
    int dado;
    struct nodo* esq;
    struct nodo* dir;
}Nodo;

typedef struct arvbbb{
    Nodo* raiz;
}Arv_bbb;

Nodo* cria();

void imprime_inordem(Nodo* nodo);

Nodo* busca_no(Arv_bbb* raiz, int k);

void insere(Nodo* raiz, Nodo* temp);

Nodo* remove_arvbbb(Nodo* no, int v);

//Liberar a arvore
void arv_libera(Nodo* nodo);

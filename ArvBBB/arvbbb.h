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

int teste_arvore(Nodo* no);

int eh_completa(Nodo* no);

int compare_no(Nodo* pri_arv, Nodo* seg_arv);

int compare_arv(Nodo* pri_arv, Nodo* seg_arv);

int maior_valor(Nodo* no);

int menor_valor(Nodo* no);

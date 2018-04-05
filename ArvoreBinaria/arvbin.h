typedef struct nodo{
    char info;
    struct nodo* esq;
    struct nodo* dir;
}Nodo;

typedef struct arvbin{
    Nodo* raiz;
}Arv_bin;

//Criar uma arvore
Arv_bin* arv_cria(Nodo* arv);

//Criar um no de uma arvore
Nodo* arv_cria_no(char c, Nodo* esq, Nodo* dir);

//Imprimir arvore em preordem
void imprime_preordem(Nodo* nodo);
//Imprimir arvore em inordem
void imprime_inordem(Nodo* nodo);
//Imprimir arvore em postordem
void imprime_postordem(Nodo* nodo);

//Fazer escolha da ordem em que imprimir a arvore
void imprime_escolhendo_ordem(Arv_bin* arv, int n);

//Buscar se um no pertence a arvore
int arv_pertence_no(Nodo* nodo, char c);
int arv_pertence(Arv_bin* arv, char c);

//Liberar a arvore
void arv_libera_no(Nodo* nodo);
void arv_libera(Arv_bin* arv);

//Determinar a altura da arvore
int arv_altura(Nodo* nodo);

//Buscar se um no pertence a arvore
Nodo* busca_no(Nodo* nodo, char c);

//Determinar numero de nos numa arvore
int tamanho_no(Nodo* nodo);
int tamanho(Arv_bin* arv);

//Funcao de espelho
Nodo* espelho_no(Nodo* nodo);
Arv_bin* espelho(Arv_bin* arv);

//Percurso em Largura
void BFS(Arv_bin* arv);

//Impressao da arvore pelo metodo iterativo
void iter_inorderm(Arv_bin* arv);
void iter_preordem(Arv_bin* arv);
void iter_postordem(Arv_bin* arv);



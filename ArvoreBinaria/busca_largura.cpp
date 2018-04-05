#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "arvbin.h"

using namespace std;
//Percurso em LARGURA
void BFS(Arv_bin* arv){
    //Fila, first in first out
	queue<Nodo *> fila;
	//Declarando um no para ajudar a imprimir a arvore
	Nodo *corr = NULL;
    //Coloque a raiz na fila
	fila.push(arv->raiz);

	while(!fila.empty()){
		corr = fila.front(); //Retorna o primeiro elemento na fila
		printf("%c  ", corr->info);
		fila.pop(); //Depois tire o primeiro elemento da fila

		if(corr->esq != NULL)
			fila.push(corr->esq);
		if(corr->dir != NULL)
			fila.push(corr->dir);
	}
}

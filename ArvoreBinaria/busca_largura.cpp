#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "arvbin.h"

using namespace std;
//Percurso em LARGURA
void BFS(Arv_bin* arv){
	queue<Nodo *> fila;
	Nodo *corr = NULL;

	fila.push(arv->raiz);

	while(!fila.empty()){
		corr = fila.front();
		printf("%c  ", corr->info);
		fila.pop();

		if(corr->esq != NULL)
			fila.push(corr->esq);
		if(corr->dir != NULL)
			fila.push(corr->dir);
	}
}

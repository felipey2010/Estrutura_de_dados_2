#include <stdio.h>
#include <stdlib.h>
#include "arvbbb.h"

void limpa_tela(){
    system("cls");
}

int main(){
    //Declaracao da arvore vazia e um nodo temporario
    Nodo* arv = NULL, *temp;
    int op, aux;
    while(1){
        limpa_tela();
        printf("*********************MENU*********************\n");
        printf("1 - Inserir na arvore\n2 - Imprimir Arvore\n0 - Sair\nDigite uma opcao: ");
        scanf("%d", &op);
        limpa_tela();

        if(op == 0){
            printf("Saindo...\n");
            break;
        }
        else if(op == 1){
            printf("Quantos nodos vai precisar?__");
            scanf("%d", &aux);
            int i = 0;
            while(i != aux){
                limpa_tela();
                printf("Digite o %dº valor: ", (i+1));
                temp = cria();
                //Pela primeira vez, insere pois a arvore estara vazia
                if(arv == NULL)
                    arv = temp;
                else
                    insere(arv, temp);
                i++;
            }
        }
        else if(op == 2){
            if(arv == NULL)
                printf("Arvore Vazia!\n");
            else{
                printf("INORDEM: ");
                imprime_inordem(arv);
                printf("\n")
                system("pause");
            }
        }
    }
    arv_libera(arv);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "arvbbb.h"

void limpa_tela(){
    system("cls");
}

int main(){
    //Declaracao da arvore vazia e um nodo temporario
    Nodo* arv = NULL, *temp, *pri_arv = NULL, *seg_arv = NULL;
    int op, aux;
    while(1){
        limpa_tela();
        printf("*********************MENU*********************\n");
        printf("1 - Inserir na arvore\n2 - Imprimir Arvore\n3 - Remover um valor\n4 - Teste de Arvore BBB\n");
        printf("5 - Maior Valor Na Arvore\n6 - Menor Valor Na Arvore\n7 - Eh Arvore Completa?\n8 - Compare 2 Arvores\n0 - Sair\nDigite uma opcao: ");
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
                printf("Digite o -%d- valor: ", (i+1));
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
                printf("\n");
                system("pause");
            }
        }
        else if(op == 3){
            printf("Parte nao implementada!\n");
            system("pause");
        }
        else if(op == 4){
            int teste = teste_arvore(arv);
            if(teste)
                printf("ARVORE BINARIA DE BUSCA\n");
            else
                printf("NAO ARVORE BINARIA DE BUSCA\n");
            system("pause");
        }
        else if(op == 5){
            printf("MAIOR VALOR: %d\n", maior_valor(arv));
            system("pause");
        }
        else if(op == 6){
            printf("MENOR VALOR: %d\n", menor_valor(arv));
            system("pause");
        }
        else if(op == 7){
            if(eh_completa(arv))
                printf("EH ARVORE COMPLETA\n");
            else
                printf("NAO EH ARVORE COMPLETA\n");
            system("pause");
        }
        else if(op == 8){ //Criar 2 arvores para fazer comparacao
            if(pri_arv != NULL)
                arv_libera(pri_arv);
            if(seg_arv != NULL)
                arv_libera(seg_arv);

            printf("***************PRIMEIRA ARVORE***************\n");
            printf("Quantos nodos vai precisar?__");
            scanf("%d", &aux);
            int i = 0;
            while(i != aux){
                limpa_tela();
                printf("Digite o -%d- valor: ", (i+1));
                temp = cria();
                //Pela primeira vez, insere pois a arvore estara vazia
                if(pri_arv == NULL)
                    pri_arv = temp;
                else
                    insere(pri_arv, temp);
                i++;
            }
            printf("***************SEGUNDA ARVORE***************\n");
            printf("Quantos nodos vai precisar?__");
            scanf("%d", &aux);
            i = 0;
            while(i != aux){
                limpa_tela();
                printf("Digite o -%d- valor: ", (i+1));
                temp = cria();
                //Pela primeira vez, insere pois a arvore estara vazia
                if(seg_arv == NULL)
                    seg_arv = temp;
                else
                    insere(seg_arv, temp);
                i++;
            }
            printf("**************COMPARANDO ARVORE**************\n");
            if(compare_arv(pri_arv, seg_arv))
                printf("ARVORES IGUAIS!\n");
            else
                printf("ARVORES DIFERENTES!\n");
            system("pause");
        }
    }
    arv_libera(arv);
    return 0;
}

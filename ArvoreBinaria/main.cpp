#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include "arvbin.h"

using namespace std;

//Funcao para limpar a tela
void limp_tela(){
    system("cls");
}

int main(){
    int esc, op;
    //Criacao da arvore
    Arv_bin* arv = arv_cria(arv_cria_no('a',
                                        arv_cria_no('b', NULL,arv_cria_no('d', NULL, NULL)),
                                                arv_cria_no('c', arv_cria_no('e', NULL, NULL), arv_cria_no('f', NULL, NULL))
                                        )
                            );
    while(1){ //Menu
        limp_tela();
        printf("1-Imprimir Arvore\n2-Pertence a Arvore\n3-Altura\n4-Buscar No\n5-Tamanho da arvore\n6-Espelhar Arvore\n7-Percorre em Largura\n8-Opcao Iterativa\n0-Sair\nDigite__");
        scanf("%d", &op);

        if(op == 1){ //Opcao para imprimir arvore em ordem
            limp_tela();
            while(1){
                printf("\n**************ESCOLHE A ORDEM PARA IMPRIMIR A ARVORE**************\n1-preordem\n2-inordem\n3-postordem\n0-Sair\nDigite:__");
                scanf("%d", &esc);
                if(esc == 0) //breakpoint quando esc for zero
                    break;
                else
                    imprime_escolhendo_ordem(arv, esc);
            }
        }
        else if(op == 2){ //Buscar se caracter pertence a arvore
            limp_tela();
            getchar(); //capturar ENTER
            char ch;
            printf("Digite caracter para buscar: ");
            scanf("%c", &ch);

            arv_pertence(arv, ch)?printf("\'%c' pertence a arvore\n", ch):printf("\'%c' nao pertence a arvore\n", ch);

            system("pause");
        }
        else if(op == 3){ //Determinar a altura da arvore
            limp_tela();
            int alt = arv_altura(arv->raiz);
            printf("Altura da arvore: %d\n", alt);

            system("pause");
        }
        else if(op == 4){ //Buscar o no que caracter pertene na arvore
            limp_tela();
            char ch;
            printf("Digite caracter para buscar o no: ");
            scanf(" %c", &ch);
            Nodo* no = busca_no(arv->raiz, ch);

            if(no == NULL)
                printf("'%c' NAO ENCONTRADO EM NENHUM NO!\n", ch);

            system("pause");
        }
        else if(op == 5){
            limp_tela();
            printf("Tamanho: %d\n", tamanho(arv));

            system("pause");
        }
        else if(op == 6){
            limp_tela();
            Arv_bin* nova_arv = espelho(arv);
            while(1){
                printf("\n**************ESCOLHE A ORDEM PARA IMPRIMIR A ARVORE ESPELHADA**************\n1-preordem\n2-inordem\n3-postordem\n4-Largura\n0-Sair\nDigite:__");
                scanf("%d", &esc);

                if(esc < 0 || esc > 4){
                    limp_tela();
                    printf("ESCOLHA INVALIDA!");
                }
                else if(esc == 0) //breakpoint quando esc for zero
                    break;
                else if(esc == 4){
                    limp_tela();
                    printf("LARGURA: ");
                    BFS(nova_arv);
                }
                else
                    imprime_escolhendo_ordem(nova_arv, esc);
            }
        }
        else if(op == 7){
            limp_tela();
            printf("*******************IMPRIMINDO ARVORE EM LARGUAR*******************\n");
            //Funcao para percorrer e imprimir a arvore em largura
            BFS(arv);

            printf("\n");
            system("pause");
        }
        if(op == 8){ //Opcao para imprimir arvore em ordem usando iteratividade
            limp_tela();
            while(1){
                printf("\n**************ESCOLHE A ORDEM PARA IMPRIMIR A ARVORE**************\n1-preordem iterativa\n2-inordem iterativa\n3-postordem iterativa\n0-Sair\nDigite:__");
                scanf("%d", &esc);
                if(esc == 0) //breakpoint quando esc for zero
                    break;
                else if(esc == 1)
                    iter_preordem(arv);
                else if(esc == 2)
                    iter_inorderm(arv);
                else if(esc == 3)
                    iter_postordem(arv);
                else
                    printf("ESCOLHA INVALIDA!");
            }
        }
        else if(op == 0)
            break;
        else
            printf("ESCOLHA INVALIDA!\n");
    }


    arv_libera(arv);

    return 0;
}


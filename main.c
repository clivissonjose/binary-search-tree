#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

int main(){

   arvore a = NULL;

   while(1){

    int opcao;
    int valor;
    scanf("%d", &opcao);
    switch(opcao) {
        case 1: 
            scanf("%d", &valor);
            a = inserir(a, valor);
            break;
        case 2: 
            preOrder(a);
            printf("\n");
            break;
        case 3: 
            scanf("%d", &valor);
            a = remover(a, valor);
            break;
        case 99:
            exit(0);
            break;
    }
   }

    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include "BST.h"

int main(){

    arvore a = NULL;
    a = inserir(a,50);
    a = inserir(a,20);
    a = inserir(a,30);
    a = inserir(a,40);
    a = inserir(a,60); 
    a = inserir(a, 3);

    printf("Pre ordem: \n");
    preOrder(a);

    printf("\nEm ordem: \n");
    inOrder(a);

    printf("\npos ordem: \n");
    posOrder(a);

    return 0;
}
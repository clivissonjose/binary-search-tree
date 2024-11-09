#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

//funcao inserir recebe como par�metro o ponteiro para a raiz de uma �rvore,
//o valor a ser inserido e RETORNA o ponteiro para a (sub)�rvore resultante

arvore inserir(arvore raiz, int valor){

    //caso base - inst�ncia mais simples do problema
    //inserir em uma �rvore vazia
   if(raiz == NULL){
     arvore novo = (arvore) malloc(sizeof(no));

     novo->valor = valor;
     novo->esq = NULL;
     novo->dir = NULL;

     return novo;
   }else{
      
      if(valor > raiz->valor){
        raiz->dir =  inserir(raiz->dir, valor);
      }else{
        raiz->esq = inserir(raiz->esq, valor);
      }

      return raiz;
   }
}


void preOrder(arvore raiz){

  if(raiz){

    printf("%d ", raiz->valor);
    preOrder(raiz->esq);
    preOrder(raiz->dir);

  }

}

void inOrder(arvore raiz){

  if(raiz){
    inOrder(raiz->esq);
    printf("%d ", raiz->valor);
    inOrder(raiz->dir);
  }
}

void posOrder(arvore raiz){

  if(raiz){
    inOrder(raiz->esq);
    inOrder(raiz->dir);
    printf("%d ", raiz->valor);
  }
}
#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

//funcao inserir recebe como parametro o ponteiro para a raiz de uma arvore,
//o valor a ser inserido e RETORNA o ponteiro para a (sub)arvore resultante

arvore inserir(arvore raiz, int valor){

    // caso base - instancia mais simples do problema
    // inserir em uma arvore vazia
   if(raiz == NULL){
     arvore novo = (arvore) malloc(sizeof(no));

     novo->valor = valor;
     novo->esq = NULL;
     novo->dir = NULL;

     return novo;
   }else{
      
      if(valor >= raiz->valor){
        raiz->dir =  inserir(raiz->dir, valor);
      }else{ // valor < raiz->valor
        raiz->esq = inserir(raiz->esq, valor);
      }

      return raiz;
   }
}

arvore maiorElemento(arvore raiz){
  arvore temp = raiz;

  if(temp->dir == NULL)
     return NULL;
  while(temp->dir != NULL ){
    temp = temp->dir; 
  }

  return temp;
}

arvore remover(arvore raiz, int valor){
  if(raiz == NULL){
    return NULL;
  }else{
    if(raiz->valor == valor){
       
       //caso 1:  O valor é uma folha 
       if(raiz->esq == NULL && raiz->dir == NULL){
          free(raiz);
          return NULL;
       }

       //Caso 2: raiz possui exatamente um filho a direita
       
       if(raiz->dir != NULL && raiz->esq == NULL){
          arvore raizResultante = raiz->dir;
          free(raiz);
          return raizResultante;
       }

       // Possui exatamante um filho a esquerda

      if(raiz->esq != NULL && raiz->dir == NULL){
        arvore raizResultante = raiz->esq;
        free(raiz);
        return raizResultante;
      }

      // Raiz possui dois filhos
      if(raiz->dir != NULL && raiz->esq != NULL){
        raiz->valor = maiorElemento(raiz->esq)->valor;
        raiz->esq = remover(raiz->esq, raiz->valor);
        return raiz;
      }

    }else{

      // Se o valor ainda não for encontrado
      // Procurar o elemento 

      if(valor > raiz->valor){
        raiz->dir = remover(raiz->dir, valor);
      }else{
        raiz->esq = remover(raiz->esq, valor);
      }

      return raiz;

    }
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
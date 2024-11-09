#ifndef BST_H
#define BST_H

typedef struct no {
int valor;
struct no *esq, *dir;
} no;

typedef no *arvore;

arvore inserir (arvore raiz, int valor);
void preOrder(arvore raiz);
void inOrder(arvore raiz);
void posOrder(arvore raiz);
#endif
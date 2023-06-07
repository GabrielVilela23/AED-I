#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct noArvoreBB {
    int valor;
    struct noArvoreBB *esq;
    struct noArvoreBB *dir;
};
typedef struct noArvoreBB tipoABB;

void inicializa(tipoABB *arvoreAux, int valor){
    arvoreAux->valor = valor;
    arvoreAux->esq = NULL;
    arvoreAux->dir = NULL; 
}

tipoABB *criaNo (int valor){
    tipoABB *novo = malloc(sizeof(tipoABB));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void insereNo(tipoABB *no, int valor) {
  if (valor < no->valor) {
    if (no->esq == NULL) {
      no->esq = criaNo(valor);
      return;
    } else {
      insereNo(no->esq, valor);
    }
  } else {
    if (no->dir == NULL) {
      no->dir = criaNo(valor);
      return;
    } else {
      insereNo(no->dir, valor);
    }
  }
}

void printPre(tipoABB *arvoreAux) {
  printf(" %d", arvoreAux->valor);
  if (arvoreAux->esq != NULL) {
    printPre(arvoreAux->esq);
  }
  if (arvoreAux->dir != NULL) {
    printPre(arvoreAux->dir);
  }
}

void printIn(tipoABB *arvoreAux) {
  if (arvoreAux->esq != NULL) {
    printIn(arvoreAux->esq);
  }
  printf(" %d", arvoreAux->valor);
  if (arvoreAux->dir != NULL) {
    printIn(arvoreAux->dir);
  }
}

void printPos(tipoABB *arvoreAux) {
  if (arvoreAux->esq != NULL) {
    printPos(arvoreAux->esq);
  }
  if (arvoreAux->dir != NULL) {
    printPos(arvoreAux->dir);
  }
  printf(" %d", arvoreAux->valor);
}

int main() {
  tipoABB arvore;
  int casos, linhas, valor;
  scanf("%d", &casos);
  for (int i = 0; i < casos; i++) {
    scanf("%d", &linhas);
    scanf("%d", &valor);
    inicializa(&arvore, valor);
    for (int j = 0; j < linhas - 1; j++) {
      scanf("%d", &valor);
      insereNo(&arvore, valor);
    }
    printf("Case %d:\nPre.:", i + 1);
    printPre(&arvore);
    printf("\nIn..:");
    printIn(&arvore);
    printf("\nPost:");
    printPos(&arvore);
    printf("\n\n");
  }
  return 0;
}
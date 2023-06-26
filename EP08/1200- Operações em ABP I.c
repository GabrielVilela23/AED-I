#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//define estrutura da arvore
struct noArvoreBB {
  char valor;
  struct noArvoreBB *esq;
  struct noArvoreBB *dir;
};
typedef struct noArvoreBB tipoABB;


void inicializa(tipoABB *arvoreAux, char valor) {
  arvoreAux->valor = valor;
  arvoreAux->esq = NULL;
  arvoreAux->dir = NULL;
}

tipoABB *criaNo(char valor) {
  tipoABB *novo = malloc(sizeof(tipoABB));
  novo->valor = valor;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

void insereNo(tipoABB *no, char valor) {
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
  printf("%c", arvoreAux->valor);
  if (arvoreAux->esq != NULL) {
    printf(" ");
    printPre(arvoreAux->esq);
  }
  if (arvoreAux->dir != NULL) {
    printf(" ");
    printPre(arvoreAux->dir);
  }
}

void printIn(tipoABB *arvoreAux) {
  if (arvoreAux->esq != NULL) {
    printIn(arvoreAux->esq);
    printf(" ");
  }
  printf("%c", arvoreAux->valor);
  if (arvoreAux->dir != NULL) {
    printf(" ");
    printIn(arvoreAux->dir);
  }
}

void printPos(tipoABB *arvoreAux) {
  if (arvoreAux->esq != NULL) {
    printPos(arvoreAux->esq);
    printf(" ");
  }
  if (arvoreAux->dir != NULL) {
    printPos(arvoreAux->dir);
    printf(" ");
  }
  printf("%c", arvoreAux->valor);
}

int procuraValor(tipoABB *arvore, char valor) {
  if (arvore->valor == valor) {
    return 1;
  } else {
    if (arvore->esq != NULL && valor < arvore->valor) {
      return procuraValor(arvore->esq, valor);
    }
    if (arvore->dir != NULL && valor > arvore->valor) {
      return procuraValor(arvore->dir, valor);
    }
    return 0;
  }
}


int main() {
  tipoABB arvore;
  int linhas;
  char op[50], valor;
  int ini = 0;
  scanf("%s", op);
  while (1) {
    if (!strcmp(op, "I")) {
      scanf("%c", &valor);
      scanf("%c", &valor);
      if (!ini) {
        ini++;
        inicializa(&arvore, valor);
      } else {
        insereNo(&arvore, valor);
      }
    } else if (!strcmp(op, "P")) {
      scanf("%c", &valor);
      scanf("%c", &valor);
      if (procuraValor(&arvore, valor)) {
        printf("%c existe\n", valor);
      } else {
        printf("%c nao existe\n", valor);
      }
    } else if (!strcmp(op, "INFIXA")) {
      printIn(&arvore);
      printf("\n");
    } else if (!strcmp(op, "PREFIXA")) {
      printPre(&arvore);
      printf("\n");
    } else if (!strcmp(op, "POSFIXA")) {
      printPos(&arvore);
      printf("\n");
    }
    scanf("%s", op);
    if (feof(stdin)) {
      break;
    }
  }

  return 0;
}
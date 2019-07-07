#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct noLista {
  int chave;
  struct noLista* proxLista;
} lista;

typedef struct ticket {
  int nome;
  struct noLista* inicioLista;
} tickets;


lista* novoEncadeado(int chave) {
  lista* no = (lista*)malloc(sizeof(lista));

  no->chave = chave;
  no->proxLista = NULL;

  return no;
}

lista* insere(lista* no, int chave) {

   no->proxLista = novoEncadeado(chave);

  return no;
}

tickets* insereNoTicket(tickets* novoTicket, int chave) {
   printf("entrou\n");
   novoTicket-> nome = 2;
   novoTicket->inicioLista = novoEncadeado(chave);

  return novoTicket;
}

int main(void) {
  tickets* a;
  a = (tickets*)malloc(sizeof(tickets));
  a = insereNoTicket(a, 7);
  //a = abb_insere(a, 4);
  //a = abb_insere(a, 9);

  //showTree(a);
  printf("\n");
  //raiz = abb_busca(a, 7);
  printf("passou da busca\n");
  
 
  

  return 0;
}

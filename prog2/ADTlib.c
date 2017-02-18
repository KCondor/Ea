#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ADTlib.h"

//Questa libreria contiene gli abstact data type visti a lezione.

/////////////////////////////////////////////////////////////
/*                          LISTE                          */
/////////////////////////////////////////////////////////////

int vuota(Lista l)
{
  return l == NULL;
}

void nuova_lista(Lista *l)
{
  *l = NULL;
}

void inserimento_testa(Lista *l, int numero)
{
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = numero;
  aux->next = *l;
  *l = aux;
}

void inserimento_ordinato(Lista *l, int numero)
{
  Nodo **p = l;
  while (*p && (*p)->dato < numero)
    p = &((*p)->next);
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = numero;
  aux->next = *p;
  *p = aux;
}

void inserimento_coda(Lista *l, int numero)
{
  Nodo **p = l;
  while (*p)
    p = &((*p)->next);
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  aux->dato = numero;
  aux->next = NULL;
  *p = aux;
}

void inversa(Lista l1, Lista *l2)
{
  while (l1)
  {
    inserimento_testa(l2, l1->dato);
    l1 = l1->next;
  }
}

int ricerca(Lista l, int numero)
{
  while (l != NULL)
  {
    if (l->dato == numero)
      return 1;
    l = l->next;
  }
  return 0;
}

void elimina(Lista *l, int numero)
{
  Nodo **p = l, *aux;
  while (*p)
  {
    if ((*p)->dato == numero)
    {
      aux = *p;
      *p = aux->next;
      free(aux);
    }
    else
      p = &((*p)->next);
  }
}

int lunghezza(Lista l)
{
  int i = 0;
  Nodo *n = l;
  while (n)
  {
    i++;
    n = n->next;
  }
  return i;
}

void stampa(Lista l)
{
  Nodo *n = l;
  while (n)
  {
    printf("%d ", n->dato);
    n = n->next;
  }
  printf("\n");
}

void svuota(Lista *l)
{
  Nodo *p;
  while (*l)
  {
    p = *l;
    *l = (*l)->next;
    free(p);
  }
}

void concatena(Lista *l1, Lista l2)
{
  Nodo **p = l1;
  while (*p)
    p = &((*p)->next);
  *p = l2;
}

void somma(Lista l1, Lista l2, Lista *l3)
{
  while (l1)
  {
    inserimento_coda(l3, l1->dato);
    l1 = l1->next;
  }
  while (l2)
  {
    inserimento_coda(l3, l2->dato);
    l2 = l2->next;
  }
}

void somma_efficiente(Lista l1, Lista l2, Lista *l3)
{
  Nodo **p = l3;
  while (l1)
  {
    *p = (Nodo *)malloc(sizeof(Nodo));
    (*p)->dato = l1->dato;
    (*p)->next = NULL;
    p = &((*p)->next);
    l1 = l1->next;
  }
  while (l2)
  {
    *p = (Nodo *)malloc(sizeof(Nodo));
    (*p)->dato = l2->dato;
    (*p)->next = NULL;
    p = &((*p)->next);
    l2 = l2->next;
  }
}

/////////////////////////////////////////////////////////////
/*                          QUEUE                          */
/////////////////////////////////////////////////////////////

Coda newQueue()
{
  Coda c;
  c.first = NULL;
  c.last = NULL;
  return c;
}

int isEmptyQueue(Coda c)
{
  return c.first == NULL;
}

void enqueue(Coda *c, char *s)
{
  Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
  strcpy(aux->dato, s);
  aux->next = NULL;
  if (isEmptyQueue(*c))
    c->first = aux;
  else
    c->last->next = aux;
  c->last = aux;
}

void dequeue(Coda *c, char *s)
{
  Nodo *temp;
  if (isEmptyQueue(*c))
  {
    printf("Errore: coda vuota\n");
    exit(-1);
  }
  temp = c->first;
  c->first = temp->next;
  if (c->first == NULL)
    c->last = NULL;
  strcpy(s, temp->dato);
  free(temp);
}

void print(Coda c)
{
  Nodo *p = c.first;
  printf("\n");
  while (p)
  {
    printf("%s\n", p->dato);
    p = p->next;
  }
  printf("\n");
}

/////////////////////////////////////////////////////////////
/*                          PILA                           */
/////////////////////////////////////////////////////////////

void nuova_Pila(Pila *p)
{
  p->nElem = 0;
}

int vuota_Pila(Pila p)
{
  return p.nElem == 0;
}

int piena_Pila(Pila p)
{
  return p.nElem == NMAX;
}

void push(Pila *p, float elem)
{
  if (piena_Pila(*p))
  {
    printf("Errore: pila piena\n");
    exit(-10);
  }
  p->dati[p->nElem] = elem;
  (p->nElem)++;
}

float pop(Pila *p)
{
  float f;
  if (vuota_Pila(*p))
  {
    printf("Errore: pila vuota\n");
    exit(-11);
  }
  f = p->dati[p->nElem - 1];
  (p->nElem)--;
  return f;
}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int dato;
  struct node *sgte;
}*nodo, tipoNodo;

typedef struct{
  nodo top;
  nodo root;
}*cola, tipoCola;

nodo crearNodo(int);
cola crearCola();
void encolar(int, cola);
int desencolar(cola);
int empty(cola);
int size(cola);
int top(cola);

int main()
{
  
  return 0;
}

nodo crearNodo(int valor)
{
  nodo item = (nodo) malloc(sizeof(tipoNodo));
  item->dato = valor;
  item->sgte = NULL;
  return item;
}

cola crearCola()
{
  cola Queue = (cola) malloc(sizeof(tipoCola));
  Queue->top = NULL;
  Queue->root = NULL;
  return Queue;
}

void enqueue(int valor, cola Queue)
{ 
  if(Queue -> root == NULL){
    nodo elemento = crearNodo(valor);
    Queue -> top = elemento;
    Queue -> root = elemento;
  }else{
    nodo elemento = crearNodo(valor);
    elemento -> sgte = NULL;
    Queue -> top -> sgte = elemento;
    Queue -> top = elemento;
  }
}

int dequeue(cola Queue)
{ 
  int info;
  if (!empty(Queue))
  {
    nodo item = Queue->root;
    info = item->dato;
    Queue->root = item->sgte;
    free(item);
  }else{
    info = -123;
  }
  return info;
}

int empty(cola Queue)
{
  return(Queue->root == NULL);
}

int size(cola Queue){
  int contador = 0;
  nodo actual = Queue->root;
  while (actual != NULL){
    contador++;
    actual = actual->sgte;
  }
  return contador;
}
*/
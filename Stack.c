/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  short dato;
  struct node *sgte;
}*nodo, tipoNodo;

typedef struct{
  nodo top;
}*pila, tipoPila;

nodo crearNodo(short);
pila crearPila();
void push(short, pila);
short pop(pila);
int empty(pila);
int size(pila);
short top(pila);

//Constructores

nodo crearNodo(short valor)
{
  nodo item = (nodo) malloc(sizeof(tipoNodo));
  item->dato = valor;
  item->sgte = NULL;
  return item;
}

pila crearPila()
{
  pila Stack = (pila) malloc(sizeof(tipoPila));
  Stack->top = NULL;
  return Stack;
}

//Funciones Básicas de los Stacks

void push(short valor, pila Stack)
{
  nodo elemento = crearNodo(valor);
  elemento->sgte = Stack->top;
  Stack->top = elemento;
}

short pop(pila Stack)
{
  short info;
  nodo item = Stack->top;
  info = item->dato;
  Stack->top = item->sgte;
  free(item);
  return info;
}

int empty(pila Stack)
{
  return(Stack->top == NULL);
}

int size(pila Stack){
  int contador = 0;
  nodo actual = Stack->top;
  while (actual != NULL){
    contador++;
    actual = actual->sgte;
  }
  return contador;
}
*/
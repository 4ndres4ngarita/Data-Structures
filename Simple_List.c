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
  nodo last;
  nodo first;
}*lista, tipoLista;


nodo crearNodo(int);//done
lista crearLista();//done
void insert(int, int, lista);//done
void insertfront(int, lista);//done
void insertlast(int, lista);//done
int delete(int, lista);//done (creo)
int deletefront(lista);//done
int deletelast(lista);//done (creo)
int empty(lista);//done
int size(lista);//done
int first(lista);//done
int last(lista);//done

void imprimir(){
  printf("Impreso :D\n");
}

int main()
{
  
  lista datos = crearLista();
  int bit; 
  bit = 1;
  while (bit > 0){
    scanf("%d", &bit);
          
    if (bit > 0) {
      insertlast(bit, datos);
      imprimir();
    }
  }
  int pos;
  bit=0;
  while (bit > 0 || pos > 0){
    //scanf("%d", &bit);
    scanf("%d", &pos);     
    if (pos > 0) {
      delete(pos, datos);
    }
  }
  int n;n=0;
  while(!empty(datos)){
    n+=1;
    printf(" valor %d: %d \n", n, deletefront(datos));
  }

  return 0;
}

nodo crearNodo(int valor){
  nodo item = (nodo) malloc(sizeof(tipoNodo));
  item->dato = valor;
  item->sgte = NULL;
  return item;
}

lista crearLista(){
  lista List = (lista) malloc(sizeof(tipoLista));
  List->last = NULL;
  List->first = NULL;
  return List;
}

void insert(int valor, int posicion, lista List){

  int info;
  if (!empty(List)){ 

    if(posicion == 1){
      insertfront( valor, List);
    }else if(posicion == (size(List)+1)){
      insertlast( valor, List);
    }else if(posicion == 2){
      nodo item = List -> first;
      nodo nodoAinsertar = crearNodo(valor);
      nodoAinsertar -> sgte = item -> sgte;
      item -> sgte = nodoAinsertar;
      
    }else if(posicion <= size(List)){
        
      nodo item = List -> first;
      short n=1;
      while(n != (posicion-1)){
        n++;
        item = item -> sgte;
      }
      nodo nodoAinsertar = crearNodo(valor);
      nodoAinsertar -> sgte = item -> sgte;
      item -> sgte = nodoAinsertar;

    }else{
      printf("Error :(\n");
    }
  }else{
    printf("Error :(\n");
  }
}

void insertfront(int valor, lista List){ 
  if(empty(List)){
    nodo elemento = crearNodo(valor);
    List -> last = elemento;
    List -> first = elemento;
  }else{
    nodo elemento = crearNodo(valor);
    elemento -> sgte = List -> first;
    List -> first = elemento;
  }
}

void insertlast(int valor, lista List){ 
  if(empty(List)){
    nodo elemento = crearNodo(valor);
    List -> last = elemento;
    List -> first = elemento;
  }else{
    nodo elemento = crearNodo(valor);
    List -> last -> sgte = elemento;
    List -> last = elemento;
  }
}

int delete(int posicion, lista List){

  int info;
  if (!empty(List)){ 

    if(posicion == 1){
      info = deletefront(List);
    }else if(posicion == size(List)){
      info = deletelast(List);
    }else if(posicion == 2){
      nodo item = List -> first;

      info = item -> sgte -> dato;//paso 1.seleccciono el dato del nodo a eliminar

      nodo nodoAborrar = item -> sgte;
      item -> sgte = item -> sgte -> sgte;//paso 2.apunto al que apuntaba el que va a ser eliminado
      
      free(nodoAborrar);//paso 3. elimino el nodo
    }else if(posicion <= size(List)){

      nodo item = List -> first;
      short n=1;
      while(n != (posicion-1)){//paso 0.llego una posicion anterior
        n++;
        item = item -> sgte;
      }

      info = item -> sgte -> dato;//paso 1.seleccciono el dato del nodo a eliminar

      nodo nodoAborrar = item -> sgte;
      item -> sgte = item -> sgte -> sgte;//paso 2.apunto al que apuntaba el que va a ser eliminado
      
      free(nodoAborrar);//paso 3. elimino el nodo

    }else{
      info = -123;
    }
  }else{
    info = -123;
  }

  return info;
}

int deletefront(lista List){ 
  int info;
  if (!empty(List))
  { 
    
    nodo item = List -> first;
    info = item -> dato;
    
    if(List -> first == List -> last){
        List -> first = NULL;
        List -> last = NULL;
    }else{
        List -> first = item -> sgte;
    }
    
    free(item);
    
  }else{
    info = -123;
  }
  return info;
}

int deletelast(lista List){
  int info;
  if (!empty(List))
  {
    nodo item = List -> first;
    
    if(List -> first == List -> last){
        
        info = item -> dato;
        List -> first = NULL;
        List -> last = NULL;
        free(item);
       
    }//else if(List -> first -> sgte == List -> last){
        //info = List -> last -> dato;
        //List -> last = List -> first;
        //free(item -> sgte);
        
    //}
    else{
      int n=1;


      while(item -> sgte != List -> last){
        n++;
        item = item -> sgte;
      }
      info = item -> sgte -> dato;
      List->last = item;
      free(item -> sgte);
    }
    
    
  }else{
    info = -123;
  }

  return info;
}

int empty(lista List){ return (List -> first == NULL && List -> last == NULL);
}

int size(lista List){
  int contador = 0;
  nodo actual = List->first;
  while (actual != NULL){
    contador++;
    actual = actual->sgte;
  }
  return contador;
}

int first(lista List){
  return List -> first -> dato;
}

int last(lista List){
  return List -> last -> dato;
}
*/
#include <stdio.h>
#include <stdlib.h>

//#include "Node.c"
//#include "Stack.c"
int Turn = 1;

typedef struct node{
  int dato;
  int vidas;
  struct node *sgte;
  struct node *ant;
}*nodo, tipoNodo;

typedef struct{
  nodo last;
  nodo first;
}*lista, tipoLista;


nodo crearNodo(int);//done
lista crearLista();//done
void insert(int, int, lista);//
void insertfront(int, lista);//done
void insertlast(int, lista);//done
int delete(int, lista);//done(creo)
int deletefront(lista);//done
int deletelast(lista);//done
int empty(lista);//done
int size(lista);//done
int first(lista);//done
int last(lista);//done

void girar(int, lista);

void imprimir(){
  printf("Impreso :D\n");
}

int main(){
  lista List = crearLista();
  int bit;
  do{
    scanf("%d",&bit);
    if(bit != 0){
        insertlast( bit, List);
    }
  }while(bit != 0);imprimir();
  printf("size(List) = %d \n",size(List));
  do{
    scanf("%d",&bit);
    girar(bit, List);
  }while(size(List) > 1);
  printf("gana el jugador %d", deletefront(List));
  return 0;
}

nodo crearNodo(int valor){
  nodo item = (nodo) malloc(sizeof(tipoNodo));
  item->dato = valor;
  item->vidas = 2;
  item->sgte = NULL;
  item->ant = NULL;
  return item;
}

lista crearLista(){
  lista List = (lista) malloc(sizeof(tipoLista));
  List->last = NULL;
  List->first = NULL;
  return List;
}

void insert(int valor, int posicion, lista List){

  if(empty(List)){
    if (posicion == 1){
      insertlast( valor, List);
    }else{
      printf("Error :(\n[la lista esta vacia, pos != 1]\n");
    }
  }else{
    if(posicion == 1){
      insertfront(valor, List);//funciona
    }else
    if ( posicion <= size(List) ){
      int n,tam;
      nodo item = List -> first;
      n = 1;tam = size(List);
      while( n != posicion){
        n++;
        item = item -> sgte;
      }
      nodo nodoAinsertar = crearNodo( valor);

      nodoAinsertar -> ant = item -> ant;
      item -> ant -> sgte = nodoAinsertar;
      item -> ant = nodoAinsertar;
      nodoAinsertar -> sgte = item;

    }else if(posicion == (size(List) + 1)){
      insertlast(valor, List);//funciona
    }else{
      printf("Error :(\n[el tamano supera a %d]\n", (size(List)+1));//funciona
    }
 }
}

void insertfront(int valor, lista List){ 
  if(empty(List)){
    nodo elemento = crearNodo(valor);
    List -> last = elemento;
    List -> first = elemento;
    elemento->ant=List->last;
    elemento->sgte=List->last;
  }else{
    nodo elemento = crearNodo(valor);
    elemento -> sgte = List -> first;
    List -> first -> ant = elemento;
    List -> first = elemento;
    elemento -> ant = List -> last;
  }
}

void insertlast(int valor, lista List){ 
  if(empty(List)){
    nodo elemento = crearNodo(valor);
    List -> last = elemento;
    List -> first = elemento;
    elemento->ant=List->last;
    elemento->sgte=List->last;
  }else{
    nodo elemento = crearNodo(valor);
    elemento -> sgte = List -> first;
    elemento -> ant = List -> last;
    List -> last -> sgte = elemento;
    List -> last = elemento;
  }
}

int delete(int posicion, lista List){

  int info;
  if (!empty(List) && List -> first != List -> last){ 

    if(posicion == 1){
      info = deletefront(List);
    }else if(posicion == size(List)){
      info = deletelast(List);
    }else if(posicion == 2){
      nodo item = List -> first;

      info = item -> sgte -> dato;

      nodo nodoAborrar = item -> sgte;
      item -> sgte = nodoAborrar -> sgte;
      item -> sgte -> ant = item;
      
      free(nodoAborrar);//paso 3. elimino el nodo
    }else if(posicion < size(List)){

      nodo item = List -> first;
      short n=2;
      while(n != (posicion)){
        n++;
        item = item -> sgte;
      }

      info = item -> sgte -> dato;

      nodo nodoAborrar = item -> sgte;
      item -> sgte = nodoAborrar -> sgte;
      item -> sgte -> ant = item;
      
      free(nodoAborrar);

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
        List -> first = List -> first -> sgte;
        List -> first -> ant = List -> last;
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
    nodo item = List -> last;
    
    if(List -> first == List -> last){
        
        info = item -> dato;
        List -> first = NULL;
        List -> last = NULL;
        free(item);  
    }
    else{
        
        info = item -> dato;
        List -> last = List -> last -> ant;
        List -> last -> sgte = List -> first;
        free(item);
    }
    
  }else{
    info = -123;
  }
  return info;
}

int empty(lista List){ return (List -> first == NULL && List -> last == NULL);
}

/*
* Code wrote by virtualdog582:
* Credits of NP: Andres Angarita
* e-mail: aajangarita@gmail.com
*
* citar merito :D
*
*/

int size(lista List){
    int contador = 0;
    if(!empty( List)){
        contador = 1;
        
        if(List -> first != List -> last){
            nodo actual = List -> first;
            while (actual != List -> last){
                contador++;
                actual = actual->sgte;
            }
        }    
    }
  
    return contador;
}

int first(lista List){
  return List -> first -> dato;
}

int last(lista List){
  return List -> last -> dato;
}

void girar(int n, lista Lista){
  nodo item = Lista -> first;
  for (int i = 1; i < Turn; i++){
    item = item -> sgte;
  }
  for (int i = 0; i < n; i++){
    item = item -> sgte;
    if (Turn == size(Lista)){
      Turn = 1;
    }else{
      Turn += 1;
    }
  }
  item -> vidas -= 1;
  printf("el jugador %d %d perdio una vida\n", item->dato, Turn);
  if (item -> vidas == 0){
    int loser = delete(Turn, Lista);
    printf("salió el jugador %d\n", loser);
  }
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int dato;
  struct node *izq;
  struct node *der;
}*nodo, tipoNodo;

typedef struct{
  nodo root;
}*arbol, tipoArbol;

nodo crearNodo(int);
arbol crearArbol();
nodo SystemBuild(arbol);
void preOrder(nodo);
void inOrder(nodo);
void posOrder(nodo);

int main(){
	arbol Arbol = crearArbol();
	SystemBuild( Arbol);
	
	/*
	printf("Pre-Orden:\t");
	preOrder( Arbol -> root);
	*/
	
	/*
	printf("\nIn-Orden:\t");
	inOrder( Arbol -> root);
	*/
	
	/*
	printf("\nPos-Orden:\t");
    posOrder( Arbol -> root);
    */
	

	return 0;
}

nodo crearNodo(int valor)
{
  nodo item = (nodo) malloc(sizeof(tipoNodo));
  item->dato = valor;
  item->izq = NULL;
  item->der = NULL;
  return item;
}

arbol crearArbol()
{
  arbol Tree = (arbol) malloc(sizeof(tipoArbol));
  Tree->root = NULL;
  return Tree;
}

nodo SystemBuild(arbol Tree)
{
	int bit;
	scanf("%d", &bit);
	if (bit != 0)
	{
		nodo item = crearNodo( bit);
		Tree -> root = item;
		printf("raiz creado\n");
		arbol arbolIzq = crearArbol();
		SystemBuild( arbolIzq);

		if (arbolIzq -> root != NULL)
		{
			Tree -> root -> izq = arbolIzq -> root;
			printf("arbol izquierdo creado\n");
		}

		arbol arbolDer = crearArbol();
		SystemBuild( arbolDer);

		if (arbolDer -> root != NULL)
		{
			Tree -> root -> der = arbolDer -> root;
			printf("arbol derecho creado\n");
		}
	}
}

/*
* Code wrote by virtualdog582:
* Credits of NP: Andres Angarita
* e-mail: aajangarita@gmail.com
*	thanks to 1u15d33ng ;)
*
*/

void preOrder( nodo root)
{
    if(root != NULL)
    {   
        printf("%d\t", root->dato);
        preOrder(root->izq);
        preOrder(root->der);
    }
}

void inOrder( nodo root)
{   
    if (root != NULL)
    {
		inOrder( root -> izq);
		printf("%d\t", root -> dato);
		inOrder( root -> der);
		
	}
}

void posOrder( nodo root)
{   
    if (root != NULL)
    {
		posOrder(root -> izq);
		posOrder(root -> der);
		printf("%d\t", root -> dato);
	}
}

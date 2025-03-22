#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

   for (int k = 1 ; k <= 10 ; k++)
   {
      int* CopiaK = (int*) malloc(sizeof(int));
      *CopiaK = k;
      pushBack(L,CopiaK);

      }

   return L;
}


/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

   int suma = 0;

   void* elemento = first(L);

   while (elemento != NULL)
   {
      int valor = *((int*)elemento);
      suma += valor;

      elemento = next(L);
   }
   


   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
    int* aux = first(L);

   while (aux != NULL)
   {
      if (*aux == elem)
      {
         popCurrent(L);
         
      }
      aux = next(L);
   }
   

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* pilaAux = create_stack();
   while(top(P1) != NULL)
   {
      void* elemento = top(P1);
      push(pilaAux, elemento);
      pop(P1);
   }

   while(top(pilaAux) != NULL)
   {
      void* elemento = top(pilaAux);
      push(P2, elemento);
      push(P1, elemento);
      pop(pilaAux);
   }
   free(pilaAux);
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {

   int Abre = 0;
   int Cierra = 0;

   for (size_t k = 0 ; cadena[k] != '\0' ; k++)
   {
      char c = cadena[k]; //La variable c se refiere a ese caracter pero mas corto por que se va a utilizar bastante

      if (c == '(' || c == '{' || c == '[') Abre++;
      else if (c == ')' || c == '}' || c == ']') Cierra++;
   }
   if (Cierra > Abre) return 0;
   else
   {
      if (Abre == Cierra) return 1;
   }

   return 0;
}
     
  #include <iostream>
#include<string.h>
using namespace std;

/*1. Insertar elementos a la lista <-
2. Mostrar elementos de la lista <- 
3. Buscar elementos en la lista <-
4. Eliminar elementos de la lista <-
5. Calcular suma promedio números pares <-
6. Calcular suma promedio números impares <-
7. Calcular numero menor de la lista <-
8. Calcular número mayor de la lista <-
9. Mostrar elementos repetidos de la lista ~
10. Eliminar elementos duplicados de la lista <-
Puntos adicionales:- Ordenar la lista decreciente
                   - Invertir el orden de la lista
*/

/*  & --> Obtenemos la posición de memoria 
    * --> Accedemos al valor al que apunta (referencia) un apuntador 
    ** --> Un puntero de un apuntador, ejemplo int ** -> apunta una direccion -> int*
    -> (*PUNTERO).ATRIBUTO nos permite acceder al atributo desde el apuntador
    Struct --> es una palabra reservada de C que indica que los elementos que vienen agrupados a           continuación entre llaves componen una estructura.
    CPP --> Los archivos CPP, de forma similar a los archivos C, contienen código fuente escrito en       el lenguaje de programación orientado a objetos C++.
    H --> Declaración de los elementos de una clase antes de poder ser usados 
    */

struct Node{
   int value; 
   Node *next; 
};

//Functions prototypes

void agregarElemento(Node*&nodo, int n );
void imprimirLista(Node*&nodo);
void buscarElemento(Node *&head, int n);
void eliminarElemento(Node *&head, int n);
void sumaPromedioPares(Node *&head);
void sumaPromedioImpares(Node *&head);
void numeroMenor(Node *&head);
void numeroMayor(Node *&head);
void mostrarDuplicados(Node *&head);
void eliminarDuplicados(Node *&head);
void ordenarDecreciente(Node *&head);
void invertirOrden(Node *&head);

void agregarElemento(Node *&head, int n){
  //
  Node *new_node = new Node();
  new_node->value = n;

  Node *aux1 = head;
  Node *auxA;

  while(aux1 != NULL){
    auxA = aux1;
    aux1 = aux1->next;
  }

  if(head == aux1){
    head = new_node;
  } else {
    auxA->next = new_node;
  }
  new_node->next= aux1;
}

void imprimirLista(Node *&head){
  Node *aux1 = head;
  string s;

  while(aux1 != NULL){
    s += "["+to_string(aux1->value) + "]" + "->";
    aux1 = aux1->next;
  }
  cout << s << endl;
}

void buscarElemento(Node *&head, int n){
  int counter = 0;
  if (head == NULL){
    cout << "Lista vacia" <<endl;
  }
  
  if(head->value != n){
    Node *aux1 = head;
    while((aux1->value != n) && (aux1->next != NULL)){
      aux1 = aux1->next;
      counter++;
    }
    if(aux1->value == n){
      cout << to_string(n) + " encontrado en la posicion ["+to_string(counter)+"]" << endl;
   
    } else
      cout << "Elemento no encontrado" << endl;
      
  }
  else 
  cout << to_string(n) + " encontrado en la posicion ["+to_string(counter)+"]" << endl; 
    
}

void eliminarElemento(Node *&head, int n){
  Node *actual = head;
  Node *anterior;
  bool found = false;
  
  while(actual!= NULL){
    if(actual->value == n){
      found = true;
      break;
    }
    else{
      anterior = actual;
      actual = actual->next;
    }
  }
  if(actual != NULL){
    if(anterior == NULL){
      head = actual->next;
    } else {
        anterior->next = actual->next;
    }
  }
  delete actual;
}

void sumaPromedioPares(Node *&head){
  Node *actual = head;
  int suma = 0;
  while(actual != NULL){
    if(actual->value%2 == 0){
      suma += actual->value;
    }
    actual = actual->next;
  }
  cout << "La suma de los pares es: " + to_string(suma)<<endl;
}

void sumaPromedioImpares(Node *&head){
  Node *actual = head;
  int suma = 0;
  while(actual != NULL){
    if(actual->value%2 != 0){
      suma += actual->value;
    }
    actual = actual->next;
  }
  cout << "La suma de los impares es: " + to_string(suma)<<endl;
}


void numeroMenor(Node *&head){
  Node *actual = head;
  Node *aux1 = actual->next;
  int menor = actual->value;

  while(actual->next != NULL){
    if(actual->value > aux1->value){
      if(aux1->value < menor)
       menor = aux1->value;
     actual = actual->next;
    } else{
      actual = aux1;
      aux1 = aux1->next;
    }
  }
  cout << "El valor del elemento menor es: " + to_string(menor)<<endl;
}

void numeroMayor(Node *&head){
  Node *actual = head;
  Node *aux1 = actual->next;
  int mayor = actual->value;

  while(actual->next != NULL){
    if(actual->value < aux1->value){
      if(aux1->value > mayor)
       mayor = aux1->value;
     actual = actual->next;
    } else{
      actual = aux1;
      aux1 = aux1->next;
    }
  }
  cout << "El valor del elemento mayor es: " + to_string(mayor)<<endl;
}

void mostrarDuplicados(Node *&head){
  
  Node *actual = head;
  Node *siguiente = actual->next;
  
  while (actual != NULL) {
    while (siguiente != NULL) {
      if(actual->value == siguiente->value){
      }else{
        cout<<actual->value<<endl;
      }
        actual = siguiente;
        siguiente = siguiente->next;
    }
    siguiente = actual->next ;
    actual = actual->next;
  } 
  
}

void eliminarDuplicados(Node *&head){
   Node *aux1 = head;
  Node *aux2 = aux1->next;

  int counter = 0;
  while(aux1 != NULL){
    aux2 = aux1->next;
    while(aux2 != NULL){
      if(aux1->value == aux2->value){
        aux1->next = aux2->next;
      }
      aux2 = aux2->next;
    }
    aux1 = aux1->next;
  }
}

void ordenarDecreciente(Node *&head){
  Node *aux1 = head;
  Node *aux2 = aux1->next;
  Node *newL;
  
  while(aux1!=NULL && aux1->value < aux2->value){
    agregarElemento(newL, aux1->value);
  }
  head = newL;
}

void invertirOrden(Node *&head){
  
  Node *aux1 = head;
  Node *final;
  int counter = 0;
  
  while(aux1 != NULL){
    if(aux1->next == NULL){
      final = aux1;
    }
    aux1 = aux1->next;
  }

  
}

void ordenarLista(Node *&head){
  Node *curr = head, *aux1 = NULL;
    int t;
    if (head == NULL) {
        return;
    }else {
        while (curr != NULL) {
            aux1 = curr->next;
            while (aux1 != NULL) {
            if (curr->value > aux1->value) {
                t = curr->value;
                curr->value = aux1->value;
                aux1->value = t;
            }
            aux1 = aux1->next;
        }
        curr = curr->next;
        }
    }
}

int main(){
  
  Node *lista = NULL;
  
  agregarElemento(lista, 4);
  agregarElemento(lista, 1);
  agregarElemento(lista, 7);
  agregarElemento(lista, 1);
  agregarElemento(lista, 4);
  agregarElemento(lista, 9);
  agregarElemento(lista, 2); 
  agregarElemento(lista, 3);
  agregarElemento(lista, 5);
  agregarElemento(lista, 5);
  agregarElemento(lista, 9);
  agregarElemento(lista, 3);
  agregarElemento(lista, 3);
  ordenarLista(lista);
  ordenarDecreciente(lista);
  //imprimirLista(lista);
  //mostrarDuplicados(lista);
  
  

  return 0;
}
# include <iostream>
# include "ListaEnlazadaFunciones.h"
using namespace std;

void ListaEnlazadaFunciones::agregarElemento(Node *&head, int n){
  
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

void ListaEnlazadaFunciones::imprimirLista(Node *&head){
  Node *aux1 = head;
  string s;

  while(aux1 != NULL){
    s += "["+to_string(aux1->value) + "]" + "->";
    aux1 = aux1->next;
  }
  cout << s << endl;
}

void ListaEnlazadaFunciones::buscarElemento(Node *&head, int n){
  int counter = 0;
  if (head == NULL){
    cout << "Lista vacia" <<endl;
    return;
  }
  
  if(head->value != n){
    Node *aux1 = head;
    while((aux1->value != n) && (aux1->next != NULL)){
      aux1 = aux1->next;
      counter++;
    }
    if(aux1->value == n){
      cout << to_string(n) + " encontrado en la posición ["+to_string(counter)+"]" << endl;
   
    } else
      cout << "Elemento no encontrado" << endl;
      
  }
  else 
  cout << to_string(n) + " encontrado en la posición ["+to_string(counter)+"]" << endl; 
    
}

void ListaEnlazadaFunciones::eliminarElemento(Node *&head, int n){
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

void ListaEnlazadaFunciones::sumaPromedioPares(Node *&head){
  Node *actual = head;
  int suma = 0;
  int counter = 0;
  while(actual != NULL){
    if(actual->value%2 == 0){
      suma += actual->value;
      counter++;
    }
    actual = actual->next;
  }
  double promedio = (double)suma/(double)counter;
  cout << "La suma de los pares es: " + to_string(suma)<<endl;
  cout << "promedio: " + to_string(promedio)<<endl;
}

void ListaEnlazadaFunciones::sumaPromedioImpares(Node *&head){
  Node *actual = head;
  int suma = 0;
  int counter = 0;
  while(actual != NULL){
    if(actual->value%2 != 0){
      suma += actual->value;
      counter++;
    }
    actual = actual->next;
  }
  double promedio = (double)suma/(double)counter;
  cout << "La suma de los impares es: " + to_string(suma)<<endl;
  cout << "promedio: " + to_string(promedio)<<endl;
}

void ListaEnlazadaFunciones::numeroMenor(Node *&head){
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

void ListaEnlazadaFunciones::numeroMayor(Node *&head){
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

void ListaEnlazadaFunciones::mostrarDuplicados(Node *&head){
  Node *actual = head;
  Node *siguiente = actual->next;
  
  while (actual != NULL) {
    while (siguiente != NULL) {
      if(actual->value == siguiente->value){
        cout<<"["+to_string(actual->value) + "] ";
      }
        actual = siguiente;
        siguiente = siguiente->next;
    }
    siguiente = actual->next ;
    actual = actual->next;
  }
}

void ListaEnlazadaFunciones::eliminarDuplicados(Node *&head){
  Node *aux1 = head;
  Node *aux2 = aux1->next;

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

void ListaEnlazadaFunciones::ordenarDecreciente(Node *&head){
  Node *aux1 = head;
  int valor;
  
  while (aux1 != NULL) {
    Node *aux2 = aux1->next;
    while (aux2 != NULL) {
      if (aux1->value < aux2->value) {
        valor = aux1->value;
        aux1->value = aux2->value;
        aux2->value= valor;
      }
      aux2 = aux2->next;
    }
    aux1 = aux1->next;
  }
}

void ListaEnlazadaFunciones::listaInvertida(Node *&head) {

  if (head != NULL) {
    listaInvertida(head->next);
    cout<<"["+to_string(head->value) + "]" + "->";
    
  }
}

void ListaEnlazadaFunciones::ordenarLista(Node *&head){
  Node *actual = head;
  Node *aux1;
    
    int temp;
    if (head == NULL) {
        return;
    }else {
        while (actual != NULL) {
            aux1 = actual->next;
            while (aux1 != NULL) {
            if (actual->value > aux1->value) {
                temp = actual->value;
                actual->value = aux1->value;
                aux1->value = temp;
            }
            aux1 = aux1->next;
        }
        actual = actual->next;
        }
    }
}

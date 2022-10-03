#include <iostream>
#include <stdlib.h>
# include "ListaEnlazadaFunciones.h"
using namespace std;

int main() {
  int option;
  Node *head = NULL;
  ListaEnlazadaFunciones *func = new ListaEnlazadaFunciones();

  do{
    cout<<"-------------------------------"<<endl;
    cout<<"Ingrese la opción que desee:"<<endl;
    cout<<"\n";
    cout<<"0. Finalizar programa"<<endl;
    cout<<"1. Agregar elemento a la lista"<<endl;
    cout<<"2. Imprimir la lista"<<endl;
    cout<<"3. Buscar un elemento en la lista"<<endl;
    cout<<"4. Eliminar un elemento de la lista"<<endl;
    cout<<"5. Promedio de los valores pares de la lista"<<endl;
    cout<<"6. Promedio de los valores impares de la lista"<<endl;
    cout<<"7. El valor menor de la lista"<<endl;
    cout<<"8. El valor mayor de la lista"<<endl;
    cout<<"9. Mostrar elementos duplicados"<<endl;
    cout<<"10. Eliminar elementos duplicados"<<endl;
    cout<<"11. Ordenar la lista de manera decreciente"<<endl;
    cout<<"12. Invertir orden de la lista"<<endl;
    cout<<"\n";

    cin>>option;

    switch (option){

      case 0:
        cout<<"El programa ha finalizado."<<endl;
        break;
      case 1:
        int valor;
        cout<<"Ingrese el valor del elemento que desea insertar:"<<endl;
        cin>>valor;
        func->agregarElemento(head, valor);
        break;

      case 2:
        func->imprimirLista(head);
        break;

      case 3:
        int valorBuscar;
      cout<<"Ingrese el valor del elemento a buscar:"<<endl;
      cin>>valorBuscar;
      func->buscarElemento(head, valorBuscar);
      break;

      case 4:
      int valorEliminar;
      cout<<"Ingrese el valor del elemento a eliminar:"<<endl;
      cin>>valorEliminar;
      func->eliminarElemento(head, valorEliminar);
      break;

      case 5:
      func->sumaPromedioPares(head);
      break;

      case 6:
      func->sumaPromedioImpares(head);
      break;

      case 7:
      func->numeroMenor(head);
      break;

      case 8:
      func->numeroMayor(head);
      break;

      case 9:
      cout<<"Los elementos duplicados son: ";
      func->ordenarLista(head);
      func->mostrarDuplicados(head);
      
      break;

      case 10:
      cout<<"Los elementos duplicados se han eliminado."<<endl;
      func->ordenarLista(head);
      func->eliminarDuplicados(head);
      break;

      case 11:
      func->ordenarDecreciente(head);
      break;

      case 12:
      func->listaInvertida(head);
      break;
      
      default:
      cout<<"Opción inválida. Digite un número del 0 al 12"<<endl;
      break;
    }
    cout<<"\n";
  }
    while(option != 0);
  
  return 0;
}
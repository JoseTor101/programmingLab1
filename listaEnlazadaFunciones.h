# ifndef LISTAENLAZADAFUNCIONES_H
# define LISTAENLAZADAFUNCIONES_H
# include "structNode.h"

class ListaEnlazadaFunciones{
public:
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
void listaInvertida(Node *&head);
void ordenarLista(Node *&head);
};


#endif
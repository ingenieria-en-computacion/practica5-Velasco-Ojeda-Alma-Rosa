#include "node.h"
#include <stdlib.h>

/**
 * Crea un nuevo nodo con los datos proporcionados y lo devuelve.
 * 
 * @param d Dato que se almacenará en el nuevo nodo.
 * @return Un apuntador al nuevo nodo creado. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para un nuevo nodo utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. El nodo creado
 *          tiene sus campos inicializados, y el campo de datos se establece con el valor
 *          proporcionado en el parámetro `d`, el siguiente .
 */
Node *new_node(Data d){
   Node *new = (Node*) malloc (sizeof(Node)); 
   if ( new !=NULL){
     new->data=d; 
     new->next=NULL; 
   }
   else {
     printf("Error: The node cannot be created\n"); 
   }
   return new; 
}

/**
 * Elimina un nodo y libera la memoria asociada a él.
 * 
 * @param n Apuntador al nodo que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para el nodo utilizando `free`.
 *          Si el apuntador pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que el nodo ya no se utiliza después
 *          de ser eliminado. Está función solo libera nodos cuyo enlace al siguiente es nulo
 */
void delete_node(Node* n){
  Node *tmp=n; 
    if (n->next==NULL) {
        free(n);
        n=NULL; 
    }
   else  if (n->next !=NULL){
     while (tmp->next != NULL && tmp->next != n) {
            tmp = tmp->next;
        } 
        if (tmp->next == n){
          Node *tmpd=n->next; 
          tmp->next= tmpd;
          n->next=NULL; 
          free(n); 
         n=NULL; 
        }
 } 
}

/**
 * Imprime la información contenida en un nodo.
 * 
 * @param n Apuntador al nodo que se desea imprimir.
 * @details Esta función imprime los campos del nodo, como su valor y punteros a otros nodos,
 *          en un formato legible. Si el puntero pasado es NULL, la función imprime un mensaje
 *          indicando que el nodo es inválido. La salida se dirige a la salida estándar (stdout).
 */
void print_node(Node* n){
    if (n !=NULL){
     printf("Info: %d\n", n->data); 
     printf("Next Node: %p\n", n->next); 
    }
    else {
        printf("Error: Node not found\n"); 
    }
}
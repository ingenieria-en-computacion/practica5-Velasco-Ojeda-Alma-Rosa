
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(int size) {
    Stack *NewS = (Stack*)malloc(sizeof(Stack)); 
    if (NewS == NULL) {
        printf("Error: The Stack cannot be created\n"); 
        return NULL;
    } else {
        NewS->top = NULL;
        NewS->size = size;
    }
    return NewS; 
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d) {
    if (s == NULL) return;
    if (s->top == s->size) {
        printf("Error: The stack is full\n"); 
        return; 
    }
    else {
        Node *Newd = new_node(d); 
        if (Newd == NULL) return;
        Newd->next = s->top;
        s->top = Newd; 
    } 
}
   
/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s) {
    if (s == NULL || s->top == NULL) return -1; 
    if (stack_is_empty(s) == 1) {
        printf("Stack is empty\n"); 
        return -1;
    }

    Node* temp = s->top;
    s->top = s->top->next;
    Data popped_data = temp->data;  
    free(temp); 
    s->size--;  
    return popped_data; 
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s) {
    if (s == NULL) return -1; 
    return (s->top == NULL) ? 1 : 0;  
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s) { 
    if (s == NULL) return; 
    Node *e = s->top;
    while (e != NULL) {
        Node *temp = e;
        e = e->next;
        free(temp); 
    }
    s->top = NULL;
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s) {
    if (s == NULL) return; 
    if (stack_is_empty(s) == 0) {
        stack_empty(s);  
    }
    free(s); 
    s = NULL;
}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s) {
    if (stack_is_empty(s) == 1) {
        printf("The stack is empty\n");
        return;
    }

    printf("[ ");
    Node *e = s->top; 
    while (e != NULL) {
        printf("%d ", e->data);  
        e = e->next;
    }
    printf("]\n");
}
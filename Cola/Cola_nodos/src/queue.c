#include "queue.h"
#include <stdlib.h>

Queue* queue_create(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q != NULL) {
        q->head = NULL;
        q->tail = NULL;
    }
    return q;
}

void queue_enqueue(Queue* q, Data d){
    if (q == NULL) return;
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) return;
    new_node->data = d;
    new_node->next = NULL;
    if (q->tail != NULL) {
        q->tail->next = new_node;
    } else {
        q->head = new_node;
    }
    q->tail = new_node;
}

Data queue_dequeue(Queue* q){
    if (q == NULL || q->head == NULL) return -1;
    Node* temp = q->head;
    Data data = temp->data;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return data;
}

bool queue_is_empty(Queue* q){
    return (q == NULL && q->head == NULL);
}

Data queue_front(Queue* q){
    if (q == NULL && q->head == NULL) return -1;
    return q->head->data;
}

void queue_empty(Queue* q){
    if (q == NULL) return;
    Node* current = q->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    q->head = NULL;
    q->tail = NULL;
}

void queue_delete(Queue* q){
    if (q == NULL) return;
    queue_empty(q);
    free(q);
}
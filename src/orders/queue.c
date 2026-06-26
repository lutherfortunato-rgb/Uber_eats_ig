#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "order.h"

//Os comentarios foram feitos no header (queue.h)

typedef struct Node {
    Order order;
    struct Node* next;
} Node;

struct Queue {
    Node* front;
    Node* rear;
    int size;
};

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));

    if (queue == NULL) {
        printf("Erro ao criar fila.\n");
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

int isQueueEmpty(const Queue* queue) {
    return queue == NULL || queue->front == NULL;
}

void enqueue(Queue* queue, Order order) {
    if (queue == NULL) {
        printf("Fila invalida.\n");
        return;
    }

    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Erro ao adicionar pedido.\n");
        return;
    }

    newNode->order = order;
    newNode->next = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

int dequeue(Queue* queue, Order* removedOrder) {
    if (isQueueEmpty(queue) || removedOrder == NULL) {
        return 0;
    }

    Node* temp = queue->front;

    *removedOrder = temp->order;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return 1;
}

int peekQueue(const Queue* queue, Order* order) {
    if (isQueueEmpty(queue) || order == NULL) {
        return 0;
    }

    *order = queue->front->order;

    return 1;
}
void displayQueue(const Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Fila de pedidos vazia.\n");
        return;
    }

    Node* current = queue->front;

    printf("\n=== FILA DE PEDIDOS ===\n");

    while (current != NULL) {
        displayOrder(&current->order);
        printf("----------------------\n");
        current = current->next;
    }
}

void destroyQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }

    Node* current = queue->front;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(queue);
}

//It better work, Goddammit!

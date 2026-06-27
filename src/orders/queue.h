#ifndef QUEUE_H
#define QUEUE_H

#include "order.h"


//A estrutura fila (queue) e opaca, ou seja, sua implementacao é escondida do usuário.
//Isso para evitar que os pedidos nao sejam alterados diretamente, garantindo que as operacoes de enfileiramento e desenfileiramento 
//sejam feitas de forma controlada.
typedef struct Queue Queue;

// Criacao da fila
Queue* createQueue(void);

// Destruição da fila
void destroyQueue(Queue* queue);

// Operações principais

//Enfileirar pedido
void enqueue(Queue* queue, Order order);

//Desinfileirar pedido
int dequeue(Queue* queue, Order* removedOrder);

// Consultas

//Ver se a fila esta vazia
int isQueueEmpty(const Queue* queue);

//Obter o tamanho da fila
int getQueueSize(const Queue* queue);

//Mostrar o topo da fila
int peekQueue(const Queue* queue, Order* order);

// Visualizacao da fila
void displayQueue(const Queue* queue);

#endif
#include <stdio.h>
#include <string.h>
#include "order.h"


//Funcao para criar um pedido
Order createOrder(int id, char customer_name[], char restaurant_name[], char description[], float total_price) {
Order order;

order.id = id;

//Para fazer as atribuicoes de strings, e necessario utilizar a funcao strcpy, pois nao e possivel atribuir diretamente 
//arrays de caracteres em C.

strcpy(order.customer_name, customer_name);
strcpy(order.restaurant_name, restaurant_name);
strcpy(order.description, description);

//Ja com o float total_price, podemos atribuir diretamente, pois e um tipo de dado primitivo.
order.total_price = total_price;

//Nenhuma entrega atribuida inicialmente
order.driver_id = -1;

//Todo pedido comeca no estado PENDING
order.status = PENDING;
return order;
}

//Obtem o estado atual do pedido
OrderStatus getOrderStatus(const Order* order) {
    if(order == NULL){
        return -1; // Retorna um valor invalido se o ponteiro for nulo
    }
    return order->status;
}

//Altera o estado do pedido e retorna o novo estado
void setOrderStatus(Order* order, OrderStatus status) {
    if(order != NULL){
        order->status = status;
    }
}

float getTotalPrice(const Order* order){
    if(order == NULL){
        return -1; // Retorna um valor invalido se o ponteiro for nulo
    }
    return order->total_price;
}

int getOrderId(const Order* order){
    if(order == NULL){
        return -1; // Retorna um valor invalido se o ponteiro for nulo
    }
    return order->id;
}

/*Ao inves de imprimir diretamente o valor do enum, podemos criar uma funcao que converta o valor do
 enum para uma string correspondente, facilitando a leitura e compreensao do estado do pedido.
Exemplo:
Ao inves de imprimir "Estado do Pedido: 0"
Imprimir "Estado do Pedido: Pendente"
*/
const char *getStatusString(OrderStatus status){
    switch(status){
        case PENDING:
            return "Pendente";
            case PREPARING:
            return "Em Preparacao";
            case READY_FOR_DELIVERY:
            return "Pronto para Entrega";
            case IN_DELIVERY:
            return "Em Entrega";
            case DELIVERED:
            return "Entregue";
            case CANCELLED:
            return "Cancelado";
            
    } 
}

void assignDriverToOrder(Order* order, int driver_id){
    if(order != NULL){
        order->driver_id = driver_id;
    }
}

int getAssignedDriver(const Order* order){
    if(order == NULL){
        return -1; // Retorna um valor invalido se o ponteiro for nulo
    }
    return order->driver_id;
}

void cancelOrder(Order* order){
    if(order != NULL){
        order->status = CANCELLED;
    }
}

int isDelivered(const Order* order){
    if(order == NULL){
        return -1; // Retorna um valor invalido se o ponteiro for nulo
    }
    return order->status == DELIVERED;
}

//Mostrar o pedido
void displayOrder(const Order* order){
    printf("ID do Pedido: %d\n", order->id);
    printf("Nome do Cliente: %s\n", order->customer_name);
    printf("Nome do Restaurante: %s\n", order->restaurant_name);
    printf("Descricao do Pedido: %s\n", order->description);
    printf("Valor Total: %.2f\n", order->total_price);
    printf("ID do Entregador: %d\n", order->driver_id);
    printf("Estado do Pedido: %s\n", getStatusString(order->status));
}


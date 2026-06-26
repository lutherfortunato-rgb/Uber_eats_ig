#ifndef ORDER_H
#define ORDER_H

#define MAX_NAME 60 //Limite maximo de caracters para os nomes
#define MAX_DESCRIPTION 200 //Limite maximo para descricao

// Tipo de dados utilizado para representar o estado atual de um pedido.
//OrderStatus funciona como um enumerador e apenas pode assumir um dos valores definidos abaixo.
typedef enum {

    // Pedido criado, mas ainda não começou a ser preparado.
    PENDING,

    // Pedido esta a ser preparado pelo restaurante.
    PREPARING,

    // Pedido pronto para ser recolhido pelo entregador.
    READY_FOR_DELIVERY,

    // Pedido encontra-se em trânsito para o cliente.
    IN_DELIVERY,

    // Pedido entregue com sucesso.
    DELIVERED,

    // Pedido cancelado.
    CANCELLED

} OrderStatus;

// Estrutura que representa um pedido feito por um cliente.
typedef struct {

    // Identificador unico do pedido.
    int id;

    // Nome do cliente que efetuou o pedido.
    char customer_name[MAX_NAME];

    // Nome do restaurante responsavel pelo pedido.
    char restaurant_name[MAX_NAME];

    // Descricao dos produtos pedidos.
    char description[MAX_DESCRIPTION];

    // Valor total do pedido.
    float total_price;

    // ID do entregador associado ao pedido.
    // Pode permanecer sem atribuicao até que um entregador seja selecionado.
    int driver_id;

    // Estado atual do pedido.
    // Assume um dos valores definidos em OrderStatus.
    OrderStatus status;

} Order;

//Identificacao das funcoes que serao implementadas no ficheiro order.c:

//-----------------------------------------------------------------------------------

//Funcao que cria um novo pedido com os dados fornecidos e retorna uma estrutura Order preenchida.

Order createOrder(int id, char customer_name[], char restaurant_name[], char description[], float total_price);

//Funcao que exibe os detalhes de um pedido, incluindo informacoes como o nome do cliente, nome do restaurante...

void displayOrder(const Order* order);

//Funcao que atualiza o estado de um pedido para um novo estado fornecido.

void setOrderStatus(Order* order, OrderStatus status);

//Funcao que retorna o estado atual de um pedido.

OrderStatus getOrderStatus(const Order* order);

//Funcao que retorna o valor total do pedido.

float getOrderTotalPrice(const Order* order);

//Outras funcoes essenciais

void assignDriver(Order* order, int driver_id); //Atribui um ID de entregador a um pedido, associando o ID do entregador ao pedido.

int getDriverId(const Order* order); //Retorna o ID do entregador

void cancelOrder(Order* order); //Cancela um pedido, alterando seu estado para CANCELLED. Esta funcao pode ser chamada quando um cliente 
                                //decide cancelar um pedido antes de ser entregue.

int isDelivered(const Order* order); //Verifica se um pedido foi entregue, retornando 1 (verdadeiro) se o estado do pedido for DELIVERED 
                                    //e 0 (falso) caso contrário. Esta funcao pode ser utilizada para verificar o status de um pedido antes
                                    // de realizar acoes adicionais, como permitir avaliações ou feedbacks por parte do cliente.


#endif 

//It better work goddammit!

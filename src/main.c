#include <stdio.h>
#include <stdlib.h>

#include "restaurant/restaurant.h"
#include "restaurant/bst.h"

#include "orders/order.h"
#include "orders/queue.h"

#include "courier/courier.h"

#include "map/graph.h"
#include "map/dijkstra.h"

#define CUSTOMER_NAME "Joao"

int main(void)
{
    printf("=====================================\n");
    printf("      Uber Eats Simulation\n");
    printf("=====================================\n\n");

    /*
        --------------------------------
        Create restaurant database (BST)
        --------------------------------
    */

    BSTNode *restaurants = NULL;

    Restaurant kfc =
        createRestaurant(
            1,
            "KFC",
            "KFC"
        );

    addMenuItem(&kfc, "Bucket 6 Pieces", 12.50);
    addMenuItem(&kfc, "Fries", 2.50);
    addMenuItem(&kfc, "Coke", 1.50);

    restaurants =
        insertRestaurant(
            restaurants,
            kfc
        );

    Restaurant burgerKing =
        createRestaurant(
            2,
            "Burger King",
            "Burger King"
        );

    addMenuItem(&burgerKing, "Whopper", 8.90);
    addMenuItem(&burgerKing, "Onion Rings", 3.00);
    addMenuItem(&burgerKing, "Sprite", 1.80);

    restaurants =
        insertRestaurant(
            restaurants,
            burgerKing
        );

    Restaurant pizzaHut =
        createRestaurant(
            3,
            "Pizza Hut",
            "Pizza Hut"
        );

    addMenuItem(&pizzaHut, "Pepperoni Pizza", 14.00);
    addMenuItem(&pizzaHut, "Garlic Bread", 4.50);
    addMenuItem(&pizzaHut, "Water", 1.00);

    restaurants =
        insertRestaurant(
            restaurants,
            pizzaHut
        );

    printf("Restaurants loaded.\n");

    /*
        ---------------------
        Create order queue
        ---------------------
    */

    Queue *orders =
        createQueue();

    /*
        ---------------------
        Register couriers
        ---------------------
    */

    CourierManager couriers;

    initCourierManager(&couriers);

    registerCourier(&couriers, "Carlos");
    registerCourier(&couriers, "Pedro");
    registerCourier(&couriers, "Ana");
    registerCourier(&couriers, "Mateus");

    /*
        ---------------------
        Create city graph
        ---------------------
    */

    Graph *city =
        createGraph();

    int courier =
        addVertex(city, "Courier");

    int kfcNode =
        addVertex(city, "KFC");

    int burgerNode =
        addVertex(city, "Burger King");

    int pizzaNode =
        addVertex(city, "Pizza Hut");

    int crossroad =
        addVertex(city, "Crossroad");

    int customer =
        addVertex(city, "Joao House");

    addEdge(city, courier, crossroad, 2);

    addEdge(city, crossroad, kfcNode, 1);
    addEdge(city, crossroad, burgerNode, 2);
    addEdge(city, crossroad, pizzaNode, 3);

    addEdge(city, kfcNode, customer, 4);
    addEdge(city, burgerNode, customer, 3);
    addEdge(city, pizzaNode, customer, 5);

    /*
        ---------------------
        Search restaurant
        ---------------------
    */

    printf("\nSearching for KFC...\n");

    BSTNode *selectedRestaurant =
        searchRestaurant(
            restaurants,
            "KFC"
        );

    if (selectedRestaurant == NULL)
    {
        printf("Restaurant not found.\n");
        return 1;
    }

    displayRestaurant(
        &selectedRestaurant->restaurant
    );

    /*
        ---------------------
        Create an order
        ---------------------
    */

    const MenuItem *selectedItem =
        getMenuItem(
            &selectedRestaurant->restaurant,
            1
        );

    if (selectedItem == NULL)
    {
        printf("Invalid menu item.\n");
        return 1;
    }

    Order order =
        createOrder(
            1,
            CUSTOMER_NAME,
            selectedRestaurant->restaurant.name,
            selectedItem->name,
            selectedItem->price
        );

    enqueue(
        orders,
        order
    );

    printf("\nOrder added to queue.\n");
    printf("Queue size: %d\n",
           getQueueSize(orders));

    /*
        ---------------------
        Assign courier
        ---------------------
    */

    const char *courierName =
        assignCourier(
            &couriers,
            order.id
        );

    if (courierName != NULL)
    {
        printf("Assigned courier: %s\n",
               courierName);
    }

    /*
        ---------------------
        Calculate route
        ---------------------
    */

    printf("\nShortest route:\n");

    printShortestPath(
        city,
        findVertex(city, "Courier"),
        findVertex(city, "Joao House")
    );

    /*
        ---------------------
        Show order
        ---------------------
    */

    printf("\nFinal Order:\n\n");

    displayOrder(&order);

    /*
        ---------------------
        Cleanup
        ---------------------
    */

    destroyQueue(orders);

    destroyCourierManager(&couriers);

    freeGraph(city);

    freeBST(restaurants);

    printf("\nProgram finished successfully.\n");

    return 0;
}
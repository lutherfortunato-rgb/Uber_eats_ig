#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "courier.h"

void initCourierManager(CourierManager *cm)
{
    if (cm == NULL)
        return;

    cm->head = NULL;
    cm->count = 0;
}

void registerCourier(
    CourierManager *cm,
    const char *name
)
{
    if (cm == NULL || name == NULL)
        return;

    appendCourier(
        &cm->head,
        name,
        "Available"
    );

    cm->count++;
}

const char *assignCourier(
    CourierManager *cm,
    int order_id
)
{
    (void)order_id;

    if (cm == NULL)
        return NULL;

    CourierNode *courier =
        findAvailableCourier(cm->head);

    if (courier == NULL)
        return NULL;

    setCourierStatus(
        cm->head,
        courier->name,
        "Busy"
    );

    return courier->name;
}

void releaseCourier(
    CourierManager *cm,
    const char *name
)
{
    if (cm == NULL || name == NULL)
        return;

    setCourierStatus(
        cm->head,
        name,
        "Available"
    );
}

void displayCouriers(
    const CourierManager *cm
)
{
    if (cm == NULL)
        return;

    printf("\n===== COURIERS =====\n");

    printCouriers(cm->head);
}

void destroyCourierManager(
    CourierManager *cm
)
{
    if (cm == NULL)
        return;

    freeCourierList(&cm->head);

    cm->count = 0;
}
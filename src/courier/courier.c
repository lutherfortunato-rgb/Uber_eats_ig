#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "courier.h"

void initCourierManager(CourierManager *cm)
{
    cm->head  = NULL;
    cm->count = 0;
}

void registerCourier(CourierManager *cm, const char *name)
{
    appendCourier(&cm->head, name, "Available");
    cm->count++;
    printf("  Courier '%s' registered successfully.\n", name);
}

const char *assignCourier(CourierManager *cm, int order_id)
{
    CourierNode *courier = findAvailableCourier(cm->head);

    if (courier == NULL) {
        printf("\n  [!] No couriers available at the moment.\n\n");
        return NULL;
    }

    /* Mark as busy */
    setCourierStatus(cm->head, courier->name, "Busy");

    printf("\n  Searching for available courier...\n");
    printf("  >> %s selected.\n", courier->name);
    printf("  Order #%d assigned to %s.\n\n", order_id, courier->name);

    return courier->name;
}

void releaseCourier(CourierManager *cm, const char *name)
{
    if (setCourierStatus(cm->head, name, "Available"))
        printf("  Courier '%s' is now available again.\n", name);
    else
        printf("  [!] Courier '%s' not found.\n", name);
}

void displayCouriers(const CourierManager *cm)
{
    printf("\n=== Couriers ===\n");
    printCouriers(cm->head);
}

void destroyCourierManager(CourierManager *cm)
{
    freeCourierList(&cm->head);
    cm->count = 0;
}

#ifndef COURIER_H
#define COURIER_H

#include "linkedlist.h"

/* ─────────────────────────────────────────────
 * Courier manager
 * Owns the courier list and exposes operations
 * used by the rest of the delivery system.
 * ───────────────────────────────────────────── */

typedef struct
{
    CourierNode *head;   /* head of the courier linked list */
    int          count;  /* total number of registered couriers */
} CourierManager;

/* Initialise an empty courier manager. */
void initCourierManager(CourierManager *cm);

/* Register a new courier (status defaults to "Available"). */
void registerCourier(CourierManager *cm, const char *name);

/* Assign the first available courier to an order.
 * Returns the courier's name (pointer into the list node) or NULL. */
const char *assignCourier(CourierManager *cm, int order_id);

/* Mark a courier as available again (e.g. after delivery). */
void releaseCourier(CourierManager *cm, const char *name);

/* Print the current courier roster. */
void displayCouriers(const CourierManager *cm);

/* Free all memory owned by the manager. */
void destroyCourierManager(CourierManager *cm);

#endif /* COURIER_H */

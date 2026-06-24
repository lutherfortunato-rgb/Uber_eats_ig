#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* ─────────────────────────────────────────────
 * Courier list node
 * Stores a courier's name and current status.
 * ───────────────────────────────────────────── */
typedef struct CourierNode
{
    char name[100];
    char status[20];        /* "Available" or "Busy" */
    struct CourierNode *next;
} CourierNode;

/* ─────────────────────────────────────────────
 * Delivery history node
 * One node per delivery event linked to an order.
 * ───────────────────────────────────────────── */
typedef struct DeliveryHistoryNode
{
    int  total;
    int  fee;
    int  delivery_fee;
    char distance[20];
    char delivery_address[100];
    char received[100];     /* timestamp / status label when received */
    char delivered[100];    /* timestamp / status label when delivered */
    struct DeliveryHistoryNode *next;
} DeliveryHistoryNode;

/* ─────────────────────────────────────────────
 * Courier list API
 * ───────────────────────────────────────────── */

/* Create a new courier node (does NOT insert it). */
CourierNode *createCourier(const char *name, const char *status);

/* Append a courier to the end of the list. */
void appendCourier(CourierNode **head, const char *name, const char *status);

/* Return the first courier whose status is "Available", or NULL. */
CourierNode *findAvailableCourier(CourierNode *head);

/* Set a courier's status by name. Returns 1 on success, 0 if not found. */
int setCourierStatus(CourierNode *head, const char *name, const char *status);

/* Remove a courier by name. Returns 1 on success, 0 if not found. */
int removeCourier(CourierNode **head, const char *name);

/* Print all couriers with their current status. */
void printCouriers(CourierNode *head);

/* Free the entire courier list. */
void freeCourierList(CourierNode **head);

#endif /* LINKED_LIST_H */

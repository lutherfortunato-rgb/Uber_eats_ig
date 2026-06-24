#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/* ═══════════════════════════════════════════════
 * COURIER LIST
 * ═══════════════════════════════════════════════ */

CourierNode *createCourier(const char *name, const char *status)
{
    CourierNode *node = (CourierNode *)malloc(sizeof(CourierNode));
    if (!node) {
        fprintf(stderr, "Error: could not allocate memory for courier.\n");
        return NULL;
    }
    strncpy(node->name,   name,   sizeof(node->name)   - 1);
    strncpy(node->status, status, sizeof(node->status) - 1);
    node->name[sizeof(node->name)     - 1] = '\0';
    node->status[sizeof(node->status) - 1] = '\0';
    node->next = NULL;
    return node;
}

void appendCourier(CourierNode **head, const char *name, const char *status)
{
    CourierNode *node = createCourier(name, status);
    if (!node) return;

    if (*head == NULL) {
        *head = node;
        return;
    }

    CourierNode *current = *head;
    while (current->next != NULL)
        current = current->next;

    current->next = node;
}

CourierNode *findAvailableCourier(CourierNode *head)
{
    CourierNode *current = head;
    while (current != NULL) {
        if (strcmp(current->status, "Available") == 0)
            return current;
        current = current->next;
    }
    return NULL;   /* none available */
}

int setCourierStatus(CourierNode *head, const char *name, const char *status)
{
    CourierNode *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strncpy(current->status, status, sizeof(current->status) - 1);
            current->status[sizeof(current->status) - 1] = '\0';
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int removeCourier(CourierNode **head, const char *name)
{
    if (*head == NULL) return 0;

    /* Special case: removing the head */
    if (strcmp((*head)->name, name) == 0) {
        CourierNode *temp = *head;
        *head = (*head)->next;
        free(temp);
        return 1;
    }

    CourierNode *prev    = *head;
    CourierNode *current = (*head)->next;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            prev->next = current->next;
            free(current);
            return 1;
        }
        prev    = current;
        current = current->next;
    }
    return 0;
}

void printCouriers(CourierNode *head)
{
    if (head == NULL) {
        printf("  (no couriers registered)\n");
        return;
    }

    printf("\n  %-20s %-12s\n", "Courier", "Status");
    printf("  %-20s %-12s\n", "--------------------", "------------");

    int index = 1;
    CourierNode *current = head;
    while (current != NULL) {
        printf("  %d. %-18s [%s]\n", index++, current->name, current->status);
        current = current->next;
    }
    printf("\n");
}

void freeCourierList(CourierNode **head)
{
    CourierNode *current = *head;
    while (current != NULL) {
        CourierNode *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

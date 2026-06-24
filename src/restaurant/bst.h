#ifndef BST_H
#define BST_H

#include "restaurant.h"

typedef struct BSTNode {

    Restaurant restaurant;

    struct BSTNode *left;
    struct BSTNode *right;

} BSTNode;

/* BST operations */
BSTNode *insertRestaurant(
    BSTNode *root,
    Restaurant restaurant
);

BSTNode *searchRestaurant(
    BSTNode *root,
    const char *name
);

void displayRestaurantsInOrder(
    BSTNode *root
);

void freeBST(
    BSTNode *root
);

#endif
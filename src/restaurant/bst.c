#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

BSTNode *insertRestaurant(
    BSTNode *root,
    Restaurant restaurant
) {

    if (root == NULL) {

        BSTNode *node =
            malloc(sizeof(BSTNode));

        if (node == NULL) {
            return NULL;
        }

        node->restaurant = restaurant;

        node->left = NULL;
        node->right = NULL;

        return node;
    }

    int comparison =
        strcmp(
            restaurant.name,
            root->restaurant.name
        );

    if (comparison < 0) {

        root->left =
            insertRestaurant(
                root->left,
                restaurant
            );
    }
    else if (comparison > 0) {

        root->right =
            insertRestaurant(
                root->right,
                restaurant
            );
    }

    return root;
}

BSTNode *searchRestaurant(
    BSTNode *root,
    const char *name
) {

    if (root == NULL) {
        return NULL;
    }

    int comparison =
        strcmp(
            name,
            root->restaurant.name
        );

    if (comparison == 0) {
        return root;
    }

    if (comparison < 0) {

        return searchRestaurant(
            root->left,
            name
        );
    }

    return searchRestaurant(
        root->right,
        name
    );
}

void displayRestaurantsInOrder(
    BSTNode *root
) {

    if (root == NULL) {
        return;
    }

    displayRestaurantsInOrder(
        root->left
    );

    printf(
        "%s\n",
        root->restaurant.name
    );

    displayRestaurantsInOrder(
        root->right
    );
}

void freeBST(
    BSTNode *root
) {

    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);

    free(root);
}
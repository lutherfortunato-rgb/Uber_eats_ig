#include <stdio.h>
#include <string.h>

#include "restaurant.h"

Restaurant createRestaurant(
    int id,
    const char *name,
    const char *location
) {

    Restaurant restaurant;

    restaurant.id = id;

    strncpy(
        restaurant.name,
        name,
        MAX_NAME - 1
    );

    restaurant.name[MAX_NAME - 1] = '\0';

    strncpy(
        restaurant.location,
        location,
        MAX_NAME - 1
    );

    restaurant.location[MAX_NAME - 1] = '\0';

    restaurant.menuCount = 0;

    return restaurant;
}

int addMenuItem(
    Restaurant *restaurant,
    const char *itemName,
    float price
) {

    if (restaurant == NULL) {
        return 0;
    }

    if (restaurant->menuCount >= MAX_MENU_ITEMS) {
        return 0;
    }

    MenuItem *item =
        &restaurant->menu[restaurant->menuCount];

    strncpy(
        item->name,
        itemName,
        MAX_NAME - 1
    );

    item->name[MAX_NAME - 1] = '\0';

    item->price = price;

    restaurant->menuCount++;

    return 1;
}

void displayMenu(
    const Restaurant *restaurant
) {

    if (restaurant == NULL) {
        return;
    }

    printf("\n===== MENU =====\n");

    for (int i = 0; i < restaurant->menuCount; i++) {

        printf(
            "%d. %s - %.2f\n",
            i + 1,
            restaurant->menu[i].name,
            restaurant->menu[i].price
        );
    }
}

void displayRestaurant(
    const Restaurant *restaurant
) {

    if (restaurant == NULL) {
        return;
    }

    printf("\n===== RESTAURANT =====\n");

    printf(
        "ID: %d\n",
        restaurant->id
    );

    printf(
        "Name: %s\n",
        restaurant->name
    );

    printf(
        "Location: %s\n",
        restaurant->location
    );

    displayMenu(restaurant);
}
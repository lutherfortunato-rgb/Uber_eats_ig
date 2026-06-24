#ifndef RESTAURANT_H
#define RESTAURANT_H

#define MAX_NAME 60
#define MAX_MENU_ITEMS 20

typedef struct {

    char name[MAX_NAME];
    float price;

} MenuItem;

typedef struct {

    int id;

    char name[MAX_NAME];

    /* Must match a location in the graph */
    char location[MAX_NAME];

    MenuItem menu[MAX_MENU_ITEMS];

    int menuCount;

} Restaurant;

/* Restaurant operations */
Restaurant createRestaurant(
    int id,
    const char *name,
    const char *location
);

int addMenuItem(
    Restaurant *restaurant,
    const char *itemName,
    float price
);

void displayRestaurant(
    const Restaurant *restaurant
);

void displayMenu(
    const Restaurant *restaurant
);

#endif
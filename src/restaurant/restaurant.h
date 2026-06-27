#ifndef RESTAURANT_H
#define RESTAURANT_H

#define MAX_NAME 60
#define MAX_MENU_ITEMS 20

/* Represents a single menu item. */
typedef struct {

    char name[MAX_NAME];
    float price;

} MenuItem;

/* Represents a restaurant. */
typedef struct {

    int id;

    char name[MAX_NAME];

    /* Must match a location in the graph */
    char location[MAX_NAME];

    MenuItem menu[MAX_MENU_ITEMS];

    int menuCount;

} Restaurant;

/* Creates a restaurant. */
Restaurant createRestaurant(
    int id,
    const char *name,
    const char *location
);

/* Adds a menu item to a restaurant.
 * Returns 1 on success, 0 on failure.
 */
int addMenuItem(
    Restaurant *restaurant,
    const char *itemName,
    float price
);

/* Displays the restaurant information. */
void displayRestaurant(
    const Restaurant *restaurant
);

/* Displays the restaurant menu. */
void displayMenu(
    const Restaurant *restaurant
);

/* Returns the number of menu items. */
int getMenuSize(
    const Restaurant *restaurant
);

/* Returns a pointer to the selected menu item.
 * Returns NULL if the option is invalid.
 *
 * option is 1-based:
 * 1 -> first menu item
 * 2 -> second menu item
 * ...
 */
const MenuItem *getMenuItem(
    const Restaurant *restaurant,
    int option
);

#endif
#include <stdio.h>

#include "menu.h"

void showMainMenu(void) {

    printf("\n");
    printf("====================================\n");
    printf("             UBER EATS             \n");
    printf("====================================\n");
    printf("1. Search Restaurant\n");
    printf("2. Create Order\n");
    printf("3. View Orders\n");
    printf("4. View Couriers\n");
    printf("5. Show City Map\n");
    printf("6. Calculate Route\n");
    printf("0. Exit\n");
    printf("====================================\n");
}

int getMenuOption(void) {

    int option;

    printf("Option: ");
    scanf("%d", &option);

    return option;
}
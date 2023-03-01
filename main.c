#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int order= 1, time = 0, flavour = 0, size = 0;
    float cost = 0;
    printf("WELCOME TO CHURCHILL'S ICE CREAM SHOP\nWhat would you like to order?\n");
    char flavours[50][50] = {"Vanilla", "Strawberry", "Chocolate", "Mango"};    //The index of each flavour helps select costs
    char sizes[50][50] = {"Small", "Large"};
    float small_costs[5] = {5, 5, 6, 7};    //Each cost corresponds to the index of the given flavour (Eg. Vanilla small = GHC 5)
    float large_costs[5] = {8, 8, 9, 10};
    int waiting_times[2] = {2, 3};          //The costs here correspond to the given size (Eg. Small size = 2 minutes)
    char toppings_list[50][50] = {"Sprinkles", "Whipped Cream", "Chopped Nuts", "Coconut Shavings"};
    int topping_times[4] = {2, 4, 6, 6};    //The times and costs correspond to the given topping
    float topping_costs[4] = {2, 3, 4, 5};
    int toppings = 0;

    do { 
        printf("1 - Vanilla\t GHC5(small)\t GHC8(large)\n2 - Strawberry\t GHC5(small)\t GHC8(large)\n3 - Chocolate\t GHC6(small)\t GHC9(large)\n4 - Mango\t GHC7(small)\t GHC10(large)\n5 - Enquiries\nFlavour: ");
        scanf("%d", &flavour);  //Customer selects a flavour. This index is decremented for proper indexing (ie. Option 1 is index 0)
        if (flavour == 5) {
            printf("A customer service agent will be with you soon\n"); //Sheesh! Picky customers
        }
        printf("\n1 - small\n2 - large\n");
        scanf("%d", &size); //Customer selects a size. Size is also decremented for proper indexing
        if (flavour < 5) {
            if (size == 1 || size == 2) {
                printf("You've ordered a %s %s ice cream", sizes[size-1], flavours[flavour-1]);

                if (size == 1) {
                    cost += small_costs[flavour - 1];   //Add costs depending on the size selected
                }
                else if(size == 2) {
                    cost += large_costs[flavour - 1];   //Remember that each size for the respective flavours has a 'unique' cost
                }
                time += waiting_times[size - 1];        //Each size also has a different waiting time
            }
            else {
                printf("Invalid size entry \n");
            }
        }
        else if (flavour == 5) {
            printf("A customer service agent will be with you soon\n");
        }
        else {
            printf("Invalid flavour entry\n");
        }
        //Another do-while loop over here
        do {
            printf("\n\tTOPPINGS\n1 - Sprinkles \t\t GHC2\n2 - Whipped Cream\t GHC3\n3 - Chopped Nuts\t GHC4\n4 - Coconut Shavings\t GHC5\nTopping: ");
            scanf("%d", &toppings);
            if (toppings < 5){ 
                printf("You've selected %s toppings\n", toppings_list[toppings-1]);
                cost += topping_costs[toppings - 1];
                time += topping_times[toppings - 1];
            }
            if (toppings == 5) {
                toppings = 0;
            }
            order--;
            }
        while (order > 0);  //Nested do-while loop ends
        int option;
        printf("Would you like to order anything else?\n1 - Yes\n2 - No\nAnswer: "); //If the user selects yes, "order" is incremented and the do-while loop continues
        scanf("%d", &option);
        if (option == 1){
            Sleep(500);  //A delay
            printf("\nYou've ordered a %s %s ice cream with %s topping", sizes[size-1], flavours[flavour-1], toppings_list[toppings-1]); 
            Sleep(500);
            printf("\nWe'll take your new order now.\n\n");
            Sleep(500);
            order ++;
        }
        else if (option == 2){
            order = 0;
            printf("\nYou've ordered a %s %s ice cream with %s topping\n", sizes[size-1], flavours[flavour-1], toppings_list[toppings-1]);
            Sleep(500); 
            printf("We'll be with you in %d minutes\nIn the meantime, be aware that the cost of your meal is %.2f cedis\n", time, cost);
        }
    }
    while(order > 0);
    printf("\n\nKindly wait for your order...");
    int timer;
    for (timer = time; timer >= 0; timer--) {
        Sleep(500);
        if (timer > 1) {
            printf("\n%d minute remaining", timer);
        }
        else if (timer == 1) {
            printf("\n%d minute remaining", timer);
        }
        else {
            printf("\nTime's up");
        }
    }
    printf("\nHere is your order\n Thanks for coming to Churchill's Ice Cream!");
    return 0;
}
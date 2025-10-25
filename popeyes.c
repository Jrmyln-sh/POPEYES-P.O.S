#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void mainMenu();
void foodMenu();
void counter();
void sandwichMenu();
void chickenMealMenu();
void chickenTendersMenu();
void sidesMenu();
void beveragesDessertsMenu();
void cartDisplay();
void payment();
void cash();
void gcash();
void gcashReceipt(float subtotal, float taxAmount, float total, char* referenceID, int transactionID);
int idDiscount(float *discount, float subtotal);
void removeOrder();
void receipt(float subtotal, float discount, float tax, float total, float payment, float change, char* paymentMethod);
void payAtCounter();
void simpleReceipt(float subtotal, float discount, float taxAmount, float total, int orderNum);
void clrscrn();

int serviceMethod = 0;
int orderType = 0;
char cartItems[50][100];
float cartPrices[50];
int cartQty[50];
int cartSize = 0;

int main() {
  srand(time(NULL));
  mainMenu();
}

void mainMenu() {
  char input[100];
  char choose;

  printf("\n\t+--------------------------------------+\n");
  printf("\n\t|          Welcome to Popeyes          |");
  printf("\n\t|      Your journey starts here        |\n");
  printf("\n\t+--------------------------------------+");
  printf("\n\t+-------------------------------+");
  printf("\n\t| Please choose Service Method  |");
  printf("\n\t+-------------------------------+");
  printf("\n\t| [1] Counter                   |");
  printf("\n\t| [2] KIOSK                     |");
  printf("\n\t| [0] Exit                      |");
  printf("\n\t+-------------------------------+\n");
  printf("\n\tChoose: \t");
  scanf(" %c",&choose);


  clrscrn();

  switch(choose) {
  case '1':
    serviceMethod = 1;
    counter();
    break;
  case '2':
    serviceMethod = 2;
    counter();
    break;

  case '0':
  printf("\n\tThank you for choosing us!!");
  exit(0);
    break;

  default:
    printf("\n\tInvalid Choices, Please Try again!\n");
    mainMenu();
    break;
  }

}

void counter() {
  char choose;
  printf("\n\t+-------------------------------+");
  printf("\n\t|    Please choose an option    |");
  printf("\n\t+-------------------------------+");
  printf("\n\t| [1] Eat In                    |");
  printf("\n\t| [2] Take Out                  |");
  printf("\n\t| [0] Back                      |");
  printf("\n\t+-------------------------------+\n");
  printf("\n\tChoose: \t");
  scanf(" %c",&choose);
  
  clrscrn();

  switch (choose) {
  case '1':
    orderType = 1;
    foodMenu();
    break;
  case '2':
    orderType = 2;
    foodMenu();
    break;
  case '0':
    mainMenu();
    break;
  default:
    printf("\n\tInvalid Choices, Please Try again!\n");
    counter();
    break;
  }
}

void foodMenu() {

  char choose;

  printf("\n\t\t\tPopeyes Kitchen\n");
  printf("\n\t--------------------------------------------\n");
  printf("\n\t\t +-----MAIN CATEGORIES-----+\n");
  printf("\n\t[1] Sandwich");
  printf("\n\t[2] Chicken Meal");
  printf("\n\t[3] Chiken Tenders");
  printf("\n\t[4] Sides");
  printf("\n\t[5] Beverages & Desserts");
  printf("\n\t[6] View Cart");
  printf("\n\t[0] <- Back\n");
  printf("\n\t--------------------------------------------\n");
  printf("\n\tPlease select a category (1-5): \t");
  scanf(" %c",&choose);
  
  clrscrn();

  switch (choose) {
  case '1':
    sandwichMenu();
    break;
  case '2':
    chickenMealMenu();
    break;
  case '3':
    chickenTendersMenu();
    break;
  case '4':
    sidesMenu();
    break;
  case '5':
    beveragesDessertsMenu();
    break;
  case '6':
    cartDisplay();
    break;
  case '0':
    counter();
    break;
  default:
    printf("\n\tInvalid Choices, Please Try again!\n");
    foodMenu();
    break;
  }
}

void sandwichMenu() {
  char item;
  char choice;
  int qty;
  char name[100];
  float price;
  float prices[11] = {
    79, 25, 154, 193, 218, 186, 
    211, 166, 191, 40, 65
  };

  printf("\n\t------------------------------------------------\n");
  printf("\n\t\t\tSandwich Menu\n");
  printf("\n\t------------------------------------------------\n");
  printf("\n\t [1] Chicken Burger with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f",prices[0]);
  printf("\n\t     - Add fries\t\t: +P%.2f\n",prices[1]);

  printf("\n\t [2] Original Chicken Sandwich with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f",prices[2]);
  printf("\n\t     - Add fries\t\t: +P%.2f\n",prices[1]);

  printf("\n\t [3] U.S. Spicy Chicken Sandwich with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f",prices[3]);
  printf("\n\t     - with fries\t: P%.2f\n",prices[4]);

  printf("\n\t [4] Chicken French Quarter with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f",prices[5]);
  printf("\n\t     - with fries\t: P%.2f\n",prices[6]);

  printf("\n\t [5] Fish / Shrimp Burger with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f",prices[7]);
  printf("\n\t     - with fries\t: P%.2f\n",prices[8]);
  
  printf("\n\t [6] Upgrade Options:");
  printf("\n\t     - Medium drink&fries\t: +P%.2f",prices[9]);
  printf("\n\t     - Large drink&fries\t: +P%.2f\n",prices[10]);

  printf("\n\t [0] <- Back to Main Categories\n");
  printf("\n\tSelect Item number: \t");
  scanf(" %c",&item);

  clrscrn();

  switch (item) {
  case '1':
    printf("\n\tChicken Burger with Drink - P%.2f\n", prices[0]);
    while (1) {
      printf("\tWould you like to add fries? (+P%.2f) [y/n]: ", prices[1]);
      scanf(" %c", &choice);
      while (getchar() != '\n');
      
      if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter 'y' or 'n'!\n\n");
      }
    }

    while (1) {
     printf("\tQuantity: \t");
     if (scanf("%d", &qty) != 1) {
       while (getchar() != '\n');
       printf("\n\tInvalid Input, Please Try again!\n\n");
       continue;
     }
     break;
    }

    if (choice == 'y' || choice == 'Y') {
      strcpy(name, "Chicken Burger w/ Drink & Fries");
      price = prices[0] + prices[1];
    } else {
      strcpy(name, "Chicken Burger w/ Drink");
      price = prices[0];
    }
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!!");
    getchar();
    getchar();
    
    clrscrn();
    sandwichMenu();
    break;

  case '2':
    printf("\n\tOriginal Chicken Sandwich with Drink - P%.2f\n", prices[2]);
    while (1) {
      printf("\tWould you like to add fries? (+P%.2f) [y/n]: ", prices[1]);
      scanf(" %c", &choice);
      while (getchar() != '\n');
      
      if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter 'y' or 'n'!\n\n");
      }
    }

    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    if (choice == 'y' || choice == 'Y') {
      strcpy(name, "Original Chicken Sandwich w/ Drink & Fries");
      price = prices[2] + prices[1];
    } else {
      strcpy(name, "Original Chicken Sandwich w/ Drink");
      price = prices[2];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!!");
    getchar();
    getchar();
    
    clrscrn();
    sandwichMenu();
    break;

  case '3':
    printf("\n\tU.S. Spicy Chicken Sandwich\n");
    printf("\t[1] With Drink only - P%.2f\n", prices[3]);
    printf("\t[2] With Fries & Drink - P%.2f\n", prices[4]);

    while (1) {
      printf("\tChoose option: ");
      scanf(" %c", &choice);
      while (getchar() != '\n');
      if (choice == '1' || choice == '2') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }

    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "U.S. Spicy Sandwich w/ Drink");
      price = prices[3];
    } else {
      strcpy(name, "U.S. Spicy Sandwich w/ Fries & Drink");
      price = prices[4];
    }
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sandwichMenu();
    break;

  case '4':
    printf("\n\tChicken French Quarter\n");
    printf("\t[1] With Drink only - P%.2f\n", prices[5]);
    printf("\t[2] With Fries & Drink - P%.2f\n", prices[6]);

    while (1) {
      printf("\tChoose option: ");
      scanf(" %c", &choice);
      while (getchar() != '\n');
      if (choice == '1' || choice == '2') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    if (choice == '1') {
      strcpy(name, "French Quarter w/ Drink");
      price = prices[5];
    } else {
      strcpy(name, "French Quarter w/ Fries & Drink");
      price = prices[6];
    }
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sandwichMenu();
    break;

  case '5':
    printf("\n\tFish / Shrimp Burger\n");
    printf("\t[1] With Drink only - P%.2f\n", prices[7]);
    printf("\t[2] With Fries & Drink - P%.2f\n", prices[8]);

    while (1) {
      printf("\tChoose option: ");
      scanf(" %c", &choice);
      while (getchar() != '\n');
      if (choice == '1' || choice == '2') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    if (choice == '1') {
      strcpy(name, "Fish/Shrimp Burger w/ Drink");
      price = prices[7];
    } else {
      strcpy(name, "Fish/Shrimp Burger w/ Fries & Drink");
      price = prices[8];
    }
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!!");
    getchar();
    getchar();
    clrscrn();
    sandwichMenu();
    break;

  case '6':
    printf("\n\tUpgrade Options\n");
    printf("\t[1] Medium Drink & Fries - P%.2f\n", prices[9]);
    printf("\t[2] Large Drink & Fries - P%.2f\n", prices[10]);
    
    while (1) {
      printf("\tChoose option: ");
      scanf(" %c", &choice);
      while (getchar() != '\n');
      if (choice == '1' || choice == '2') {
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    if (choice == '1') {
      strcpy(name, "Upgrade: Medium");
      price = prices[9];
    } else {
      strcpy(name, "Upgrade: Large");
      price = prices[10];
    }
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!!");
    getchar();
    getchar();
    clrscrn();
    sandwichMenu();
    break;

  case '0':
    foodMenu();
    break;
  
  default:
    printf("\n\tInvalid Item, Please Try again!\n");
    sandwichMenu();
    break;
  }
}

void chickenMealMenu() {
  char item;
  char choice;
  int qty;
  char name[100];
  float price;
  float prices[10] = {
    99, 159, 109, 178, 149, 39, 
    50, 48, 5
  };
  printf("\n\t------------------------------------------------\n");
  printf("\n\t\t\tChicken Meal Menu\n");
  printf("\n\t------------------------------------------------\n");

  printf("\n\t [1] 1pc Chicken with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[0]);

  printf("\n\t [2] 1pc Chicken and Spaghetti with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[1]);

  printf("\n\t [3] 1pc Chicken Fillet with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[2]);
  
  printf("\n\t [4] 2pc Chicken with Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[3]);

  printf("\n\t [5] 1pc Chicken with Fries and Drink");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[4]);

  printf("\n\t [6] Add-On Options:");
  printf("\n\t     - KitKat Dessert\t\t: +P%.2f",prices[5]);
  printf("\n\t     - Mashed Potato\t\t: +P%.2f",prices[6]);
  printf("\n\t     - Honey Biscuit\t\t: +P%.2f",prices[7]);
  printf("\n\t     - Upgrade to Spicy\t\t: +P%.2f\n",prices[8]);

  printf("\n\t [0] <- Back to Main Categories\n");
  printf("\n\tSelect Item number: \t");
  scanf(" %c",&item);

  clrscrn();

  switch (item) {
  case '1':
    printf("\n\t1pc Chicken with Drink - P%.2f\n", prices[0]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "1pc Chicken w/ Drink");
    price = prices[0];

    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '2':
    printf("\n\t1pc Chicken and Spaghetti with Drink - P%.2f\n", prices[1]);
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "1pc Chicken & Spaghetti w/ Drink");
    price = prices[1];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '3':
    printf("\n\t1pc Chicken Fillet with Drink - P%.2f\n", prices[2]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "1pc Chicken Fillet w/ Drink");
    price = prices[2];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '4':
    printf("\n\t2pc Chicken with Drink - P%.2f\n", prices[3]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "2pc Chicken w/ Drink");
    price = prices[3];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '5':
    printf("\n\t1pc Chicken with Fries and Drink - P%.2f\n", prices[4]);

    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "1pc Chicken w/ Fries & Drink");
    price = prices[4];

    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '6':
    printf("\n\tAdd-On Options\n");
    printf("\t[1] KitKat Dessert - P%.2f\n", prices[5]);
    printf("\t[2] Mashed Potato - P%.2f\n", prices[6]);
    printf("\t[3] Honey Biscuit - P%.2f\n", prices[7]);
    printf("\t[4] Upgrade to Spicy - P%.2f\n", prices[8]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] >= '1' && input[0] <= '4')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' to '4'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "KitKat Dessert");
      price = prices[5];
    } else if (choice == '2') {
      strcpy(name, "Mashed Potato");
      price = prices[6];
    } else if (choice == '3') {
      strcpy(name, "Honey Biscuit");
      price = prices[7];
    } else {
      strcpy(name, "Spicy Upgrade");
      price = prices[8];
    }
  
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenMealMenu();
    break;

  case '0':
    foodMenu();
    break;
  
  default:
    printf("\n\tInvalid Item, Please Try again!\n");
    chickenMealMenu();
    break;
  }
}

void chickenTendersMenu() {
  char item;
  char choice;
  int qty;
  char name[100];
  float price;
  float prices[7] = {
    695, 160, 130, 191, 357, 523, 30
  };
  printf("\n\t------------------------------------------------\n");
  printf("\n\t\t\tChicken Tenders Menu\n");
  printf("\n\t------------------------------------------------\n");

  printf("\n\t [1] 20Pc Tenders with 6 Dips");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[0]);
  
  printf("\n\t [2] 3pcs Tenders with Drink");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[1]);
  
  printf("\n\t [3] 3Pc Tenders with 1 Dip");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[2]);
  
  printf("\n\t [4] 5Pc Tenders with 2 Dips");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[3]);
  
  printf("\n\t [5] 10Pc Tenders with 3 Dips");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[4]);
  
  printf("\n\t [6] 15Pc Tenders with 5 Dips");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[5]);

  printf("\n\t [7] Drinks");
  printf("\n\t     - For only\t\t\t: P%.2f\n",prices[6]);

  printf("\n\t [0] <- Back to Main Categories\n");
  printf("\n\tSelect Item number: \t");
  scanf(" %c",&item);

  clrscrn();

  switch (item) {
  case '1':
      printf("\n\t20Pc Tenders with 6 Dips - P%.2f\n", prices[0]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "20Pc Tenders w/ 6 Dips");
    price = prices[0];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '2':
    printf("\n\t3pcs Tenders with Drink - P%.2f\n", prices[1]);
  
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "3pcs Tenders w/ Drink");
    price = prices[1];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '3':
    printf("\n\t3Pc Tenders with 1 Dip - P%.2f\n", prices[2]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "3Pc Tenders w/ 1 Dip");
    price = prices[2];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '4':
    printf("\n\t5Pc Tenders with 2 Dips - P%.2f\n", prices[3]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "5Pc Tenders w/ 2 Dips");
    price = prices[3];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '5':
    printf("\n\t10Pc Tenders with 3 Dips - P%.2f\n", prices[4]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "10Pc Tenders w/ 3 Dips");
    price = prices[4];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '6':
    printf("\n\t15Pc Tenders with 5 Dips - P%.2f\n", prices[5]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "15Pc Tenders w/ 5 Dips");
    price = prices[5];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '7':
    printf("\n\tDrinks - P%.2f\n", prices[6]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "Drinks");
    price = prices[6];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    chickenTendersMenu();
    break;

  case '0':
    foodMenu();
    break;
  
  default:
    printf("\n\tInvalid Item, Please Try again!\n");
    chickenTendersMenu();
    break;
  }
}

void sidesMenu() {
  char item;
  char choice;
  int qty;
  char name[100];
  float price;
  float prices[11] = {
    71, 126, 250, 69, 199, 389, 61,
    78, 128, 228, 30
  };
  printf("\n\t------------------------------------------------\n");
  printf("\n\t\t\tSides Menu\n");
  printf("\n\t------------------------------------------------\n");

  printf("\n\t [1] Spaghetti");
  printf("\n\t     - A la Carte\t\t: P%.2f",prices[0]);
  printf("\n\t     - Meal\t\t\t: P%.2f",prices[1]);
  printf("\n\t     - Platter\t\t\t: P%.2f\n",prices[2]);

  printf("\n\t [2] Biscuits");
  printf("\n\t     - Hazelnut White Choco Wafer");
  printf("\n\t     - 1pc\t\t\t: P%.2f",prices[3]);
  printf("\n\t     - Box of 3\t\t\t: P%.2f",prices[4]);
  printf("\n\t     - Box of 6\t\t\t: P%.2f\n",prices[5]);

  printf("\n\t [3] Pies");
  printf("\n\t     - Cinnamon Apple\t\t: P%.2f",prices[6]);
  printf("\n\t     - Strawberry Cheesecake Pie : P%.2f\n",prices[6]);

  printf("\n\t [4] Hot Pops");
  printf("\n\t     - Regular\t\t\t: P%.2f",prices[7]);
  printf("\n\t     - Medium\t\t\t: P%.2f",prices[8]);
  printf("\n\t     - Large\t\t\t: P%.2f\n",prices[9]);

  printf("\n\t [5] Add Drinks");
  printf("\n\t     - For Only\t\t\t: P%.2f\n",prices[10]);

  printf("\n\t [0] <- Back to Main Categories\n");
  printf("\n\tSelect Item number: \t");
  scanf(" %c",&item);

  clrscrn();

  switch (item) {
  case '1':
    printf("\n\tSpaghetti\n");
    printf("\t[1] A la Carte - P%.2f\n", prices[0]);
    printf("\t[2] Meal - P%.2f\n", prices[1]);
    printf("\t[3] Platter - P%.2f\n", prices[2]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] >= '1' && input[0] <= '3')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' to '3'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Spaghetti A la Carte");
      price = prices[0];
    } else if (choice == '2') {
      strcpy(name, "Spaghetti Meal");
      price = prices[1];
    } else {
      strcpy(name, "Spaghetti Platter");
      price = prices[2];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sidesMenu();
    break;

  case '2':
    printf("\n\tBiscuits - Hazelnut White Choco Wafer\n");
    printf("\t[1] 1pc - P%.2f\n", prices[3]);
    printf("\t[2] Box of 3 - P%.2f\n", prices[4]);
    printf("\t[3] Box of 6 - P%.2f\n", prices[5]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] >= '1' && input[0] <= '3')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' to '3'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Hazelnut White Choco Wafer 1pc");
      price = prices[3];
    } else if (choice == '2') {
      strcpy(name, "Hazelnut White Choco Wafer Box of 3");
      price = prices[4];
    } else {
      strcpy(name, "Hazelnut White Choco Wafer Box of 6");
      price = prices[5];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sidesMenu();
    break;

  case '3':
    printf("\n\tPies\n");
    printf("\t[1] Cinnamon Apple - P%.2f\n", prices[6]);
    printf("\t[2] Strawberry Cheesecake Pie - P%.2f\n", prices[7]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] == '1' || input[0] == '2')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Cinnamon Apple Pie");
      price = prices[6];
    } else {
      strcpy(name, "Strawberry Cheesecake Pie");
      price = prices[7];
    }

    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sidesMenu();
    break;

  case '4':
    printf("\n\tHot Pops\n");
    printf("\t[1] Regular - P%.2f\n", prices[8]);
    printf("\t[2] Medium - P%.2f\n", prices[9]);
    printf("\t[3] Large - P%.2f\n", prices[10]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] >= '1' && input[0] <= '3')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' to '3'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Hot Pops Regular");
      price = prices[8];
    } else if (choice == '2') {
      strcpy(name, "Hot Pops Medium");
      price = prices[9];
    } else {
      strcpy(name, "Hot Pops Large");
      price = prices[10];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sidesMenu();
    break;

  case '5':
    printf("\n\tAdd Drinks - P%.2f\n", prices[10]);
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    strcpy(name, "Add Drinks");
    price = prices[10];
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    sidesMenu();
    break;

  case '0':
    foodMenu();
    break;
  
  default:
    printf("\n\tInvalid Item, Please Try again!\n");
    sidesMenu();
    break;
  }
}

void beveragesDessertsMenu() {
  char item;
  char choice;
  int qty;
  char name[100];
  float price;
  float prices[7] = {
    76, 83, 76, 86, 76, 36, 55
  };
  printf("\n\t------------------------------------------------\n");
  printf("\n\t\t\tBeverages & Desserts Menu\n");
  printf("\n\t------------------------------------------------\n");

  printf("\n\t [1] Beverages");
  printf("\n\t     - Lemonade Pineapple\t M: P%.2f  L: P%.2f",prices[0],prices[1]);
  printf("\n\t     - Classic Black\t\t M: P%.2f",prices[2]);
  printf("\n\t     - Choco Malt Spanish Latte\t M: P%.2f",prices[3]);
  printf("\n\t     - Coffee Float\t\t M: P%.2f\n",prices[4]);

  printf("\n\t [2] Desserts");
  printf("\n\t     - Chocolate Caramel Sundae\t: P%.2f",prices[5]);
  printf("\n\t     - Chunky Choco Wafer\t: P%.2f\n",prices[6]);

  printf("\n\t [0] <- Back to Main Categories\n");
  printf("\n\tSelect Item number: \t");
  scanf(" %c",&item);

  clrscrn();

  switch (item) {
  case '1':
    printf("\n\tBeverages\n");
    printf("\t[1] Lemonade Pineapple (M) - P%.2f\n", prices[0]);
    printf("\t[2] Lemonade Pineapple (L) - P%.2f\n", prices[1]);
    printf("\t[3] Classic Black (M) - P%.2f\n", prices[2]);
    printf("\t[4] Choco Malt Spanish Latte (M) - P%.2f\n", prices[3]);
    printf("\t[5] Coffee Float (M) - P%.2f\n", prices[4]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] >= '1' && input[0] <= '5')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' to '5'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Lemonade Pineapple (M)");
      price = prices[0];
    } else if (choice == '2') {
      strcpy(name, "Lemonade Pineapple (L)");
      price = prices[1];
    } else if (choice == '3') {
      strcpy(name, "Classic Black (M)");
      price = prices[2];
    } else if (choice == '4') {
      strcpy(name, "Choco Malt Spanish Latte (M)");
      price = prices[3];
    } else {
      strcpy(name, "Coffee Float (M)");
      price = prices[4];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    beveragesDessertsMenu();
    break;

  case '2':
    printf("\n\tDesserts\n");
    printf("\t[1] Chocolate Caramel Sundae - P%.2f\n", prices[5]);
    printf("\t[2] Chunky Choco Wafer - P%.2f\n", prices[6]);
    
    while (1) {
      char input[100];
      printf("\tChoose option: ");
      scanf("%s", input);
      
      if (strlen(input) == 1 && (input[0] == '1' || input[0] == '2')) {
        choice = input[0];
        break;
      } else {
        printf("\n\tInvalid Input, Please enter '1' or '2'!\n\n");
      }
    }
    
    while (1) {
      printf("\tQuantity: \t");
      if (scanf("%d", &qty) != 1) {
        while (getchar() != '\n');
        printf("\n\tInvalid Input, Please Try again!\n\n");
        continue;
      }
      break;
    }
    
    if (choice == '1') {
      strcpy(name, "Chocolate Caramel Sundae");
      price = prices[5];
    } else {
      strcpy(name, "Chunky Choco Wafer");
      price = prices[6];
    }
    
    strcpy(cartItems[cartSize], name);
    cartPrices[cartSize] = price;
    cartQty[cartSize] = qty;
    cartSize++;
    
    printf("\n\t%s added to cart! (Qty: %d)\n", name, qty);
    printf("\n\tPress Enter to continue!");
    getchar();
    getchar();
    
    clrscrn();
    beveragesDessertsMenu();
    break;

  case '0':
    foodMenu();
    break;
  
  default:
    printf("\n\tInvalid Item, Please Try again!\n");
    beveragesDessertsMenu();
    break;
  }
}

void cartDisplay() {
  char choose;
  float total = 0;
  printf("\n\t-------------------CART------------------");
  if (cartSize == 0) {
    printf("\n\t     Your cart is empty!\n");
  } else {
    printf("\n");
    for (int i = 0; i < cartSize; i++) {
      float subtotal = cartPrices[i] * cartQty[i];
      printf("\t  [%d] %s\n", i + 1, cartItems[i]);
      printf("\t      P%.2f x %d = P%.2f\n\n", cartPrices[i], cartQty[i], subtotal);
      total += subtotal;
    }
    printf("\t  TOTAL AMOUNT: P%.2f\n", total);
  }
  printf("\n\t-----------------------------------------");

  printf("\n\t[1] Add more items");
  printf("\n\t[2] Remove an items");
  printf("\n\t[3] Checkout");
  printf("\n\t[0] Back");
  printf("\n\tChoose: \t");
  scanf(" %c",&choose);

  clrscrn();

  switch (choose) {
  case '1':
    foodMenu();
    break;
  case '2':
    removeOrder();
    break;
  case '3':
    if (cartSize == 0) {
      printf("\n\tCart is empty! Please add items first.\n");
      cartDisplay();
    } else {
      payment();
    }
    break;
  case '0':
    foodMenu();
    break;
  default:
    printf("\n\tInvalid Choices, Please Try again!\n");
    cartDisplay();
    break;
  }

}

void removeOrder() {
  int itemNum;
  char choice;

  if (cartSize == 0) {
  printf("\n\tYour cart is empty!\n");
  cartDisplay();
  return;
  }

  printf("\n\t--------------------------------------\n");
  printf("\t           REMOVE ITEM                  \n");
  printf("\t--------------------------------------\n\n");
  for (int i = 0; i < cartSize; i++) {
    printf("\t  [%d] %s - Qty: %d\n", i + 1, cartItems[i], cartQty[i]);
  }
  printf("\n\t========================================\n");
  printf("\n\tEnter item number to remove (0 to cancel): ");
  scanf("%d", &itemNum);
  if (itemNum == 0) {
    clrscrn();
    cartDisplay();
    return;
  }
  if (itemNum < 1 || itemNum > cartSize) {
    printf("\n\tInvalid item number!\n");
    clrscrn();
    removeOrder();
    return;
  }
  printf("\n\tRemoved: %s\n", cartItems[itemNum - 1]);
  for (int i = itemNum - 1; i < cartSize - 1; i++) {
    strcpy(cartItems[i], cartItems[i + 1]);
    cartPrices[i] = cartPrices[i + 1];
    cartQty[i] = cartQty[i + 1];
  }
  cartSize--;
  cartDisplay();
}

void payment() {
  char choose;

  printf("\n\t+-------------------------------+");
  printf("\n\t|         Payment Option        |");
  printf("\n\t+-------------------------------+");
  if (serviceMethod == 2) {
    printf("\n\t| [1] Pay at the Counter        |");
    printf("\n\t| [2] GCash                     |");
  } else {
    printf("\n\t| [1] Cash                      |");
    printf("\n\t| [2] GCash                     |");
  }
  printf("\n\t| [0] Back                      |");
  printf("\n\t+-------------------------------+\n");
  printf("\n\tChoose: \t");
  scanf(" %c",&choose);

  clrscrn();

  switch (choose) {
  case '1':
    if (serviceMethod == 2) {
      payAtCounter();
    } else {
      cash();
    }
    break;
  case '2':
    gcash();
    break;
  case '0':
    cartDisplay();
    break;
  default:
    printf("\n\tInvalid Choices, Please Try again!\n");
    payment();
    break;
  }
}
void payAtCounter() {
  float subtotal = 0;
  float discount = 0;
  float taxAmount = 0;
  float total = 0;
  
  for (int i = 0; i < cartSize; i++) {
    subtotal += cartPrices[i] * cartQty[i];
  }
  
  int hasDiscount = idDiscount(&discount, subtotal);
  
  clrscrn();
  
  if (hasDiscount) {
    subtotal = subtotal - discount;
    printf("\n\t20%% PWD/Senior Discount Applied: -P%.2f\n", discount);
  }
  taxAmount = subtotal * 0.12;
  total = subtotal + taxAmount;
  
  printf("\n\tSubtotal after discount: P%.2f", subtotal);
  printf("\n\tTax (12%%): P%.2f", taxAmount);
  printf("\n\tTotal Amount: P%.2f\n", total);
  int orderNum = rand() % 9000 + 1000;
  printf("\n\tGenerating order slip...\n");
  printf("\n\tPress Enter to view order slip!");
  getchar();
  getchar();
  
  simpleReceipt(subtotal, discount, taxAmount, total, orderNum);
  
  clrscrn();
  
  printf("\n\t----------------------------------------");
  printf("\n\t        PAYMENT AT THE COUNTER");
  printf("\n\t----------------------------------------");
  printf("\n\tOrder Number: %d", orderNum);
  printf("\n\tTotal Amount: P%.2f", total);
  printf("\n\t----------------------------------------\n");
  
  float payment;
  while (1) {
    printf("\n\tEnter payment amount: P");
    if (scanf("%f", &payment) != 1) {
      while (getchar() != '\n');
      printf("\n\tInvalid Input, Please Try again!\n");
      continue;
    }
    
    if (payment < total) {
      printf("\n\tInsufficient payment! Please enter at least P%.2f\n", total);
      continue;
    }
    
    break;
  }
  
  float change = payment - total;
  
  printf("\n\tPayment: P%.2f", payment);
  printf("\n\tChange: P%.2f\n", change);
  printf("\n\tPayment Successful!\n");
  
  printf("\n\tPress Enter to view final receipt!");
  getchar();
  getchar();
  
  receipt(subtotal, discount, taxAmount, total, payment, change, "Pay at the Counter");
  
  cartSize = 0;
  clrscrn();
  mainMenu();
}

void cash() {
  float subtotal = 0;
  float discount = 0;
  float taxAmount = 0;
  float total = 0;
  
  for (int i = 0; i < cartSize; i++) {
    subtotal += cartPrices[i] * cartQty[i];
  }
  
  int hasDiscount = idDiscount(&discount, subtotal);
  
  clrscrn();
  
  if (hasDiscount) {
    subtotal = subtotal - discount;
    printf("\n\t20%% PWD/Senior Discount Applied: -P%.2f\n", discount);
  }
  
  taxAmount = subtotal * 0.12;
  total = subtotal + taxAmount;
  
  printf("\n\tSubtotal after discount: P%.2f", subtotal);
  printf("\n\tTax (12%%): P%.2f", taxAmount);
  printf("\n\tTotal Amount: P%.2f\n", total);
  
  float payment;
  while (1) {
    printf("\n\tEnter payment amount: P");
    if (scanf("%f", &payment) != 1) {
      while (getchar() != '\n');
      printf("\n\tInvalid Input, Please Try again!\n");
      continue;
    }
    
    if (payment < total) {
      printf("\n\tInsufficient payment! Please enter at least P%.2f\n", total);
      continue;
    }
    
    break;
  }
  
  float change = payment - total;
  
  printf("\n\tPayment: P%.2f", payment);
  printf("\n\tChange: P%.2f\n", change);
  printf("\n\tPayment Successful!\n");
  
  printf("\n\tPress Enter to view receipt!");
  getchar();
  getchar();
  
  receipt(subtotal, discount, taxAmount, total, payment, change, "Cash");
  cartSize = 0;
  clrscrn();
  mainMenu();
}

void gcash() {
  float subtotal = 0;
  float discount = 0;
  float taxAmount = 0;
  float total = 0;
  
  for (int i = 0; i < cartSize; i++) {
    subtotal += cartPrices[i] * cartQty[i];
  }
  
  int hasDiscount = idDiscount(&discount, subtotal);
  
  clrscrn();
  
  if (hasDiscount) {
    subtotal = subtotal - discount;
    printf("\n\t20%% PWD/Senior Discount Applied: -P%.2f\n", discount);
  }
  
  taxAmount = subtotal * 0.12;
  total = subtotal + taxAmount;
  
  printf("\n\tSubtotal after discount: P%.2f", subtotal);
  printf("\n\tTax (12%%): P%.2f", taxAmount);
  printf("\n\tTotal Amount: P%.2f\n", total);
  
  char gcashNumber[12];
  printf("\n\t----------------------------------------");
  printf("\n\t           GCASH PAYMENT");
  printf("\n\t----------------------------------------\n");
  
  while (1) {
    printf("\n\tSend to 09626881002");
    printf("\n\tFrom: ");
    scanf("%s", gcashNumber);
    if (strlen(gcashNumber) != 11) {
      printf("\n\tInvalid! GCash number must be 11 digits.\n");
      continue;
    }
    
    int valid = 1;
    for (int i = 0; i < 11; i++) {
      if (gcashNumber[i] < '0' || gcashNumber[i] > '9') {
        valid = 0;
        break;
      }
    }
    
    if (!valid) {
      printf("\n\tInvalid! Please enter numbers only.\n");
      continue;
    }
    
    break;
  }
  
  char referenceID[14];
  for (int i = 0; i < 13; i++) {
    referenceID[i] = '0' + (rand() % 10);
  }
  referenceID[13] = '\0';
  
  int transactionID = rand() % 90000000 + 10000000;
  
  printf("\n\t----------------------------------------");
  printf("\n\tAmount to Pay: P%.2f", total);
  printf("\n\t----------------------------------------");
  
  char confirm;
  while (1) {
    char input[100];
    printf("\n\tConfirm payment? [y/n]: ");
    scanf("%s", input);
    
    if (strlen(input) == 1 && (input[0] == 'y' || input[0] == 'Y')) {
      confirm = input[0];
      break;
    } else if (strlen(input) == 1 && (input[0] == 'n' || input[0] == 'N')) {
      confirm = input[0];
      break;
    } else {
      printf("\n\tInvalid Input, Please enter 'y' or 'n'!\n");
    }
  }
  
  if (confirm == 'n' || confirm == 'N') {
    printf("\n\tPayment cancelled!\n");
    printf("\n\tPress Enter to return to payment menu!");
    getchar();
    getchar();
    clrscrn();
    payment();
    return;
  }
  
  printf("\n\tProcessing payment");
  for (int i = 0; i < 3; i++) {
    printf(".");
    fflush(stdout);
    for (long j = 0; j < 100000000; j++);
  }
  
  printf("\n\n\tPayment Successful!");
  printf("\n\tGCash Transaction Complete!\n");
  
  printf("\n\tPress Enter to view GCash receipt!");
  getchar();
  getchar();
  
  gcashReceipt(subtotal, taxAmount, total, referenceID, transactionID);
  
  float payment = total;
  float change = 0.00;
  
  receipt(subtotal, discount, taxAmount, total, payment, change, "GCash");
  cartSize = 0;
  clrscrn();
  mainMenu();
}

int idDiscount(float *discount, float subtotal) {
  char choice;
  
  while (1) {
    char input[100];
    printf("\n\tDo you have PWD/Senior ID? [y/n]: ");
    scanf("%s", input);
    if (strlen(input) == 1 && (input[0] == 'y' || input[0] == 'Y')) {
      choice = input[0];
      break;
    } else if (strlen(input) == 1 && (input[0] == 'n' || input[0] == 'N')) {
      choice = input[0];
      break;
    } else {
      printf("\n\tInvalid Input, Please enter 'y' or 'n'!\n");
    }
  }

  if (choice == 'y' || choice == 'Y') {
    *discount = subtotal * 0.20;
    return 1;
  }
  *discount = 0.00;
  return 0;
}

void gcashReceipt(float subtotal, float taxAmount, float total, char* referenceID, int transactionID) {
  clrscrn();
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char dateStr[50];
  int hour = t->tm_hour;
  char* ampm = "AM";
  if (hour >= 12) {
    ampm = "PM";
    if (hour > 12) hour -= 12;
  }
  if (hour == 0) hour = 12;
  sprintf(dateStr, "%02d %02d %d %02d:%02d %s", 
          t->tm_mon + 1, t->tm_mday, t->tm_year + 1900, 
          hour, t->tm_min, ampm);
  printf("\n\n\t\t========================================");
  printf("\n\t\t          GCASH PAYMENT RECEIPT");
  printf("\n\t\t========================================\n");
  
  printf("\n\t\t              POPEYES");
  printf("\n\t\t            09626881002\n");
  
  printf("\n\t\t========================================\n");
  
  printf("\n\t\t  AMOUNT:              P%.2f", subtotal);
  printf("\n\t\t  TAX (12%%):           P%.2f", taxAmount);
  printf("\n\t\t  ------------------------------------");
  printf("\n\t\t  TOTAL AMOUNT:        P%.2f\n", total);
  
  printf("\n\t\t========================================\n");
  
  printf("\n\t\t  REF ID: %s", referenceID);
  printf("\n\t\t  DATE: %s", dateStr);
  printf("\n\t\t  TRANSACTION ID: %d\n", transactionID);
  
  printf("\n\t\t========================================");
  printf("\n\t\t        Payment Successful!");
  printf("\n\t\t      Thank you for using GCash");
  printf("\n\t\t========================================\n");
  
  printf("\n\t\tPress Enter to next receipt!");
  getchar();
  getchar();
}

void simpleReceipt(float subtotal, float discount, float taxAmount, float total, int orderNum) {
  clrscrn();
  
  printf("\n\n\t\t========================================");
  printf("\n\t\t          POPEYES - ORDER SLIP");
  printf("\n\t\t========================================\n");
  
  if (serviceMethod == 1) {
    printf("\n\t\tService Method: Counter");
  } else {
    printf("\n\t\tService Method: KIOSK");
  }
  
  if (orderType == 1) {
    printf("\n\t\tOrder Type: Eat In");
  } else {
    printf("\n\t\tOrder Type: Take Out");
  }
  
  printf("\n\t\tOrder Number: %d", orderNum);
  
  printf("\n\n\t\t----------------------------------------");
  printf("\n\t\t            ORDER DETAILS");
  printf("\n\t\t----------------------------------------\n\n");
  
  for (int i = 0; i < cartSize; i++) {
    printf("\t\t%dx %s\n", cartQty[i], cartItems[i]);
    printf("\t\t                        P%.2f\n\n", cartPrices[i] * cartQty[i]);
  }
  
  printf("\t\t-----------------------------------------\n");
  float originalSubtotal = 0;
  for (int i = 0; i < cartSize; i++) {
    originalSubtotal += cartPrices[i] * cartQty[i];
  }
  
  printf("\t\tSubtotal:            P%.2f\n", originalSubtotal);
  
  if (discount > 0) {
    printf("\t\tPWD/Senior Discount: -P%.2f\n", discount);
    printf("\t\tDiscounted Subtotal: P%.2f\n", subtotal);
  }
  
  printf("\t\tVAT (12%%):           P%.2f\n", taxAmount);
  printf("\t\tTOTAL:               P%.2f\n", total);
  
  printf("\t\t   Please proceed to the counter");
  printf("\n\t\t        to complete payment\n");;
  
  printf("\n\t\tPress Enter to proceed to payment!");
  getchar();
  getchar();
}

void receipt(float subtotal, float discount, float taxAmount, float total, float payment, float change, char* paymentMethod) {
  int snNum = 1;
  int orderNum = rand() % 9000 + 1000;
  int transactionNo = rand() % 90000000 + 10000000;
  long long tin = ((long long)rand() * rand()) % 1000000000000LL;
  
  char validationCode[17];
  for (int i = 0; i < 16; i++) {
    validationCode[i] = '0' + (rand() % 10);
  }
  validationCode[16] = '\0';
  clrscrn();
  printf("\n\n\t\t       --- Check Closed ---");
  printf("\n\n\t\t           POPEYES SM FAIRVIEW");
  printf("\n\n\t\t           PLK PHILIPPINES INC.");
  printf("\n\n\t\tAX 041-044 SM CITY FAIRVIEW GREATER LAGRO");
  printf("\n\n\t\t               QUEZON CITY");
  printf("\n\n\t\t       VAT REG TIN: 010-026-709-017");
  printf("\n\n\t\t    S/N: R70376 MIN: 21072316211862774");
  printf("\n\n\t\t   PERMIT NO: FP072021-028-0296440-00017");
  printf("\n\n\t\t               SALES INVOICE");
  
  printf("\n\n\t\tS.I.# %d", snNum);
  printf("\n\n\t\t                   %d", orderNum);;
  if (serviceMethod == 1) {
    printf("\n\n\t\tService: Counter");
  } else {
    printf("\n\n\t\tService: KIOSK");
  }
  
  if (orderType == 1) {
    printf("\n\n\t\tOrder Type: Eat In");
  } else {
    printf("\n\n\t\tOrder Type: Take Out");
  }
  
  printf("\n\n");
  for (int i = 0; i < cartSize; i++) {
    printf("\t\t%dx %s\n", cartQty[i], cartItems[i]);
    printf("\t\t                              P%.2f\n", cartPrices[i] * cartQty[i]);
  }
  
  printf("\n\n\t\t----------------------------------------");
  printf("\n\n\t\tWe want to hear from you.");
  printf("\n\n\t\tVisit www.tellpopeyes.com");
  printf("\n\n\t\tEnter Code");
  printf("\n\n\t\t%s", validationCode);
  printf("\n\n\t\tEnjoy a Treat on us when you");
  printf("\n\n\t\tpresent this receipt with");
  printf("\n\n\t\tvalidation code");
  printf("\n\n\t\tValid 30 Days after Login");
  printf("\n\n\t\t----------------------------------------");
  
  if (orderType == 1) {
    printf("\n\n\t\tEat In Total: P%.2f", total);
  } else {
    printf("\n\n\t\tTake Out Total: P%.2f", total);
  }
  
  printf("\n\n\t\t%s", paymentMethod);
  printf("\n\n\t\tChange: \tP%.2f", change);
  printf("\n\n\t\tTransaction No.: %d", transactionNo);
  printf("\n\n\t\tVAT AMOUNT: P%.2f", taxAmount);
  printf("\n\n\t\tCUST NAME: ");
  printf("\n\n\t\tADDRESS: ");
  printf("\n\n\t\tTIN: ");
  printf("\n\n\t\tBUS STYLE: ");
  printf("\n\n\t\t           NCR Corporation. (PHILIPPINES)");
  printf("\n\n\t\t                TIN: %012lld", tin);
  printf("\n\n\t\t        17TH FLR 6788 Ayala Ave. Makati City");
  printf("\n\n\t\t            Acc: 1160001666052014060010");
  printf("\n\n\t\t   Date Issued:07/17/2014 Valid Until:07/31/2025");
  printf("\n\n\t\t       THIS RECEIPT SHALL BE VALID FOR FIVE");
  printf("\n\n\t\t          YEARS OF THE DATE OF PERMIT USE");
  
  printf("\n\n\t\tPress Enter to Another Transaction!");
  getchar();
  getchar();
}

void clrscrn() {
  system("cls");
}




// File Name: assign7_asr36.cpp
//
// Author Name: Ayisha S. R. Sowkathali
// Date: 11/30/2015
// Assignment Number: 7
// CS 1428.004 Fall 2015
// Instructor: Jill Seaman
//
// This program simulates a soft drink machine using
// structures, functions and arrays.

#include <iostream>
#include <iomanip>
using namespace std;

// Variety of drinks available in the vending machine.
const int NUM_OF_DRINKS = 5;

/* Structure of vending machine containing names of 
 each drinks, its cost and the initial quantity of 
 each drinks available in the vending machine. */
struct vendMachine {
    string name;
    double cost;
    int units;
};

// Function Prototypes:
void displayMenu(vendMachine menu[]);
int userOption(vendMachine menu[]);
double costPerDrink(vendMachine cost[], int &);

int main()
{
    // declaration of the strunture variables.
    vendMachine drinks[NUM_OF_DRINKS] = {
        {"1. coke (can)", 0.75, 10},
        {"2. coke (bottle)", 1.25, 10},
        {"3. Mountain Dew (can)", 0.75, 10},
        {"4. Water", 1.25, 10},
        {"5. Full Throttle", 2.00, 10}
    };

    int choice;             // Choice entered by the user
    double priceOfDrink=0;  // Price of each drink from the function
    double amountEarned=0;  // Amount earned by the machine
    
    cout << fixed << setprecision(2);
    
    do{
        
        // Function Call
        displayMenu(drinks);
    
        choice = userOption(drinks);

        priceOfDrink = costPerDrink(drinks, choice);
        
        amountEarned += priceOfDrink;
       
    } while (choice!=6);
    
    cout << "Amount Earned: " << "$" << amountEarned;
    cout << endl;
    
    return 0;
}

/* Function definition to display the list 
 of drinks available in the vending machine.*/
void displayMenu(vendMachine menu[]){
    for (int i=0; i<NUM_OF_DRINKS;i++) {
        cout << menu[i].name << endl;
    }
    cout << "6. Quit the Program " << endl;
    cout << endl;
}

/* Function definition to enter user choice of drink. */
int userOption(vendMachine num[]){
    int option;
    cout << "Enter your choice: ";
    cin >> option;
    while(option<1||option>6) {
        cout << "!!Invalid Choice!!/nEnter Choice (1-6): ";
        cin >> option;
    }
    return option;
}

/* Function definition to calculate the cost of each drink and 
 to let the user know whether the choice of drink is available 
 or not. */
double costPerDrink(vendMachine drinks[], int &option){

    int choice = option-1;
    
    drinks[choice].units = drinks[choice].units - 1;
    
    if (drinks[choice].units>0 && drinks[choice].units!=6)
        cout << "The cost is : $" << drinks[choice].cost
        << endl << endl;
    
    if (drinks[choice].units<=0 && drinks[choice].units!=6)
        cout << "The choice is Sold out" << endl << endl;
    
    return drinks[choice].cost;
}


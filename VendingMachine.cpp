/*
    Richard Phan

    This program simulates a vending machine that holds various drinks. The User is able to select what type of drink they would like,
    as well as how much money is inserted into the machine. Input validation for this program does not deliver a drink to the user 
    if the money inserted is  < the price of selected drink.

    3/14/24

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold drink information
struct Drink {
    string name;
    double cost = 0.0; 
    int quantity = 0;
};

class DrinkMachine {
private: 
    Drink drinks[5]; // Array to store drink information
    double totalMoneyCollected;

    // Private member functions
    void inputMoney(int choice);
    void dailyReport();

public: //These are the member fcns that int main can access
    DrinkMachine(); // Constructor
    void displayChoices(); // Display menu of drink names and prices
    void buyDrink(int choice); // Handles beverage purchase
    ~DrinkMachine(); // Destructor
};

// Constructor to initialize drinks array
DrinkMachine::DrinkMachine() {
    drinks[0] = { "Cola", 1.00, 20 };
    drinks[1] = { "Root beer", 1.00, 20 };
    drinks[2] = { "Orange soda", 1.00, 20 };
    drinks[3] = { "Grape soda", 1.00, 20 };
    drinks[4] = { "Bottled water", 1.50, 20 };
    totalMoneyCollected = 0.0;
}

// Display menu of drink names and prices
void DrinkMachine::displayChoices() {
    cout << "Drink Choices:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << drinks[i].name << " - $" << fixed << setprecision(2) << drinks[i].cost << endl;
    }
}

// Handle drink purchase
void DrinkMachine::buyDrink(int choice) {
    cout << "You selected: " << drinks[choice - 1].name << endl;
    inputMoney(choice); // Call inputMoney function
}

// Accept, validate, and return the amount of money input
void DrinkMachine::inputMoney(int choice) {
    double money;
    cout << "\nPlease insert money: $";
    cin >> money;

    if (money < drinks[choice - 1].cost) {
        cout << "Insufficient funds." << endl;
        cout << "CLINK! CLANK!" << endl;
        cout << "Your money has been returned by the coin return!" << endl;
    }
    else if (drinks[choice - 1].quantity == 0) {
        cout << "Sorry, " << drinks[choice - 1].name << " is sold out! Here is your money back." << endl;
    }
    else {
        cout << endl;
        cout << "KERTHUNK! An ice cold beverage fell down. \n";
        cout << "Here is your " << drinks[choice - 1].name << "! Enjoy!" << endl;
        totalMoneyCollected += drinks[choice - 1].cost;
        drinks[choice - 1].quantity--;
    }
}

// Destructor to report remaining drinks and total money collected
DrinkMachine::~DrinkMachine() {
    cout << "\nInventory Report:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Remaining " << drinks[i].name << ": " << drinks[i].quantity << endl;
    }
    cout << "Total money collected: $" << fixed << setprecision(2) << totalMoneyCollected << endl;
}

int main() { //IMPORTANT REMOVE 1 FROM MAIN B4 SUBMISSION
    DrinkMachine machine; // Create DrinkMachine object

    int choice;
    do {
        cout << "\nHello! Would you like something cold to drink?" << endl;
        cout << "Here are our drink options: " << endl;
        cout << setfill('-') << setw(40) << "" << endl;
        machine.displayChoices(); // Display choices and get user input
        cout << "Enter your choice (1-5) or 0 to quit: ";
        cin >> choice;

        // Process user choice
        if (choice >= 1 && choice <= 5) {
            machine.buyDrink(choice);
        }
        else if (choice != 0) {
            cout << "Invalid choice. Please enter a valid number (1-5) or 0 to quit." << endl;
        }
    } while (choice != 0);

    return 0;
}

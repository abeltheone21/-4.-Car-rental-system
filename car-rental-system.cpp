#include <iostream>   // standard input/output
#include <cstdlib>    // for system("cls")
#include <vector>     // to use vector container
#include <string>     // to use strings

using namespace std;

// Car struct to store car information
struct Car {
    int id;
    string brand;
    string model;
    string plateNumber;
    bool isAvailable;
    double pricePerDay;
};

vector<Car> carList;

// Function declarations
void showAvailableCars();
void customerMenu();
void managerMenu();
void rentalstat();
void addNewCar();
int mainmenu();
void initializeCarList();
void carRent();
void viewRentalStatus();
void manage_check_point();

int mainmenu() {
    int choice;
    system("cls");

    cout << " ======================================" << endl;
    cout << "|   Welcome to Car Rental System       |" << endl;
    cout << "|======================================|" << endl;
    cout << "|  1. View Available Cars              |" << endl;
    cout << "|  2. Customer                         |" << endl;
    cout << "|  3. Manager                          |" << endl;
    cout << "|  4. Exit                             |" << endl;
    cout << " ======================================" << endl;
    cout << "\nPlease enter your choice (1-4): ";
    cin >> choice;

    return choice;
}

// Initialize the car list
void initializeCarList() {
    carList.clear();

    // Create car objects and push them back to the vector
    Car c1 = {1, "Toyota", "Corolla", "TOY123", true, 50.0};
    Car c2 = {2, "Honda", "Civic", "HON456", true, 70.0};
    Car c3 = {3, "Ford", "Focus", "FOR789", true, 60.0};
    Car c4 = {4, "BMW", "X5", "BMW101", true, 90.0};
    Car c5 = {5, "Mercedes", "C-Class", "MER202", true, 100.0};
    Car c6 = {6, "Audi", "A4", "AUD303", true, 150.0};
    Car c7 = {7, "Hyundai", "Tucson", "HYU404", true, 57.0};
    Car c8 = {8, "Kia", "Sportage", "KIA505", true, 52.0};
    Car c9 = {9, "Nissan", "Altima", "NIS606", true, 90.0};
    Car c10 = {10, "Volkswagen", "Tiguan", "VOL707", true, 60.0};
    //this will add the valuees stord to the end of the vectore 
    carList.push_back(c1);
    carList.push_back(c2);
    carList.push_back(c3);
    carList.push_back(c4);
    carList.push_back(c5);
    carList.push_back(c6);
    carList.push_back(c7);
    carList.push_back(c8);
    carList.push_back(c9);
    carList.push_back(c10);
}

// Show all cars (both available and rented) with aligned columns
void showAvailableCars() {
    system("cls");
    cout << "==================== AVAILABLE CARS ====================\n";
    cout << "ID   Brand        Model        Plate      Price   Status\n";
    cout << "=========================================================\n";

    for (int i = 0; i < carList.size(); i++) {
        Car car = carList[i];
        cout << car.id << "    ";
        
        cout << car.brand;
        for (int s = car.brand.length(); s < 12; s++) cout << " ";
        
        cout << car.model;
        for (int s = car.model.length(); s < 12; s++) cout << " ";
        
        cout << car.plateNumber;
        for (int s = car.plateNumber.length(); s < 11; s++) cout << " ";
        
        cout << car.pricePerDay << "   ";

        if(car.isAvailable){
            cout << "Available";
        } else {
            cout << "Rented";
        }
        cout << endl;
    }

    cout << "=========================================================\n";
    char go_back;
    cout << "Enter X to go back to the main menu: ";
    cin >> go_back;
    if(go_back == 'x' || go_back == 'X'){
        return;
    }
}

// Manager adds new cars
void addNewCar() {
    Car newCar;
    system("cls");
    cout << "|============|\n";
    cout << "| ADD NEW CAR |\n";
    cout << "|============|\n";

    newCar.id = carList.size() + 1;

    cout << "Enter brand: ";
    cin >> newCar.brand;

    cout << "Enter model: ";
    cin >> newCar.model;

    cout << "Enter plate number: ";
    cin >> newCar.plateNumber;

    cout << "Enter price per day: ";
    cin >> newCar.pricePerDay;

    newCar.isAvailable = true;

    carList.push_back(newCar);
    cout << "\nCar added successfully!\n";

    char go_back;
    cout << "Enter X to go back to the main menu: ";
    cin >> go_back;
    if(go_back == 'x' || go_back == 'X'){
        return;
    }
}

// Rent a car: show available cars, let customer pick one, mark as rented
void carRent() {
    system("cls");
    cout << "|==================== RENT A CAR ========================|\n";
    cout << "ID   Brand        Model        Plate      Price   Status\n";
    cout << "|========================================================|\n";
	//this section will if the car is rented or not and if not rented display the cars with thair states
    for (int i = 0; i < carList.size(); i++) {
        if (carList[i].isAvailable) {
            cout << carList[i].id << "    ";
            
            cout << carList[i].brand;
            for (int s = carList[i].brand.length(); s < 12; s++) cout << " ";
            
            cout << carList[i].model;
            for (int s = carList[i].model.length(); s < 12; s++) cout << " ";
            
            cout << carList[i].plateNumber;
            for (int s = carList[i].plateNumber.length(); s < 11; s++) cout << " ";
            
            cout << carList[i].pricePerDay << "   Available" << endl;
        }
    }

    cout << " ===========================================================\n";

    int chosenId;
    cout << "\nEnter the ID of the car you want to rent: ";
    cin >> chosenId;

    bool found = false;
    for (int i = 0; i < carList.size(); i++) {
        if (carList[i].id == chosenId && carList[i].isAvailable) {
            carList[i].isAvailable = false;
            cout << "\nYou successfully rented: " << carList[i].brand << " " << carList[i].model << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nCar not available or invalid ID.\n";
    }
    char go_back;
    cout << "Enter X to go back to the main menu: ";
    cin >> go_back;
    if(go_back == 'x' || go_back == 'X'){
        return;
    }
}

// Manager views rental status (all cars with status)
void viewRentalStatus() {
    system("cls");
    cout << "|==================== RENTAL STATUS ======================|\n";
    cout << "ID   Brand        Model        Plate      Price   Status\n";
    cout << "|=========================================================|\n";

    for (int i = 0; i < carList.size(); i++) {
        cout << carList[i].id << "    ";
        cout << carList[i].brand;
        for (int s = carList[i].brand.length(); s < 12; s++) cout << " ";
        cout << carList[i].model;
        for (int s = carList[i].model.length(); s < 12; s++) cout << " ";
        cout << carList[i].plateNumber;
        for (int s = carList[i].plateNumber.length(); s < 11; s++) cout << " ";
        cout << carList[i].pricePerDay << "   ";

        if(carList[i].isAvailable) {
            cout << "Available";
        } else {
            cout << "Rented";
        }
        cout << endl;
    }

    cout << "==========================================================\n";

    char go_back;
    cout << "Enter X to go back to the main menu: ";
    cin >> go_back;
    if(go_back == 'x' || go_back == 'X'){
        return;
    }
}

// wrapper for rental status
void rentalstat() {
    viewRentalStatus();
}

// Manager login check
void manage_check_point(){
    system("cls");
    string managerPassword;
    cout << "======= Manager login =============" << endl;
    cout << "Enter the password: ";
    cin >> managerPassword;
    if(managerPassword == "abel01" || managerPassword == "miki02"){
        managerMenu();
    }
    else{
        cout << "\nIncorrect password\n";
        system("pause");
    }
}

// Manager menu
void managerMenu() {
    int choice;
    system("cls");

    cout << "|======================================================|\n";
    cout << "|                Welcome Manager!!                     |\n";
    cout << "|======================================================|\n";
    cout << "|  1. Add Car                                          |\n";
    cout << "|  2. View Rental Status                               |\n";
    cout << "|  3. Main Menu                                        |\n";
    cout << "|======================================================|\n";
    cout << "\nPlease enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            addNewCar();
            break;
        case 2:
            rentalstat();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            char go_back;
            cout << "Enter X to go back to the main menu: ";
            cin >> go_back;
            if(go_back == 'x' || go_back == 'X'){
                return;
            }
    }
}

// Customer menu THIS WILL ALLOW THE CUSTEMER TO  VIEW AVAILABLE CARS ,Rent a car and main menu
void customerMenu() {
    int choice;
    system("cls");

    cout << "|=========================================|\n";
    cout << "|    Welcome to Customer Service          |\n";
    cout << "|=========================================|\n";
    cout << "|  1. View Available Cars                 |\n";
    cout << "|  2. Rent a Car                          |\n";
    cout << "|  3. Main Menu                           |\n";
    cout << " =========================================\n";
    cout << "\nPlease enter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            showAvailableCars();
            break;
        case 2:
            carRent();
            break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Returning to main menu.\n";
            return;
    }
}

int main() {
    initializeCarList();

    int user_input;

    while (true) {
        user_input = mainmenu();
        system("cls");

        switch (user_input) {
            case 1:
                showAvailableCars();
                break;
            case 2:
                customerMenu();
                break;
            case 3:
                manage_check_point();
                break;
            case 4:
                cout << "You have exited the program. Thank you!\n";
                return 0;
            default:
                char go_back;
                cout << "Incorrect choice. Enter x to go back to the main menu:\n";
                cin >> go_back;
                if(go_back == 'x' || go_back == 'X'){
                    break;
                }
        }
        system("cls");
    }

    return 0;
}


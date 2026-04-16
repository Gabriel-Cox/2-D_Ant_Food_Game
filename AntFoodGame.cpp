// AntFoodGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void showMenu();

int main()
{
    //Create constants for grid size, amount of food, ant, food, and empty
    const int GRID_COLUMNS = 30;
    const int GRID_ROWS = 20;
    const int AMOUNT_OF_FOOD = 40;
    const char ANT = 'A';
    const char FOOD = 'F';
    const char EMPTY = '.';
    //Seed a random number
    int timeSince1970 = time(0);
    srand(timeSince1970);
    //Create an empty grid. We will populate it with ant and food later.
    char grid[GRID_COLUMNS][GRID_ROWS];
    for (int y = 0; y < GRID_ROWS; y++) {
        for (int x = 0; x < GRID_COLUMNS; x++) {
            grid[x][y] = EMPTY;
        }
    }
    //Find ant coordinates on the grid.
    int antXCoordinates = rand() % GRID_COLUMNS;
    int antYCoordinates = rand() % GRID_ROWS;
    grid[antXCoordinates][antYCoordinates] = ANT;
    //Find the food coordinates and make sure they are not the
    //same as the ant coordinates or any other food coordinates
    int foodXCoordinates;
    int foodYCoordinates;
    for (int i = 0; i < AMOUNT_OF_FOOD; i++) {
        foodXCoordinates = rand() % GRID_COLUMNS;
        foodYCoordinates = rand() % GRID_ROWS;
        while ((grid[foodXCoordinates][foodYCoordinates] == ANT) || (grid[foodXCoordinates][foodYCoordinates] == FOOD)) {
            foodXCoordinates = rand() % GRID_COLUMNS;
            foodYCoordinates = rand() % GRID_ROWS;
        }
        grid[foodXCoordinates][foodYCoordinates] = FOOD;
    }

    // The Game!
    int points = 0;
    char choice;
    cout << "You are the ant (A)! Collect all of the food (F) to win!" << endl;
    do {
        showMenu();
        for (int i = 0; i < (GRID_COLUMNS + 2); i++) {
            cout << "-";
        }
        cout << endl;
        for (int y = 0; y < GRID_ROWS; y++) {
            cout << "|";
            for (int x = 0; x < GRID_COLUMNS; x++) {
                cout << grid[x][y];
            }
            cout << "|" << endl;
        }
        for (int i = 0; i < (GRID_COLUMNS + 2); i++) {
            cout << "-";
        }
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(999, '\n');
        if (choice == '1') {
            grid[antXCoordinates][antYCoordinates] = EMPTY;
            antYCoordinates--;
        }
        else if (choice == '2') {
            grid[antXCoordinates][antYCoordinates] = EMPTY;
            antYCoordinates++;
        }
        else if (choice == '3') {
            grid[antXCoordinates][antYCoordinates] = EMPTY;
            antXCoordinates--;
        }
        else if (choice == '4') {
            grid[antXCoordinates][antYCoordinates] = EMPTY;
            antXCoordinates++;
        }
        else if (choice != '5') {
            system("cls");
            cout << "Sorry we didn't understand that input." << endl;
            continue;
        }
        system("cls");
        // If the ant goes off the grid one way or the other, have it reappear on the other side.
        if (antXCoordinates == GRID_COLUMNS) {
            antXCoordinates = 0;
        }
        if (antXCoordinates < 0) {
            antXCoordinates = GRID_COLUMNS - 1;
        }
        if (antYCoordinates == GRID_ROWS) {
            antYCoordinates = 0;
        }
        if (antYCoordinates < 0) {
            antYCoordinates = GRID_ROWS - 1;
        }
        if (grid[antXCoordinates][antYCoordinates] == FOOD) {
            points++;
            grid[antXCoordinates][antYCoordinates] = ANT;
        }
        else {
            grid[antXCoordinates][antYCoordinates] = ANT;
        }
    } while (points != AMOUNT_OF_FOOD && choice != '5');
    for (int i = 0; i < (GRID_COLUMNS + 2); i++) {
        cout << "-";
    }
    cout << endl;
    for (int y = 0; y < GRID_ROWS; y++) {
        cout << "|";
        for (int x = 0; x < GRID_COLUMNS; x++) {
            cout << grid[x][y];
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < (GRID_COLUMNS + 2); i++) {
        cout << "-";
    }
    cout << endl;
    cout << "GAME OVER!" << endl;
    cout << "Starting food: " << AMOUNT_OF_FOOD << endl;
    cout << "You collected " << points << " of them!" << endl;
    if (points == AMOUNT_OF_FOOD) {
        cout << "VICTORY!" << endl;
    }


}

void showMenu() {
    cout << "1. Move Up " << endl;
    cout << "2. Move Down " << endl;
    cout << "3. Move Left " << endl;
    cout << "4. Move Right " << endl;
    cout << "5. Exit " << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

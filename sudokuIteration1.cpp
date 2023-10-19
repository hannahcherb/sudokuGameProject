// Name: Hannah Cherb
// Program Description: Sudoku Game :D
// ^^ add more later


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
// header file with all the boards

using namespace std;

class game // header file with all the boards that the class inherits
{
private:

    int choice; // level of difficulty users choose

public:

    void getChoice()
    {
       // Menu 
       // Code a menu system for the user (basic shell of what the program 
       // will be)

        cout << "Welcome to Royal Blue Sudoku! You can play a 9*9 sudoku game of" << endl;
        cout << "three difficulty levels: easy, medium, or hard. Please choose a" << endl;
        cout << "difficulty level below." << endl;

        cout << "1 - Easy" << endl;
        cout << "2 - Medium" << endl;
        cout << "3 - Hard" << endl;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // send them to easy level
            displayBoard();
        }
        else if (choice == 2)
        {
            // send them to medium level
            displayBoard();
        }
        else if (choice == 3)
        {
            // send them to hard level
            displayBoard();
        }
        else
        {
            // send them back to menu and tell them to try again
            system("cls"); // better way ? find
            getChoice();
        }
    }

    int sudokuBoard1A[9][9] =
    {
         {0, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 1, 0, 0, 0},
         {0, 7, 8, 0, 0, 0, 0, 0, 1},
         {0, 0, 4, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 2, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };


    void displayBoard()
    {
        // clear screen from menu
        system("cls");

    
       // display board
        cout << "ROYAL BLUE SUDOKU" << endl; // title
        cout << "-------------------------" << endl; // top of board
        
        // i --> rows
        // x --> columns
        // use for loop + nested for loop to display sudokuBoard1A
        for (int i = 0; i < 9; i++)
        {
            cout << "| "; // row line
            for (int x = 0; x < 9; x++)
            {
                if (sudokuBoard1A[i][x] == 0) // if the box is empty
                {
                    cout << " "; // print a blank space
                } 
                else
                {
                    cout << sudokuBoard1A[i][x]; // print numbers
                }

                if (x % 3 == 2) // if uou're on the LAST COLUMN in 3*3 box, print the bar
                {
                    cout << " | "; // create the 3*3 boxes
                }
                else 
                {
                    cout << " "; // add space between numbers (without it's uneven)
                }
                    
            }
            cout << endl;

            if (i % 3 == 2) // if you're on the LAST ROW in 3*3 box, print the bar
            {
                cout << "-------------------------" << endl; // bottom board
            }
        }
    }

    // collect user input + check rules

    // bool function to check if a number is valid by row and column

    // bool function to check if board is full

    // void function to play the game, upon conditions of first 2



};



int main()
{

    // Make object of class
    game details;

    // Call menu selection and get level choice
    details.getChoice();
    

    // collect choice
    int row, col, num;
    cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;

    while (true) // find better way than this
    {
        cin >> row >> col >> num; // get user input
        // if they enter a number that is not 1-9
        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
        {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        // This needs to work in order for the board to keep displaying
        //if (sudokuboard[row - 1][col - 1] == 0 && isSafe(row - 1, col - 1, num))
        //{
        //    sudokuboard[row - 1][col - 1] = num;
        //    showGame();
        //}
        // This needs to work in order for the board to keep displaying
        if (num)
        {
            details.sudokuBoard1A[row-1][col-1] = num;
            details.displayBoard();
        }


        else // if their input is valid but incorrect
        {
            cout << "Invalid move! Please try again." << endl;
        }

        //if (solved()) // if the board is solved
        //{
        //    cout << "Congratulations! You have solved the Sudoku puzzle." << endl;
        //    break;
        //}
    }



    return 0;

}


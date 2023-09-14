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

    void displayBoard()
    {
        // clear screen from menu
        system("cls");

        // test board
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

    /*
    all i can think of is labeling the rows and columns, asking the user to enter them, and then putting in their number. checking that position for the rules, and if it follows them, placing the number there
    
    need an array for the row and column labels, then iterate through it until 9, printing the labels

    user will select rowXcolumn value

    cin >> row >> column;

    store it in the position they enter sudokuBoard[row][col]

    check this position to see if it abides by rules, and if it does, keep it/display it. if it doesn't, that is when it should prompt users to enter another number somewhere else. here it needs to tabulate mistakes too.
    */











};



int main()
{

    // Make object of class
    game details;

    // Call menu selection and get level choice
    details.getChoice();
    

    // return 0;

}


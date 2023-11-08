// Name: Hannah Cherb
// Program Description: Sudoku Game :D



#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "boards.h" // include header file

using namespace std;

class game : public boards // inherits boards from .h file
{
private:

    int choiceDifficulty; // difficulty users choose
    int choiceLevel; // level (board)

public:

    void getChoice()
    {
       // Menu 
       // Code a menu system for the user (basic shell of what the program 
       // will be)

        cout << "Welcome to Royal Blue Sudoku! You can play a 9*9 sudoku game of" << endl;
        cout << "three difficulty levels: easy, medium, or hard. Please choose a" << endl;
        cout << "difficulty level below." << endl;

        cout << "1 - Easy (6 mistakes allowed)" << endl;
        cout << "2 - Medium (4 mistakes allowed)" << endl;
        cout << "3 - Hard (2 mistakes allowed)" << endl;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choiceDifficulty;

        if (choiceDifficulty == 1) // send them to easy level
        {
            // Allow them to choose 1 of 3 board options
            cout << endl << "Choose your level:" << endl;
            // this is where the design could come in!!

            cout << "1 - Rocky Mountain Climb" << endl;
            cout << "2 - Arctic Circle Plunge" << endl;
            cout << "3 - Amazon Jungle Dash" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard1A); // send the board here
                playGame(sudokuBoard1A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard1B); // send the board here
                playGame(sudokuBoard1B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard1C); // send the board here
                playGame(sudokuBoard1C);
            } 
            else
            {
                // send them back to menu and tell them to try again
                system("cls"); // better way ? find
                getChoice();
            }
        }
        // DO THIS ********************************
        else if (choiceDifficulty == 2)
        {
            // send them to medium level
            // Allow them to choose 1 of 3 board options
            cout << endl << "Choose your level:" << endl;
            // this is where the design could come in!!

            cout << "1 - Swiss Alps Ascent" << endl;
            cout << "2 - Grand Canyon Expedition" << endl;
            cout << "3 - Barrier Reef Dive" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard2A); // send the board here
                playGame(sudokuBoard2A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard2B); // send the board here
                playGame(sudokuBoard2B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard2C); // send the board here
                playGame(sudokuBoard2C);
            }
            else
            {
                // send them back to menu and tell them to try again
                system("cls"); // better way ? find
                getChoice();
            }
        }
        // DO THIS ********************************
        else if (choiceDifficulty == 3)
        {
            // send them to hard level
                        // Allow them to choose 1 of 3 board options
            cout << endl << "Choose your level:" << endl;
            // this is where the design could come in!!

            cout << "1 - Australian Outback Adventure" << endl;
            cout << "2 - Sea Abyss Odyssey" << endl;
            cout << "3 - Nuclear Meltdown Fallout" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard3A); // send the board here
                playGame(sudokuBoard3A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard3B); // send the board here
                playGame(sudokuBoard3B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard3C); // send the board here
                playGame(sudokuBoard3C);
            }
            else
            {
                // send them back to menu and tell them to try again
                system("cls"); // better way ? find
                getChoice();
            }
        }
        else
        {
            // send them back to menu and tell them to try again
            system("cls"); // better way ? find
            getChoice();
        }
    }




    void displayBoard(int arr[9][9])
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
                if (arr[i][x] == 0) // if the box is empty
                {
                    cout << " "; // print a blank space
                } 
                else
                {
                    cout << arr[i][x]; // print numbers
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

   // make sure input is correct
    bool correctInput(int row, int col, int num, int arr[9][9])
    {
        // check row
        for (int x = 0; x < 9; x++) // go through the columns
        {
            if (arr[row][x] == num) // if the number already appears in another col in the row
            {
                return false; // input can NOT go in
            }
        }

        // check column
        for (int x = 0; x < 9; x++) // go through the rows
        {
            if (arr[x][col] == num) // if the number already appears in another row in the col
            {
                return false; // input can NOT go in
            }
        }

        // check box
        for (int i = 0; i < 3; i++) // loop through rows
        {
            for (int j = 0; j < 3; j++) // loop through columns
            {
                // if num is in the box
                if (arr[i][j] == num)
                    return false; // input can NOT go in
            }
        }

        // if the input follows all the rules
        return true;   // it shall pass!

    }

    // check if it is solved ******************************************
    //bool solved(int arr[9][9])
    //{
    //    for (int row = 0; row < 9; row++) // loop through rows
    //    {
    //        for (int col = 0; col < 9; col++) // loop through columns
    //        {
    //            if (arr[row][col] == 0) // if cell is empty
    //            {
    //                for (int num = 1; num <= 9; num++) // try numbers from 1 to 9
    //                {
    //                    if (correctInput(row, col, num, arr)) // if the num is in the correct place
    //                    {
    //                        arr[row][col] = num; // put the number in the cell

    //                        if (solved(arr)) // check if the board can be solved with this number
    //                            return true; // if solved, return true

    //                        arr[row][col] = 0; // if the board cannot be solved, reset the cell
    //                    }
    //                }
    //                return false; // if no number works, return false
    //            }
    //        }
    //    }
    //    return true; // if all cells are filled, return true - it is solved!!
    //}
    // ******************************************************************



    void playGame(int arr[9][9])
    {
        // collect choice
        int row, col, num;
        cout << "To return to the main menu, enter '0 0 0'" << endl << endl;
        cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;

        while (true) // find better way than this
        {
            cin >> row >> col >> num; // get user input

            // if they want to exit to main menu
            if (row == 0 && col == 0 && num == 0)
            {
                system("cls");
                getChoice();
            }
            // if they enter a number that is not 1-9
            if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
            {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }

            // Allows numbers to go on the board without logic/being correct
            if (arr[row - 1][col - 1] == 0 && correctInput(row - 1, col - 1, num, arr))
            {
                arr[row - 1][col - 1] = num;
                displayBoard(arr);
                cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;
            }

            else // if their input is valid but incorrect
            {
                cout << "Invalid move! Please try again." << endl;
                // tabulate mistakes 
                mistakeCounter(choiceLevel);
            }

            //if (solved(arr)) // if the board is solved
            //{
            //    cout << "Congratulations! You solved the puzzle!" << endl;
            //    break;
            //}
        }
    }

    void mistakeCounter(int choiceLevel)
    {
        static int mistakeCount = 0; // static (no unlimited chances)

        mistakeCount++; 
        cout << "Mistakes: " << mistakeCount << endl << endl;

        // EASY LEVEL
        if (mistakeCount >= 6 && choiceLevel == 1) { // check easy level (6 mistakes)
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl << endl;
            exit(0); // Exit the program
        }
        // MEDIUM LEVEL
        else if (mistakeCount >= 4 && choiceLevel == 2) { // check medium level (4 mistakes)
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
        // HARD LEVEL
        else if (mistakeCount >= 2 && choiceLevel == 3) { // check hard level (2 mistakes)
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
    }

    void continueGame()
    {
        int playAgain;

        cout << "Would you like to play again? If so, enter '1' and if you are" << endl;
        cout << "done, enter '2':";
        cin >> playAgain;
        if (playAgain == 1)
        {
            getChoice();
        }
        else if (playAgain == 2)
        {
            cout << "Thanks for playing! Try out more levels soon!" << endl;
        }
        else
        {
            cout << "Would you like to play again? If so, enter '1' and if you are" << endl;
            cout << "done, enter '2':";
            cin >> playAgain;
        }
    }


};



int main()
{
    // Make object of class
    game details;

    // Call menu selection and get level choice
    details.getChoice();

    // done !
    return 0;
}


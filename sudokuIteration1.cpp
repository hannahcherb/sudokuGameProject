// Name: Hannah Cherb
// Program Description: Sudoku Game :D


#include<iostream>
#include<string>
#include<vector>
#include "boards.h" // include header file

using namespace std;

class game : public boards // inherits boards from .h file
{
private:

    int choiceDifficulty; // difficulty users choose
    int choiceLevel; // level (board)
    int mistakes;
    int comboStreak;
    int score;


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

            cout << "1 - Grand Canyon Expedition" << endl;
            cout << "2 - Rocky Mountain Climb" << endl;
            cout << "3 - Arctic Circle Plunge" << endl;
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

            cout << "1 - Amazon Jungle Dash" << endl;
            cout << "2 - Swiss Alps Ascent" << endl;
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
            system("cls");
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
        // Check the row, column, and 3x3 box
        for (int i = 0; i < 9; i++) 
        {
            if (arr[row][i] == num || arr[i][col] == num || arr[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) 
            {
                return false;
            }
        }
        return true;
    }

    // check if it is solved ******************************************
    bool solved(int arr[9][9]) 
    {
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                if (arr[row][col] == 0 || !correctInput(row, col, arr[row][col], arr))
                {
                    // If there's an empty cell, the Sudoku is not solved
                    return false;
                }
            }
        }
        return true;  
    }


    bool findEmptyCell(int arr[9][9], int& row, int& col) 
    {
        for (row = 0; row < 9; row++) 
        {
            for (col = 0; col < 9; col++) 
            {
                if (arr[row][col] == 0) 
                {
                    return true;  // Found an empty cell
                }
            }
        }
        return false;  // All cells are filled
    }

    void playGame(int arr[9][9])
    {
        // collect choice
        int row, col, num;
        score = 50; // for pts
        comboStreak = 0; // for pts
        mistakes = 0;


        cout << "To return to the main menu, enter '0 0 0'" << endl << endl;
        cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;
        

        while (true) // find better way than this
        {
            cin >> row >> col >> num; // get user input

            // show user their score
            cout << "Current score: " << score << endl;

            // if they want to exit to main menu
            if (row == 0 && col == 0 && num == 0)
            {
                system("cls");
                getChoice();
            }
            // if they enter a number that is not 1-9
            else if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
            {
                cout << "Invalid input. Please try again." << endl;
                continue;
            }
            // Allows numbers to go on the board 
            else if (arr[row - 1][col - 1] == 0 && correctInput(row - 1, col - 1, num, arr))
            {
                arr[row - 1][col - 1] = num;
                displayBoard(arr);
                
                calculateScore();
                showScore(); 
                updateComboStreak(true);

                if (solved(arr)) // if the board is solved
                {
                    // it returns true? congrats
                    // it CANNOT be returning true since it is skipping :(
                    cout << "Congratulations! You solved the puzzle!" << endl;
                    break;
                }
                else
                {
                    cout << "Current score: " << score << endl;
                    cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;
                }

            }
            else // if their input is valid but incorrect
            {
                cout << "Invalid move! Please try again." << endl;
                updateComboStreak(false);  // Reset combo streak 
                mistakeCounter();
                calculateScore();
                showScore();
                cout << "Current score: " << score << endl;
            }

        }
    }

    void mistakeCounter()
    {
        mistakes++;
        cout << "Mistakes: " << mistakes << endl << endl;

        // EASY LEVEL
        if (mistakes > 6 && choiceLevel == 1)
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl << endl;
            exit(0); // Exit the program
        }
        // MEDIUM LEVEL
        else if (mistakes > 4 && choiceLevel == 2)
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
        // HARD LEVEL
        else if (mistakes > 2 && choiceLevel == 3)
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
    }

    void resetMistakes()
    {
        mistakes = 0;
    }

    void calculateScore() 
    {
        // Calculate mistake penalties based on difficulty level
        int mistakePenalty = 0; 

        if (mistakes>0)
        {
            if (choiceLevel == 1)
            {
                mistakePenalty = -2;
            }
            else if (choiceLevel == 2)
            {
                mistakePenalty = -4;
            }
            else
            {
                mistakePenalty = -10;
            }
        }

        // Apply mistake penalty
        score += mistakePenalty;

        // Calculate combo streak bonus
        int comboBonus;
        if (choiceLevel == 1)
        {
            comboBonus = 2;
        }
        else if (choiceLevel == 2)
        {
            comboBonus = 5;
        }
        else
        {
            comboBonus = 7;
        }

        // Apply combo streak bonus
        score += comboBonus * comboStreak;

        resetMistakes();

        if (score < 0)
        {
            cout << "Game over! Your score dropped below 0. Better luck next time!" << endl;
            exit(0); // Exit the program
        }

    }
    

    void updateComboStreak(bool correctMove) 
    {
        if (correctMove)
        {
            comboStreak++;
        }
        else
        {
            comboStreak = 0;  // Reset combo streak on an incorrect move
        }
    }

    void showScore() 
    {
        // Display the score
        cout << "Your score: " << score << endl;
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


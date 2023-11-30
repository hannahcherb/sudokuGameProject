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
    int mistakes; // keep tracko of mistakes
    int comboStreak; // comboStreak to add to score
    int score; // user score


public:


    void getChoice()
    {
       // Menu 
        cout << "Welcome to Royal Blue Sudoku! You can play a 9*9 sudoku game of" << endl;
        cout << "three difficulty levels: easy, medium, or hard. Please choose a" << endl;
        cout << "difficulty level below." << endl;

        cout << "1 - Easy (6 mistakes allowed)" << endl;
        cout << "2 - Medium (4 mistakes allowed)" << endl;
        cout << "3 - Hard (2 mistakes allowed)" << endl;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choiceDifficulty;

        if (choiceDifficulty == 1) // easy difficulty
        {
            cout << endl << "Choose your level:" << endl;
            cout << "1 - Grand Canyon Expedition" << endl;
            cout << "2 - Rocky Mountain Climb" << endl;
            cout << "3 - Arctic Circle Plunge" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard1A); // 1A board
                playGame(sudokuBoard1A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard1B); // 1B board
                playGame(sudokuBoard1B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard1C); // 1C board
                playGame(sudokuBoard1C);
            } 
            else
            {
                // prompt to enter valid choice
                system("cls");
                getChoice();
            }
        }

        else if (choiceDifficulty == 2) // medium difficulty
        {
            cout << endl << "Choose your level:" << endl;

            cout << "1 - Amazon Jungle Dash" << endl;
            cout << "2 - Swiss Alps Ascent" << endl;
            cout << "3 - Barrier Reef Dive" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard2A); // 2A board
                playGame(sudokuBoard2A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard2B); // 2B board
                playGame(sudokuBoard2B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard2C); // 2C board
                playGame(sudokuBoard2C);
            }
            else
            {
                // prompt to enter valid choice
                system("cls");
                getChoice();
            }
        }

        else if (choiceDifficulty == 3) // hard difficulty
        {
            cout << endl << "Choose your level:" << endl;

            cout << "1 - Australian Outback Adventure" << endl;
            cout << "2 - Sea Abyss Odyssey" << endl;
            cout << "3 - Nuclear Meltdown Fallout" << endl;
            cout << "Enter the number corresponding to your choice: ";
            cin >> choiceLevel;

            if (choiceLevel == 1)
            {
                displayBoard(sudokuBoard3A); // 3A board
                playGame(sudokuBoard3A);
            }
            else if (choiceLevel == 2)
            {
                displayBoard(sudokuBoard3B); // 3B board
                playGame(sudokuBoard3B);
            }
            else if (choiceLevel == 3)
            {
                displayBoard(sudokuBoard3C); // 3C board
                playGame(sudokuBoard3C);
            }
            else
            {
                // prompt to enter valid choice
                system("cls");
                getChoice();
            }
        }
        else
        {
            // prompt to enter valid choice
            system("cls");
            getChoice();
        }
    }


    void displayBoard(int arr[9][9])
    {   
        // clear menu
        system("cls");

       // display board
        cout << "ROYAL BLUE SUDOKU" << endl; // title
        cout << "-------------------------" << endl; // top of board
        
        // i --> rows and x --> columns
        // use for loops to display sudokuBoard
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

   // check input
    bool correctInput(int row, int col, int num, int arr[9][9])
    {
        // check if cell is empty
        if (arr[row][col] != 0)
        {
            return false;
        }

        // check the row, column, and 3x3 box
        for (int i = 0; i < 9; i++) 
        {
            if (arr[row][i] == num || arr[i][col] == num || arr[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == num) 
            {
                return false;
            }
        }
        return true;
    }


    // check if solved
    bool solved(int arr[9][9], int& row, int& col)
    {
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                if (arr[row][col] == 0)
                {
                    // If there's an empty cell, the Sudoku is not solved
                    return false;
                }
            }
        }
        return true; // return true for congratulatory message 
    }

    // play the game
    void playGame(int arr[9][9])
    {
        // variables
        int row, col, num;
        score = 50;
        comboStreak = 0;
        mistakes = 0;

        cout << "To return to the main menu, enter '0 0 0'" << endl << endl;
        cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;
        
        // implement game logic + play game
        while (true)
        {
            cin >> row >> col >> num; // get user input

            cout << "Current score: " << score << endl; // show user their score

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
            // allow correct input on the board 
            else if (arr[row - 1][col - 1] == 0 && correctInput(row - 1, col - 1, num, arr))
            {
                arr[row - 1][col - 1] = num;
                displayBoard(arr);
                
                // keep track of score and combo streak
                calculateScore();
                updateComboStreak(true);

                if (solved(arr,row,col)) // if the board is solved
                {
                    cout << "Congratulations! You solved the puzzle!" << endl;
                    cout << "Final score: " << score << endl;
                    break;
                }
                else
                {
                    showScore();
                    cout << "Current score: " << score << endl;
                    cout << "Enter the row, column, and number (1-9) of your Sudoku move (ex: 2 5 2):" << endl;
                }

            }
            else // valid but incorrect input
            {
                cout << "Invalid move! Please try again." << endl;
                updateComboStreak(false);  // end streak
                mistakeCounter();
                calculateScore();
                showScore();
                cout << "Current score: " << score << endl;
            }

        }
    }

    // count mistakes
    void mistakeCounter()
    {
        // increment and display
        mistakes++;
        cout << "Mistakes: " << mistakes << endl << endl;

        if (mistakes > 6 && choiceLevel == 1) // easy difficulty
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl << endl;
            exit(0); // Exit the program
        }
        else if (mistakes > 4 && choiceLevel == 2) // medium difficulty
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
        else if (mistakes > 2 && choiceLevel == 3) // hard difficulty
        {
            cout << "Game over! You have exceeded the maximum number of mistakes for this difficulty level." << endl;
            exit(0); // Exit the program
        }
    }

    // reset mistakes after each play
    void resetMistakes()
    {
        mistakes = 0;
    }

    void calculateScore() 
    {
        // calculate score with mistakes
        int mistakePenalty = 0; 

        if (mistakes>0) // if a mistake is made
        {
            if (choiceLevel == 1) // easy difficulty penalty
            {
                mistakePenalty = -2;
            }
            else if (choiceLevel == 2) // medium difficulty penalty
            {
                mistakePenalty = -4;
            }
            else if (choiceLevel ==3) // hard difficulty penalty
            {
                mistakePenalty = -10;
            }
        }

        // new score w/ mistake penalty
        score += mistakePenalty;

        // streak combo bonuses
        int comboBonus;

        if (choiceLevel == 1) // easy difficulty combo bonus
        {
            comboBonus = 2;
        }
        else if (choiceLevel == 2) // medium difficulty combo bonus
        {
            comboBonus = 4;
        }
        else if (choiceLevel ==3) // hard difficulty combo bonus
        {
            comboBonus = 6;
        }

        // new score w/ combo bonus
        score += comboBonus * comboStreak;

        // reset mistakes
        resetMistakes();

        // if score falls below 0, end the game
        if (score < 0)
        {
            cout << "Game over! Your score dropped below 0. Better luck next time!" << endl;
            exit(0); // Exit the program
        }

    }
  
    // keep track of combo streak for bonuses
    void updateComboStreak(bool correctMove) 
    {
        if (correctMove)
        {
            comboStreak++;
        }
        else
        {
            comboStreak = 0;  // reset combo streak
        }
    }

    // display score
    void showScore() 
    {
        cout << "Your score: " << score << endl;
    }

    // prompt to continue/end game
    void continueGame()
    {
        int playAgain;

        cout << "Would you like to play again? If so, enter '1' and if you are" << endl;
        cout << "done, enter '2':";
        cin >> playAgain;
        if (playAgain == 1) // allow user to play again
        {
            getChoice();
        }
        else if (playAgain == 2) // allow user to exit
        {
            cout << "Thanks for playing! Try out more levels soon!" << endl;
        }
        else // prompt for correct input
        {
            continueGame();
        }
    }
};


int main()
{
    // make object of class
    game details;

    // call menu selection and get level choice + play game
    details.getChoice();

    // done
    return 0;
}


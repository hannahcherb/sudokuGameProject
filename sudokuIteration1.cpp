// Name: Hannah Cherb
// Program Description: Sudoku Game :D
// ^^ add more later


#include<iostream>
#include<string>
#include<vector>
#include<fstream>
// header file with all the boards?? that the class inherits
// okay and then something randomly picks the board and displays it?
// watch some vids

using namespace std;

class game // header file with all the boards?? that the class inherits
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

        // doesn't show up because nothing is being done to display it on screen
        cout << "display board" << endl;

        // display actual board
        /*
        
        >:[
        
        
        
        */


      
        /* NOTES -------------------------------------------------------------------
        
        there also needs to be a mistake tabulator
        and hints
        make a space for this and worry about details later

        sudoku.com displays (with the board) difficulty, mistakes, score, and time. 

        i need something for score and time. how is sudoku scored? idk
        
        */

    }





};



int main()
{

    // Make object of class
    game details;

    // Call menu selection and get level choice
    details.getChoice();
    

    // return 0;

}


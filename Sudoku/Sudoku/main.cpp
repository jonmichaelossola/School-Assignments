//
//  main.cpp
//  Sudoku
//
//  Created by Jon Michael Ossola on 8/4/18.
//  Copyright © 2018 Jon Michael Ossola. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

void readFile(int board [][9], string fileName);
void displayBoard(int board [][9]);
void display(int board [][9]);
void editSquare(int board [][9]);
void showPossibles(int board [][9]);
void displayMenu();
void missingRow(int board [][9], int missing [], const int & col, const int & row);
void missingColumn(int board [][9], int missing [], const int & col, const int & row);
void missingSquare(int board [][9], int missing [], const int & col, const int & row);
void solveBoard(int board [][9], int col, int row);
void getCoordinates(int & col, int & row);
void writeToFile(int board [][9]);
bool isSolved(int board[][9]);

/********************************************************************
 * The main function. This will handle all of the main controls.
 * This just calls on our main display function, displays the options,
 * and displays the board.
 ********************************************************************/
int main(int argc, const char * argv[]) {
    int board [9][9];
    
    string fileName;
    cout << "Where is your board located? ";
    cin >> fileName;
    
    readFile(board, "input.txt");
    displayMenu();
    
    cout << endl;
    displayBoard(board);
    cout << endl;
    
    display(board);
    return 0;
}

/********************************************************************
 * This is our display function. It controls which of the controls
 * goes down. Pretty straightforward ano? Stop calling functions
 * after a q or a Q is found.
 ********************************************************************/
void display(int board [][9])
{
    char option = 's';
    
    while (option != 'q' && option != 'Q')
    {
        cout << "> ";
        cin >> option;
        
        // The program will operate from here.
        switch (option)
        {
            case 'f': case 'F':
                while (!isSolved(board))
                    solveBoard(board, 0, 0);
                cout << endl;
                break;
            case 'd': case 'D':
                displayBoard(board);
                cout << endl;
                break;
            case 'e': case 'E':
                editSquare(board);
                cout << endl;
                break;
            case 's': case 'S':
                showPossibles(board);
                cout << endl;
                break;
            case '?':
                displayMenu();
                cout << endl;
                break;
            case 'q': case 'Q':
                writeToFile(board);
                break;
        }
    }
}

/********************************************************************
 * this is the display menu function. Displays the menu for the
 * controls for sudoku. Displays which controls do what stuff.
 * doesn't return anything.
 ********************************************************************/
void displayMenu()
{
    cout << "Options:\n";
    cout << "   ?  Show these instructions\n";
    cout << "   D  Display the board\n";
    cout << "   E  Edit one square\n";
    cout << "   S  Show the possible values for a square\n";
    cout << "   Q  Save and quit\n";
}

/********************************************************************
 * Read from the file, storing each item into a board of sudoku
 * pieces. That's it!
 ********************************************************************/
void readFile(int board [][9], string fileName)
{
    ifstream fin(fileName.c_str());
    
    if (fin.fail())
    {
        cout << "Error in reading file: " << fileName << endl;
        // in the case of error reading file, exit program.
        exit(0);
    }

    int i;
    int col = 0;
    int row = 0;
    
    while (fin >> i)
    {
        board[col][row] = i;
        
        row++;
        if (row == 9)
        {
            col++;
            row = 0;
        }
    }
    
    // we done! Boiiiiiiiiiiii.
    fin.close();
}

/********************************************************************
 * Display the board meticulously to pass test bed. Don't need to
 * go to crazy over this function.
 ********************************************************************/
void displayBoard(int board [][9])
{
    int count = 0;
    cout << "   A B C D E F G H I\n";
    for (int i = 0; i < 9; i++)
    {
        count++;
        
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                cout << count << setw(4);
                if (board[i][j])
                    cout << board[i][j];
                else
                    cout << ' ';
            }
            else if (j == 3 || j == 6)
            {
                cout << "|";
                if (board[i][j])
                    cout << board[i][j];
                else
                    cout << ' ';
            }
            else
            {
                cout << ' ';
                if (board[i][j])
                    cout << board[i][j];
                else
                    cout << ' ';
            }
        }
        cout << endl;
        
        if (i == 2 || i == 5)
            cout << "   " << "-----+-----+-----\n";
    }
}

/********************************************************************
 * Saving any found pieces into the passed in integer array, which
 * saves all of the items found in a like a hash table.
 ********************************************************************/
void missingRow(int board [][9], int missing [], const int & col, const int & row)
{
    for (int i = 0; i <= 8; i++)
    {
        int check = board[col][i];
        if (missing[check] != board[col][i] && board[col][i] != 0)
            missing[check] = board[col][i];
    }
}

/********************************************************************
 * Saves all of the pieces found in the column into the hash table.
 * the board and the missing is pass by pointer.
 ********************************************************************/
void missingColumn(int board [][9], int missing [], const int & col, const int & row)
{
    for (int i = 0; i <= 8; i++)
    {
        if (missing[board[i][row]] != board[i][row] && board[i][row] != 0)
            missing[board[i][row]] = board[i][row];
    }
}

/********************************************************************
 * Find everything inside of the square. We do this by finding the
 * top left coordinate of each square and then working our way through
 * the square, looking if we have any missing.
 ********************************************************************/
void missingSquare(int board [][9], int missing [], const int & col, const int & row)
{
    // this will get us the top left coordinates of the quadrant we are at :)
    int x = col;
    while (x % 3 != 0)
        x--;
    int y = row;
    while (y % 3 != 0)
        y--;
    
    for (int i = x+0; i < x+3; i++)
    {
        for (int j = y+0; j < y+3; j++)
        {
            // we are basically using a hash table data structure here :P
            if (missing[board[i][j]] != board[i][j] && board[i][j] != 0)
                missing[board[i][j]] = board[i][j];
        }
    }
}

/********************************************************************
 * Pretty simple, changes the coordinates the user enters into
 * something the board can read by taking the ascii value and
 * returning those.
 ********************************************************************/
void getCoordinates(int & col, int & row, string & findMe)
{
    cout << "What are the coordinates of the square: ";
    cin >> findMe;
    
    row = findMe[0] - 65;
    col = findMe[1] - 49;
}

/********************************************************************
 * This function will allow us to edit a single squre. It calls
 * on other functions we have already defined previously and
 * then shows the possibilities and then takes input to edit the square.
 ********************************************************************/
void editSquare(int board [][9])
{
    string findMe;
    int newVal;
    int row;
    int col;

    getCoordinates(col, row, findMe);
    cout << "What is the value at '" << findMe << "': ";
    cin >> newVal;

    int possibles [10];
    for (int i = 0; i < 10; i++)
        possibles[i] = 0;
    
    missingRow(board, possibles, col, row);
    missingSquare(board, possibles, col, row);
    missingColumn(board, possibles, col, row);
    
    bool found = false;
    
    for (int i = 0; i < 10; i++)
    {
        if (possibles[i] == newVal)
            found = true;
    }
    
    if (!found)
        board[col][row] = newVal;
    else
    {
        cout << "ERROR: Value '" << newVal << "' in square '" << findMe << "' is invalid\n";
    }
}

/********************************************************************
 * This is the function to show the possibles. First we gather a
 * array of ints, basically a hash table. We store the numbers that
 * the spot chosen cannot be, and then use that to display the possible
 * spots for the
 ********************************************************************/
void showPossibles(int board [][9])
{
    int possibles [10];
    for (int i = 0; i < 10; i++)
        possibles[i] = 0;
    
    int col;
    int row;
    string findMe;
    getCoordinates(col, row, findMe);
    
    missingRow(board, possibles, col, row);
    missingSquare(board, possibles, col, row);
    missingColumn(board, possibles, col, row);
    
    cout << "The possible values for '" << findMe << "' are: ";
    bool noneLeft = false;
    for (int i = 1; i < 10; i++)
    {
        if (possibles[i] == 0)
        {
            for (int j = i+1; j < 10; j++)
            {
                if (j == 9 && possibles[j] != 0)
                    noneLeft = true;
                if (j <= 9 && possibles[j] == 0)
                    break;
            }
            
            if (!noneLeft)
                cout << i << ", ";
            else if (noneLeft || (i == 9 && possibles[i] == 0))
                cout << i << endl;
        }
    }
}

/********************************************************************
 * Pretty straight forward. Write all of the data to a file.
 * And that's it! :D
 ********************************************************************/
void writeToFile(int board [][9])
{
    cout << "What file would you like to write your board to? ";
    string fileName;
    cin >> fileName;
    
    ofstream fout(fileName.c_str());
    
    if (fout.fail())
    {
        cout << "Error reading file: " << fileName << endl;
        exit(0);
    }
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            fout << board[i][j] << ' ';
        }
        fout << endl;
    }
    
    fout.close();
}

/********************************************************************
 * This is the function to make check if the board is solved or not.
 * returns true if solved, false if not.
 ********************************************************************/
bool isSolved(int board[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
                return false;
        }
    }
    
    return true;
}

/********************************************************************
 * Recursively goes through each cell that isn't yet solved, and
 * finds if there is one solution, in which case, it inputs that into
 * the board.
 ********************************************************************/
void solveBoard(int board [][9], int col, int row)
{
    if (board[col][row] == 0)
    {
        int possibles [10];
        for (int i = 0; i < 10; i++)
        {
            possibles[i] = 0;
        }
        
        missingRow(board, possibles, col, row);
        missingColumn(board, possibles, col, row);
        missingSquare(board, possibles, col, row);
        int solution = 0;
        
        for (int i = 1; i < 10; i++)
        {
            if (solution && possibles[i] == 0)
            {
                solution = 0;
                break;
                // there is more than one possible solution, so we don't do anything.
            }
            if (possibles[i] == 0)
                solution = i;
        }
        if (solution)
        {
            board[col][row] = solution;
        }
    }
    
    if (col == 8 && row == 8)
        return;
    
    if (row == 8)
        solveBoard(board, col+1, 0);
    else
        solveBoard(board, col, row+1);
}

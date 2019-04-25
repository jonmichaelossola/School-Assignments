/***********************************************************************
* Program:
*    Assignment 00,    
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part is to determine what to write here.
************************************************************************/
/***********************************************************************
 * Program:
 *    Project 7, Sudoku
 * Author:
 *    Don Page
 * Summary:
 *    Sudoku Program that allows user to save his/her progress and also shows
 *    the possible values when prompted to do so. Lets the user solve, rotate,
 *    and clear the board
 ************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

struct Board
{
   int values[81];             //Stores board values
   bool isFixedValue[81];      //Keeps track of what numbers can be modified
   bool isPossibleValue[81][9];
   int coordinates;
};

void getFileName(char fileName[]);
bool getBoard(char fileName[], Board &mainBoard);
bool validateBoard(Board board);
void interact(Board &mainBoard);
void displayMenu();
void displayBoard(Board board);
char getOption();

int getCoordinates(bool isFixedValue[]);
int getNewValue(Board &board);
bool canChange(Board mainBoard, int coordinates, int value);
bool anyDuplicates(int board[], int coordinates, int value);
void editSquare(int board[], int coordinates, int value);
void showPossibles(Board &board);
void save(Board mainBoard);
void rotateBoard(Board &board);
bool checkPossibles(Board &newBoard);
float solve(Board &newBoard);
bool bruteForce(Board &board);
bool isSolved(Board board);
void clearBoard(Board &board);


/**********************************************************************
 * Gets the filename, loads board, and checks to see if opened properly
 * Then interacts with the user.
 ***********************************************************************/
int main(int argc,char *argv[])
{
   char fileName[256];
   Board mainBoard;

   //Get FileName and read board
   getFileName(fileName);
   if (!getBoard(fileName, mainBoard))
      cout << "Error: Unable to open file " << fileName << endl;

   //Validate Board and show menu
   else
      if (validateBoard(mainBoard))
      {
         displayMenu();
         displayBoard(mainBoard);
         interact(mainBoard);
      }

   //system("PAUSE");
   return 0;
}

/**********************************************************************
 * PROMPT fileName
 * GET filename
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin.getline(fileName, 255);
   return;
}

/**********************************************************************
 * getBoard
 *  WHILE row 0 to 80
 *        GET value from file
 *        IF value > 0
 *           SET isFixedValue to true
 *        ELSE
 *           SET isFixedValue to false
 *           SET value / -1
 *  RETURN
 ***********************************************************************/
bool getBoard(char fileName[], Board &mainBoard)
{
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   //Fill MainBoard from file
   for (int i = 0; i < 81; i++)
   {
      fin >> mainBoard.values[i];

      //Original board values are greater than 0(read only)
      //and cannot be changed or modified
      if (mainBoard.values[i] > 0)
         mainBoard.isFixedValue[i] = true;

      //User input values are negative(read/write) & must be changed to +
      else
      {
         mainBoard.isFixedValue[i] = false;
         mainBoard.values[i] = (mainBoard.values[i] / -1);
      }

   }

   fin.close();
   return true;
}

/**********************************************************************
 * validateBoard
 *  WHILE i = 0 to 80
 *        SET tempValue to current value on board
 *        SET board value to 0 temporary
 *        IF tempValue != 0 && anyDuplicates()
 *           PUT Error duplicate value to screen
 *           RETURN false
 *        SET board value back to original value (tempValue)
 *  RETURN true
 ***********************************************************************/
bool validateBoard(Board board)
{

   for (int i = 0; i < 81; i++)
   {
      //The value is temporarily changed to not check for self duplicates
      int tempValue = board.values[i];
      board.values[i] = 0;
      if (tempValue != 0 && anyDuplicates(board.values, i, tempValue))
      {
         cout << "ERROR: Duplicate value '"
              << tempValue
              << "' in inside square represented by '"
              << (char)toupper((i / 9) + 65)
              << ((i % 9) + 1)
              << "'";
         return false;
      }
      board.values[i] = tempValue; //Change back to original value
   }

   //Passed sudoku rules
   return true;
}

/**********************************************************************
 * interact
 *  displayMenu()
 *  displayBoard()
 *  WHILE ! done
 *     SWITCH getOption()
 *        CASE ?
 *           displayMenu()
 *        ... Every menu item goes here
 *  RETURN
 ***********************************************************************/
void interact(Board &mainBoard)
{
   bool done = false;
   int value = -1;
   float time;

   //Interactive Menu
   while (!done)
      switch (getOption())
      {
         case '?'://Display menu
            displayMenu();
            break;
         case 'd'://Display board
            displayBoard(mainBoard);
            break;
         case 'e'://Edit square
            mainBoard.coordinates = getCoordinates(mainBoard.isFixedValue);
            if (mainBoard.coordinates != -1)
               value = getNewValue(mainBoard);
            if (value != -1)
               editSquare(mainBoard.values, mainBoard.coordinates, value);
            break;
         case 's'://Show possible values of square
            showPossibles(mainBoard);
            break;
         case 'r'://Rotate Board
            rotateBoard(mainBoard);
            break;
         case 'c':
            clearBoard(mainBoard);
            break;
         // case 'f'://Finish Board
         //    Board newBoard = mainBoard;//We will solve our board on new one
         //    clearBoard(newBoard);
         //    time = solve(newBoard);
         //    //Copy the solution back to mainBoard so it keeps fixed values
         //    for (int i = 0; i < 81; i++)
         //       mainBoard.values[i] = newBoard.values[i];
         //    cout << "The board took: " << time << " second(s) to finish" << endl;
         //    break;
         case 'q'://Save and quit
            save(mainBoard);
            done = true;
            break;
         default:
            cout << "ERROR: Invalid command" << endl;
            displayMenu();
            break;
      }
   return;
}

/**********************************************************************
 * displayMenu
 *  PUT options to screen
 ***********************************************************************/
void displayMenu()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << endl;
   return;
}

/**********************************************************************
 * displayBoard
 *    PUT header on screen
 *    WHILE 0 to 80
 *       IF (row != 0 && row % 3 == 0)
 *          DISPLAY -----+-----+------
 *       IF (i % 9 == 0)
 *          DISPLAY numbered row
 *       IF (column != 0 && column % 3 == 0)
 *          DISPLAY |
 *          ELSE
 *             DISPLAY space
 *       IF value == 0
 *          DISPLAY space
 *       ELSE
 *          SET color text to red
 *          DISPLAY value
 *    SET color text to white
 *    PUT newline
 ***********************************************************************/
void displayBoard(Board board)
{
   // HANDLE hConsole;
   // hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   //Display Header
   cout << "   A B C D E F G H I" << endl;

   //Row = i / 9 and Column = i % 9
   for (int i = 0; i < 81; i++)
   {
      //Divisor every 3rd row
      if ((i / 9) != 0 && (i / 9) % 3 == 0 && (i % 9) == 0)
         cout << "   -----+-----+-----" << endl;

      if (i % 9 == 0)//Numbered Rows
         cout << ((i / 9) + 1) << " ";

      //Divisor every 3rd Column
      ((i % 9) != 0 && (i % 9) % 3 == 0) ? cout << "|" : cout << " ";

      //Space for each unknown value(0)
      if (board.values[i] == 0)
         cout << " ";
      else //Set original board values to red
      {
         cout << board.values[i];
      }

            if ((i + 1) % 9 == 0)
               cout << endl;
   }
   return;
}

/**********************************************************************
 * PROMPT user for option
 * GET option
 ***********************************************************************/
char getOption()
{
   char option;
   cout << endl << "> ";
   cin >> option;
   return (tolower(option));
}

/**********************************************************************
 * getCoordinates
 *  SET coordinates = -1
 *  PROMPT user for coordinates
 *  GET input
 *  IF input[0] is not a letter
 *     values[0] = input[1]
 *  IF input[1] is not a digit
 *     values[1] = input[0]
 *  IF values[0] is not letter a-z || values[1] is not 1-9
 *     PUT Error to screen invalid input
 *  ELSE IF isFixedValue[values[0]-97][values[1]-49]
 *           PUT Error to screen read only
 *  ELSE
 *     coordinates = (values[0]-97) + (values[1]-49)*9
 *  RETURN coordinates
 ***********************************************************************/
int getCoordinates(bool isFixedValue[])
{
   int coordinates = -1;
   char input[3];
   int values[2];

   cout << "What are the coordinates of the square: ";
   cin  >> input;

   //Change format to grid[0] lowercase letter , grid[1] number
   (isalpha(input[0])) ? values[0] = tolower(input[0])
      : values[0] = tolower(input[1]);
   (isdigit(input[1])) ? values[1] = input[1]
      : values[1] = input[0];

   //Check for valid input(a-z)(1-9)
   if (values[0] < 'a' || values[0] > 'z' || values[1] < 49 || values[1] > 57)
      cout << "ERROR: Square '" << input << "' is invalid" << endl;

   //Check cell if read only
   else if (isFixedValue[(values[0] - 97) + (values[1] - 49) * 9])
      cout << "ERROR: Square '"
           << (char)toupper(values[0])
           << values[1] - 48
           << "' is filled" << endl;

   //Convert to coordinates(ex. (a2) = (97,50) = (10)
   else                 //Column      +        Row       * Column
      coordinates = ((values[0] - 97) + (values[1] - 49) * 9);
   return coordinates;
}

/**********************************************************************
 * getNewValue
 *  PROMPT user for new value
 *  GET value
 *  IF value < 0 || value > 9 || !canChange(value)
 *     PUT Error on screen value is invalid
 *     RETURN -1
 *  RETURN value
 ***********************************************************************/
int getNewValue(Board &board)
{
   //Get new value
   int value;
   cout << "What is the value at '"
        << (char)(board.coordinates % 9 + 65) //Letter
        << (board.coordinates / 9 + 1)        //Number
        << "': ";
   cin  >> value;

   //Check for valid input : 0 <= value <= 9
   //and if new value is allowed by sudoku rules
   if (value < 0 || value > 9 ||
       !canChange(board, board.coordinates, value))
   {
      cout << "ERROR: Value '" << value << "' in square '"
           << (char)(board.coordinates % 9 + 65)
           << (board.coordinates / 9 + 1)
           << "' is invalid" << endl;
      return -1;
   }
   return value;
}

/**********************************************************************
 * canChange
 *  IF isFixedValue[coordinates]
 *     RETURN false
 *  IF value == 0
 *     RETURN true
 *  IF anyDuplicates()
 *     RETURN false
 *  RETURN true
 ***********************************************************************/
bool canChange(Board mainBoard, int coordinates, int value)
{
   //Check for board read only values
   if (mainBoard.isFixedValue[coordinates])
      return false;

   //Check for resetting user input values to 0
   if (value == 0)
      return true;

   //Check if there are duplicates in Row Column or Block
   if (anyDuplicates(mainBoard.values, coordinates, value))
      return false;

   //Passed all checks
   return true;
}

/**********************************************************************
 * anyDuplicates - Row Column and Blocks
 *  SET row = coordinates / 9
 *  SET column = coordinates % 9
 *  WHILE c = 0 to 8
 *     IF value == mainBoard[coordinates / 9][c]
 *        RETURN false
 *  WHILE r = 0 to 8
 *     IF value == mainBoard[r][coordinates % 9]
 *        RETURN false
 *  WHILE r = beginning row to r+3
 *     WHILE c = beginning column to c+3
 *        IF value == mainBoard[r][c]
 *           RETURN false
 ***********************************************************************/
bool anyDuplicates(int board[], int coordinates, int value)
{
   int row = coordinates / 9;
   int column = coordinates % 9;

   //Check if value already exists in row or column
   for (int i = row * 9; i < ((row * 9) + 9); i++)
      if (value == board[i])
         return true;

   //Check if value already exists in column
   for (int i = column; i < 81; i+=9)
      if (value == board[i])
         return true;

   //Check if value already exists in (3 X 3) block
   while (column % 3 != 0)   //Move to first column in block
      column--;
   while (row % 3 != 0)//Move to first row in block
      row--;
   for (int r = row; r < (row + 3); r++)
      for (int c = column; c < (column + 3); c++)
         if (value == board[((r * 9) + c)])
            return true;

   //If get here there are no duplicates in that row column or block
   return false;
}

/**********************************************************************
 * editSquare
 *  SET board[coordinates] = value
*  RETURN
***********************************************************************/
void editSquare(int board[], int coordinates, int value)
{
   //Update Board...
   board[coordinates] = value;
   return;
}

/**********************************************************************
 * showPossibles
 *  getCoordinates()
 *  PUT possible values for coordinates are: to screen
 *  WHILE guess = 1 to 9
 *     IF canChange(guess)
 *        possibles += guess,
 *  SET possibles[possibles.length() - 2] = '\0'
 *  PUT possibles to screen
 ***********************************************************************/
void showPossibles(Board &board)
{
  string possibles;

   board.coordinates = getCoordinates(board.isFixedValue);

   cout << "The possible values for '"
        << (char)(board.coordinates % 9 + 65) //Letter
        << (board.coordinates / 9 + 1)        //Number
        << "' are: ";


   //Check values 1 to 9
   //used 49 through 57 so can be stored as characters in string
   for (int guess = 49; guess <= 57; guess++)
      if (canChange(board, board.coordinates, guess - 48))
      {
         //possibles[i] = guess - 48;
        possibles += guess;
          possibles += ", ";
      }

   //Remove last comma in string
   possibles[possibles.length() - 2] = '\0';

   // don't want to see the NULL character
   for (int i = 0; possibles[i] != '\0'; i++)
   {
    cout << possibles[i];
   }
   cout << endl;
   return;
}

/**********************************************************************
 * save
 *  PROMPT fileName to save to
 *  GET fileName
 *  WHILE i = 0 to 81
 *        fout board[i] 'space'
 *     fout 'newline'
 *  PUT to screen board written successfully
 *  RETURN
 ***********************************************************************/
void save(Board mainBoard)
{
   char fileName[256];

   cout << "What file would you like to write your board to: ";
   cin  >> fileName;

   ofstream fout(fileName);
   if (fout.fail())
      return;

   //Write Board to file
   for (int i = 0; i < 81; i++)
   {
      if (!mainBoard.isFixedValue[i]) //user input is saved with (-)
         fout << "-" << mainBoard.values[i] << " ";
      else
         fout << mainBoard.values[i] << " ";
      if ((i + 1) % 9 == 0)
         fout << endl;
   }
   fout.close();

   cout << "Board written successfully" << endl;
   return;
}

/**********************************************************************
 * Rotates board 180 degrees and keeps track of fixed values
 ***********************************************************************/
void rotateBoard(Board &board)
{
   int tempBoard[81];
   bool tempFixed[81];

   //First copy board
   for (int i = 0; i < 81; i++)
   {
      tempBoard[i] = board.values[i];
      tempFixed[i] = board.isFixedValue[i];
   }

   //Rotates board 180 degrees
   int iEnd = 80;
   for (int i =0; i < 81; i++, iEnd--)
   {
      board.values[i]       = tempBoard[iEnd];
      board.isFixedValue[i] = tempFixed[iEnd];
   }

   return;
}

/**********************************************************************
 * Fills in all values where the possible values for that cell is one #
 * Returns true if board was solved
 * Returns false if board was not solved
 ***********************************************************************/
bool checkPossibles(Board &newBoard)
{
   bool noChanges;

   //Loop until 'one' possible values are filled in
      do
      {
         noChanges = true;
         for (int i = 0; i < 81; i++)
         {
            int possibles = 0;
            int value;

            //If fixed value set all other possible values to false
            if (newBoard.isFixedValue[i])
            {
               for (int num = 0; num < 9; num++)
                  newBoard.isPossibleValue[i][num] = false;
               newBoard.isPossibleValue[i][newBoard.values[i] - 1] = true;
            }
            else
               //Test numbers 1 through 9 if they are possible values
               for (int guess = 1; guess <= 9; guess++)
                  if (canChange(newBoard, i, guess))
                  {
                     value = guess;
                     newBoard.isPossibleValue[i][guess - 1] = true;
                     possibles++;
                  }
                  else
                     newBoard.isPossibleValue[i][guess - 1] = false;

            if (possibles == 1)  //Only one possible value so fill in
            {
               newBoard.values[i] = value;
               newBoard.isFixedValue[i] = true;
               noChanges = false;
            }
         }
      }while(noChanges == false);

      //Check to see if solved
      if (isSolved(newBoard))
         return true;
      return false;
}

/**********************************************************************
 * This will use human logic to attempt to solve a board
 * It will add the total number of possibles for each number
 * in each ROW, COLUMN, and BLOCK...
 * If the total is one it will fill that number in and update the possibles
 * in each square with the function checkPossibles
 ***********************************************************************/
float solve(Board &newBoard)
{
   int coordinates = 0;
   bool noChanges;
   int startTime = clock();
      do
      {
         noChanges = true;

         //Fill in one possible answer squares and exit if solved
         //We will do this after each Row, Column, and Block check
         if (checkPossibles(newBoard))
            return true;

         //Fill in the known numbers for each ROW
         for (int i = 0; i < 81; i += 9)
            for(int guess = 1; guess <= 9; guess++)//Numbers 1 to 9
            {
               int total = 0;

               //Test the number on the row
               for(int iRow = i; iRow < (i + 9); iRow++)
                  if(!newBoard.isFixedValue[iRow])
                     total += newBoard.isPossibleValue[iRow][guess - 1];

               if (total == 1)//We have found an answer!
                  for(int iRow = i; iRow < (i + 9); iRow++)
                     if (newBoard.isPossibleValue[iRow][guess - 1] &&
                         !newBoard.isFixedValue[iRow])
                     {
                        newBoard.values[iRow] = guess;
                        newBoard.isFixedValue[iRow] = true;
                        noChanges = false;
                     }
            }

         //Fill in one possible answer squares and exit if solved
         if (checkPossibles(newBoard))
            return true;

         //This will fill in the known numbers for each COLUMN
         for (int i = 0; i < 9; i++)
            for(int guess = 1; guess <= 9; guess++)//Numbers 1 to 9
            {
               int total = 0;

               //Test the number on the column
               for(int iColumn = i; iColumn < 81; iColumn += 9)
                  if(!newBoard.isFixedValue[iColumn])
                     total += newBoard.isPossibleValue[iColumn][guess - 1];

               if (total == 1)//We have found an answer!
                  for(int iColumn = i; iColumn < 81; iColumn += 9)
                     if (newBoard.isPossibleValue[iColumn][guess - 1] &&
                         !newBoard.isFixedValue[iColumn])
                     {
                        newBoard.values[iColumn] = guess;
                        newBoard.isFixedValue[iColumn] = true;
                        noChanges = false;
                     }

            }

         //Fill in one possible answer squares and exit if solved
         if (checkPossibles(newBoard))
            return true;

         //This will fill in the known numbers for each BLOCK
         for (int r = 0; r < 81; r += 27)
            for (int c = 0; c < 9; c += 3)
            {
               int i = r + c;//Puts me at the beginning of each block
               for(int guess = 1; guess <= 9; guess++)//Numbers 1 to 9
               {
                  int total = 0;

                  //Test the number on the column
                  for(int iBlockR = i; iBlockR < (i + 27); iBlockR += 9)
                     for (int iBlockC = iBlockR; iBlockC < (iBlockR + 3); iBlockC++)
                        if(!newBoard.isFixedValue[iBlockC])
                           total += newBoard.isPossibleValue[iBlockC][guess - 1];


                  if (total == 1)//We have found an answer!
                     for(int iBlockR = i; iBlockR < (i + 27); iBlockR += 9)
                        for (int iBlockC = iBlockR; iBlockC < (iBlockR + 3); iBlockC++)
                           if (newBoard.isPossibleValue[iBlockC][guess - 1] &&
                               !newBoard.isFixedValue[iBlockC])
                           {
                              newBoard.values[iBlockC] = guess;
                              newBoard.isFixedValue[iBlockC] = true;
                              noChanges = false;
                           }
               }
            }

         //Fill in one possible answer squares and exit if solved
         if (checkPossibles(newBoard))
            return true;
      }while(noChanges == false);

      //If not solved by now, Time to use the big guns
      if (!isSolved(newBoard))
         bruteForce(newBoard);

      //Output time it took to solve board
      return (clock() - startTime) / 1000.0;
}

/**********************************************************************
 * This will go to the first empty square and fill it in with the first
 * valid number and then advance to the next square. If it finds a square
 * where all numbers fail it backtraces and fills in the last square with
 * the next valid number and will continue until the Board is solved.
 ***********************************************************************/
bool bruteForce(Board &board)
{
   int coordinates = 0;
   int guess = 1;

   for (int i = 0; i < 81;i++)
   {
      //Check for solved if on last square
      if (i == 81 && isSolved(board))
         return true;

      //Go to next non fixed cell
      while (board.isFixedValue[i])
         i++;

      //Set guess to 1 more than current value in cell and reset value
      guess = board.values[i] + 1;
      board.values[i] = 0;

      for (; board.values[i] == 0 && guess <= 9; guess++)
         if (board.isPossibleValue[i][guess -1] &&
             canChange(board, i , guess))
            board.values[i] = guess;

      //If ALL #s fail go back to previously changed value
         else
            if (guess == 9)
            {
               //Step one back
               i--;

               //Continue to previous cell until value isn't fixed or 9 or
               //has only one possible value
               while(board.isFixedValue[i] || board.values[i] == 9)
               {
                  //If value is 9 needs to be set back to zero
                  if (board.values[i] == 9 && !board.isFixedValue[i])
                     board.values[i] = 0;
                  i--;
               }
               i--; //Will be incremented after loop
            }


   }
   return true;
}

/**********************************************************************
 * Loops through to see if the board is solved / all values filled in
 ***********************************************************************/
bool isSolved(Board board)
{
   //If at least one value is zero the board is not solved
   for (int i = 0; i < 81; i++)
      if (board.values[i] == 0)
         return  false;
   return true;
}

/**********************************************************************
 * Clears all values that aren't fixed values
 ***********************************************************************/
void clearBoard(Board &board)
{
   for (int i = 0; i < 81; i++)
      if (!board.isFixedValue[i])
         board.values[i] = 0;
   return;
}

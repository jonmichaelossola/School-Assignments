/***********************************************************************
* Program:
*    Assignment 02, Record Keeping       
*    Brother Macbeth, CS165
* Author:
*    Jon Michael Ossola
* Summary: 
*    In the program below, it takes in a file from the user, and 
*    loops through the contents of that file. Next, the program
*    takes in a time stamp from the user and then uses that time
*    stamp to determine which contents of the file to display to 
*    the screen. Finally, the program displays those contents.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      Figuring out how to store the contents of the file in the array.
************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

/*******************************************************************
* This is the structure which contains the user name, the name of 
* the file, as well as the time stamp.
*******************************************************************/
struct Position 
{
   string userName;
   string fileName;
   long timeStamp;
};

/*****************************************************************
* The function below takes in a file from the user, and then 
* stores the elements of the file in an array of the structure.
******************************************************************/
int readFile(const string recordName, Position accessRecord[])
{
   ifstream fin(recordName.c_str()); // opens file
   
   if (fin.fail())
   {
      return 0;
   }
   
   int x = 0; // counting variable initialized

   // stores contents of file in an array of structures.
   while (fin >> accessRecord[x].fileName >> accessRecord[x].userName
          >> accessRecord[x].timeStamp) 
   {                               
      x++;                                                  
   }
   
   fin.close();
   return x;
}

/*****************************************************************
* In the time stamp below, the function asks for the start time 
* and the end time. Also the function is pass by value.
******************************************************************/
void timeStamp(long &startTime, long &endTime)
{
   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
}

/*****************************************************************
* This function takes in a structure from the user of the record
* and displays that record to the screen.
*******************************************************************/
void displayRecords(const Position record) 
{
   cout << setw(15) << record.timeStamp;
   cout << setw(20) << record.fileName;
   cout << setw(20) << record.userName;
   cout << endl;
}

/****************************************************************
* The function below takes in the array of structures, as well 
* as the time stamps, and passes structures of the records
* to the function above to have them printed to the screen, if 
* they fit into the time stamp given.
****************************************************************/
void accessRecords(const long startTime, const long endTime, 
                   const Position accessRecord[], const int sizeFile)
{
   cout << "The following records match your criteria:\n";
   cout << endl;
   cout << setw(15) << "Timestamp" << setw(20) << "File";
   cout << setw(21) << "User\n";
   cout << "--------------- ------------------- -------------------\n";

   // accesses records within the time stamp and passes them to 
   // another function.
   for (int x = 0; x < sizeFile; x++) 
   {                               
      if (accessRecord[x].timeStamp >= startTime
          && accessRecord[x].timeStamp <= endTime)
      {
         displayRecords(accessRecord[x]);
      }
   }
   cout << "End of records\n";
   
}


/**********************************************************************
 * In the main function, here all of the other functions are called as
 * well as the array of structures is declared, as well as the other
 * variables. 
 ***********************************************************************/
int main()
{
   Position accessRecord[500];
   string recordName;
   cout << "Enter the access record file: ";
   cin >> recordName;
   cout << endl;

   int sizeFile = readFile(recordName, accessRecord);
   
   long startTime;
   long endTime;
   timeStamp(startTime, endTime);
   cout << endl;
   
   accessRecords(startTime, endTime, accessRecord, sizeFile);
   
   
   return 0;
}

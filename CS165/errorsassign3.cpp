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
*      Configuring the catch try and throw statements.
************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
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

/**************************************************************
* The function below checks the line if there are any errors
* and if there aren't any, it returns a structure.
**************************************************************/
Position parseLine(string line) throw (string)
{
   stringstream ss;
   ss.str(line);

   Position record;

   // store elements of the line in a structure
   ss >> record.fileName;
   ss >> record.userName;
   ss >> record.timeStamp;
   // check for errors
   if (ss.fail())
   {
      throw line;
   }
      
   // make sure that the time stamp isn't wrong
   if (record.timeStamp < 1000000000 || record.timeStamp >
      10000000000)
      throw line;

   return record;
}

/**************************************************************
* The function below takes a file and line by line sends the
* lines to the parse line function above. It also stores the 
* contents of the file in an array.
****************************************************************/
int parseFile(string recordName, Position accessRecord[])
{
   string line;
   
   ifstream fin(recordName.c_str());

   if (fin.fail())
   {
      cout << "Error reading File\n";
      return 0;
   }

   int x = 0;

   // reads file line by line and passes lines 
   // into the parse line function
   while (getline(fin, line))
   {
      try
      {
         accessRecord[x] = parseLine(line);         
      }
      catch (string message)
      {
         cout << "Error parsing line: ";
         cout << message; 
         cout << endl;
      }
      x++;
   }
   
   fin.close();

   return x;
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
         cout << setw(15) << accessRecord[x].timeStamp;
         cout << setw(20) << accessRecord[x].fileName;
         cout << setw(20) << accessRecord[x].userName;
         cout << endl;
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
   
   int sizeFile = parseFile(recordName, accessRecord);
   cout << endl;
   
   long startTime;
   long endTime;
   timeStamp(startTime, endTime);
   cout << endl;
   
   accessRecords(startTime, endTime, accessRecord, sizeFile);
   
   
   return 0;
}

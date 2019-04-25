/***********************************************************************
* Program:
*    Assignment 42, 
*    Brother Cook, CS124
* Author:
*    Jon Michael Ossola
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part was the for loop in the first function.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
string generateSong(string list[], int num)
{
   string output;

   list[0] += " bone connected to the foot bone\n";
   list[1] += " bone connected to the leg bone\n";
   list[2] += " bone connected to the knee bone\n";
   list[3] += " bone connected to the hip bone\n";
   list[4] += " bone connected to the back bone\n";
   list[5] += " bone connected to the neck bone\n";
   list[6] += " bone connected to the jaw bone\n";
   list[7] += " bone connected to the ";
   list[8] += " bone\n";

   for (int i = 0; i < num; i++)
   {
      output += list[i];
   }

   
   // your code goes here

   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   string list[9] =
   {
      "toe",
      "foot",
      "leg",
      "knee",
      "hip",
      "back",
      "neck",
      "jaw",
      "head"
   };

   // generate the song
   string song = generateSong(list, 9);

   // display the results
   cout << song;
   
   return 0;
}

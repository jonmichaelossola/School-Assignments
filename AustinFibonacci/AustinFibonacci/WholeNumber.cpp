/***********************************************************************
 * Class:
 *    WholeNumber
 * Summary:
 *    This will handle the adding up of the last, big number.
 *
 * Author
 *    Austin Nelson
 **********************************************************************/  
#include "WholeNumber.h"
#include <iomanip>
using namespace std;


/***********************************************************************
 * Name: Overload operator: =
 * Data Type: WholeNumber
 * Parameters: The rigth hand side of the object
 * Return: the left hand side
 * Purpose: To copy things
 ************************************************************************/
WholeNumber & WholeNumber :: operator = (WholeNumber & rhs)
{
    this->total = rhs.total;
    return *this;
}

/***********************************************************************
 * Name: Overload operator: +=
 * Data Type: WholeNumber
 * Parameters: The integer to add
 * Return: the left hand side
 * Purpose: To add things onto the left side
 ************************************************************************/
WholeNumber & WholeNumber :: operator += (WholeNumber & rhs) throw (const char *)
{
    List<unsigned int> newList;
    unsigned int rem = 0;
    ListIterator<unsigned int> left = this->total.rbegin();
    ListIterator<unsigned int> right = rhs.total.rbegin();
    
    while (left != this->total.rend() || right != rhs.total.rend())
    {
        int list1 = (left == this->total.rend() ? 0 : *left);
        int list2 = (right == rhs.total.rend() ? 0 : *right);
        
        newList.push_front((list1+list2+rem) % 1000);
        rem = (list1+list2+rem) / 1000;
        
        if (left != this->total.rend()) left--;
        if (right != rhs.total.rend()) right--;
    }
    
    if (rem == 1) { newList.push_front(1); }
    
    this->total = newList;
    return *this;
}

/***********************************************************************
 * Name: Overload operator: <<
 * Data Type: ostream
 * Parameters: The rigth hand side of the object and an ostream
 * Return: out
 * Purpose: print stuff in a specific way
 ************************************************************************/
ostream & operator << (std::ostream & out, WholeNumber & rhs)
{
    out << "\t";
    for (ListIterator<unsigned int> it = rhs.total.begin(); it != rhs.total.end(); ++it)
    {
        // TODO figure out a way to not print out the last comma
        if (*it != *(rhs.total.rbegin()))
        {
            out << setfill('0') << setw(3) << *it << ",";
        }
        else
            out << setfill('0') << *it;
    }
    out << endl;
    return out;
}

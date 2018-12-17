/******************************************************************************
 * Author: Granit Arifi
 * Date: 9/25/2018
 * Description: This function takes in a string, and two integers representing
 * minimum and maximum values for your input validation.
 * The function then checks if each character in the string is a digit as well
 * as checking if the string converted to an int exceeds the max value of an int
 * *****************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>
#include "validateInput.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool validateInput(string s, int min, int max)
{
    int menuInput;
    bool negCheck = false;  // check for negative sign
    if (s.empty())
    {
        return false;
    }

    // Loop through each character in the string
    // and check if it is a digit.
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(0) == '-' && s.length() > 1 && negCheck == false)
        {
            negCheck = true;
            i++;
            continue;
        }
        else if (!isdigit(s.at(i)))
        {
            return false;
        }
    }
    
    // Do a try/catch on converting the string to an int
    // using stoi. This only executes if the above passes
    // I developed this portion to check for extremely large
    // values like "99999999999999999999999" being passed in.
    try {
        menuInput = stoi(s);
    }

    catch(std::out_of_range)
    {
        return false;
    }

    // Checks if the input exceeds max or min values
    if (stoi(s) > max || stoi(s) < min)
    {
        return false;
    }
    return true;
}

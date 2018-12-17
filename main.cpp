/******************************************************************************
 * Program Name: dll
 * Author: Granit Arifi
 * Date: 10/27/2018
 * Description: Implements a double-linked list program that lets you
 * add to head/tail, remove from head/tail, traverse the list reversely.
 * ****************************************************************************/

#include <iostream>
#include "Node.hpp"
#include "DubLinkList.hpp"
#include "Menu.hpp" 
#include "validateInput.hpp"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;

int main()
{
    int number;
    DubLinkList list;
    ifstream numberFile("num.dat");
    if (!numberFile)
    {
        cout << "Error opening the file of numbers: " << endl;
        exit(1);
    }
    // Menu implementation
    Menu m(9);
    m.setItem("Add a new node to the head");;
    m.setItem("Add a new node to the tail");
    m.setItem("Delete from head");
    m.setItem("Delete from tail");
    m.setItem("Traverse the list reversely");
    m.setItem("Print value Head points to");
    m.setItem("Print value Tail points to");
    m.setItem("Read in list from file");
    m.setItem("Exit");
    m.display();
    while (m.getChoice() !=9)
    {
        if (m.getChoice() == 1)
        {
            cout << endl << "Enter an int to add to the head" << endl;
            string choice;
            std::getline(std::cin, choice);
            while (validateInput(choice, -99999, 99999) == false)
            {
                cout << endl << "Please enter a valid integer between -99999 and -99999" << endl;
                std::getline(std::cin, choice);
            }
            int numChoice = std::stoi(choice);
            list.addHead(numChoice);
        }
        else if (m.getChoice() == 2)
        {
            cout << endl << "Enter an int to add to the tail" << endl;
            string choice;
            std::getline(std::cin, choice);
            while (validateInput(choice, -99999, 99999) == false)
            {
                cout << endl << "Please enter a valid integer between -99999 and -99999" << endl;
                std::getline(std::cin, choice);
            }
            int numChoice = std::stoi(choice);
            list.addTail(numChoice);
        }
        else if (m.getChoice() == 3)
        {
            list.deleteHead();
        }
        else if (m.getChoice() == 4)
        {
            list.deleteTail();
        }
        else if (m.getChoice() == 5)
        {
            list.displayRev();
        }
        else if (m.getChoice() == 6)
        {
            list.printHeadPoint();
        }
        else if (m.getChoice() == 7)
        {
            list.printTailPoint();
        }
        else if (m.getChoice() == 8)
        {
            while (numberFile >> number)
            {
                list.addTail(number);
            }
        }
        cout << endl;
        m.display();
    } 
  
    return 0;
}

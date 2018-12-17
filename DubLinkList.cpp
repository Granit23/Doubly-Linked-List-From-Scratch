/******************************************************************************
 * Author: Granit Arifi
 * Date: 10/27/2018
 * Description: Implements a doubley linked list that can add and remove from
 * the head and tail of the list as well as traverse the list reversely.
 * ***************************************************************************/

#include "DubLinkList.hpp"
#include "Node.hpp"
#include <iostream>

using std::cout; 
using std::endl;

void DubLinkList::addTail(int num)
{
    // creates new node with head pointing to it
    if (head == nullptr)
    {
        head = new Node(num);
        tail = head;
    }
    else
    {
        // iterates through the list until null ptr is reached
        // then adds a new node and points tail to that new node
        Node *ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;   
        }
        tail = ptr;
        ptr->next = new Node(num,nullptr,tail);
        tail = ptr->next;
 
    }
    display();
}


void DubLinkList::addHead(int num)
{
    if (head == nullptr)
    {
        // if list is empty, have head point to a new node with the number.
        head = new Node(num);
        tail = head;
      //  cout << "Head: " << head->val << endl;
       // cout << "Tail: " << tail->val << endl;
    }
    else
    {
        // Set temp to a new Node object, and set the next variable to point to head
        Node *temp = new Node(num, head);

        // Set the prev variable at the head to point to temp
        head->prev = temp;

        // Now set the new head to be where temp is.
        head = temp;

    }
    display();

}

void DubLinkList::deleteHead()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    // Check if there is just 1 item left in the list and delete it.
    else if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        
    }
    else
    {
        //sets head to the next node, deletes the current node 
        Node *tmp = head;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
    }
    display();
}

void DubLinkList::deleteTail()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else if (tail == head)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node *temp;
        temp = tail->prev;
        delete tail;
        tail = temp;
        if (temp != nullptr)
        {
            tail->next = nullptr;
        }
    }
    display();
}

DubLinkList::~DubLinkList()
{
    Node *ptr = head;
    while  (ptr != nullptr)
    {
        Node *garbage = ptr;
        ptr = ptr->next;
        delete garbage;
    }
}

void DubLinkList::displayRev()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *ptr = tail;
        while (ptr != nullptr)
        {
            cout << ptr->val << "   ";
            ptr = ptr->prev;
        }
    }
}

void DubLinkList::display()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else 
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->val << "   ";
            ptr = ptr->next;
        }
    }
}

void DubLinkList::printHeadPoint()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "Value that head is pointing to: " << head->val << endl;
    }
    display();
}

void DubLinkList::printTailPoint()
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        cout << "Value that tail is pointing to: " << tail->val << endl;
    }
    display();
}
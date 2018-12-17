/******************************************************************************
 * Author: Granit Arifi
 * Date: 10/27/2018
 * Description: Node class to be used by linked lists and doubly-linked lists
 * ***************************************************************************/

#include "Node.hpp"

Node::Node(int val, Node *next, Node *prev)
{
    this->val = val;
    this->next = next;
    this->prev = prev;

}



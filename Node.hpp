/******************************************************************************
 * Author: Granit Arifi
 * Date: 10/27/2018
 * Description: Node class to be used by linked lists and doubly-linked lists
 * ***************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

class Node 
{
    public:
        Node *next;
        Node *prev;
        int val;
        Node(int, Node *next1 = nullptr, Node *prev1 = nullptr);

};

#endif
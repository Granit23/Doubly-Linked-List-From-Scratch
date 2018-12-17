/******************************************************************************
 * Author: Granit Arifi
 * Date: 10/27/2018
 * Description: Implements a doubley linked list that can add and remove from
 * the head and tail of the list as well as traverse the list reversely.
 * ***************************************************************************/
 
 #ifndef DUB_LINK_LIST_HPP
 #define DUB_LINK_LIST_HPP

 #include "Node.hpp"

 class DubLinkList
 {
    protected:
       // Node *head;
        //Node *tail;
    
    public:
        Node *head;
        Node *tail;
        DubLinkList() { head = tail = nullptr;}
        ~DubLinkList();
        void addHead(int);
        void addTail(int);
        void deleteHead();
        void deleteTail();
        void displayRev();
        void display();
        void printHeadPoint();
        void printTailPoint();
        
 };

 #endif
#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
	protected:
        int size;
        Node *head;
    public:

        LinkedList();
        LinkedList(int);
        LinkedList(const LinkedList &);

        ~LinkedList();

        void insert(int);
        void removeByValue(int);
        void removeByPosition(int);
        bool search(int value);
        
		LinkedList& operator =(const LinkedList& x);
        friend ostream& operator <<(ostream &salida1,const LinkedList& C);
};

#endif

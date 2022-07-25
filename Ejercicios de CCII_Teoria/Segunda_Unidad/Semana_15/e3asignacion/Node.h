#ifndef __NODE_H__
#define __NODE_H__

class Node{    
    private:
        int value;
        Node *next;
    public:
        Node(int _value = 0 , Node* _next = nullptr): 
            value(_value), next(_next){}

		int getValue() const;
        void setValue(int);

		Node* getNext() const;               
        void setNext(Node*);

};

#endif

#include "Node.h"

void Node::setValue(int _value){
    this->value = _value;
}

int Node::getValue() const {
    return value;
}

void Node::setNext(Node *_next){
    this->next = _next;
}

Node* Node::getNext() const{
    return next;
}


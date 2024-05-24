#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

MultiMap::MultiMap() {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    head = nullptr;
}

void MultiMap::add(TKey c, TValue v) {
//to make it more efficient: add to beginning
    //BEST CASE: theta(1) -- e Empty
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    TElem element(c,v);
    Node* new_Node = new Node;
    new_Node->data = element;
    //if empty put it to beginning
    if(isEmpty() == true){
        new_Node->next = nullptr;
        head = new_Node;
    }
    //if not empty put it to end
    else {
        //i == current position
        Node *i = head;
        while (i->next != nullptr) {
            i = i->next;
        }
        i->next = new_Node;
        new_Node->next = nullptr;
    }
}


bool MultiMap::remove(TKey c, TValue v) {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    if(isEmpty() == true)
        return false;

    TElem element(c,v);
    Node* i = head;     //current node
    Node* j = nullptr;     //previous node

    //nu a ajuns la capat si na gasit elementul
    while(i != nullptr && i->data != element){
            j = i;
            i = i->next;
    }

    //prima poz
    if(i != nullptr && j == nullptr){
        head = head->next;
        return true;
    }
    //sterge elementul, care nu e head
    else if(i != nullptr){
        j->next = i->next;
        i->next = nullptr;
        return true;
    }
    return false;
}


vector<TValue> MultiMap::search(TKey c) const {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    vector<TValue> values{};
    if(isEmpty() == true)
        return values;      //empty list of values
    Node* i = head;         //current node
    while(i != nullptr){
        if(c == i->data.first){
            values.push_back(i->data.second);
        }
        i = i->next;
    }

    return values;
}


int MultiMap::size() const {
    //BEST CASE: theta(1) -- empty
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    int count = 0;
    //i = current position
    Node* i = head;
    if(isEmpty() == true)       //count = 0
        return 0;

    while(i != nullptr){
        count++;
        i = i->next;
    }
	return count;
}


bool MultiMap::isEmpty() const {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    if(head == nullptr){
        return true;
    }
	return false;
}

MultiMapIterator MultiMap::iterator() const {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
	return MultiMapIterator(*this);
}

MultiMap::~MultiMap() {
    //BEST CASE: theta(1) -- if head null
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    if(head != nullptr){
        while(head->next != nullptr){
            Node* aux = head;
            head = head->next;
            delete aux;
        }
        delete head;
    }
    else
        delete head;
}


void MultiMap::invert_container() {
    //pre: container in originally given form
    //post: container inverted
    //BEST CASE: theta(n)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: theta(n)
    Node* i = head;         //current
    Node* j = nullptr;      //previous
    Node* current_next = nullptr;
    while(i != nullptr){
        current_next = i->next;
        i->next = j;
        j = i;
        i = current_next;
    }
    i=j;
}
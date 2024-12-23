#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
    //best case: theta(1)
    //average case:theta(log n)
    //worst case:theta(n)
    //gesamt:O(n)
    head = nullptr;
    current = -1;
    int node = map.root;
    while (node != -1) {
        Stack* newNode = new Stack();
        newNode->position = node;
        newNode->next = head;
        head = newNode;
        node = map.left[node];
    }
    if (head != nullptr) {
        current = head->position;
    } else {
        current = -1;
    }
}

void SMIterator::first(){
    //best case: theta(1)
    //average case:theta(log n)
    //worst case:theta(n)
    //gesamt:O(n)
    while (head != nullptr) {
        Stack* current_node = head;
        head = head->next;
        delete current_node;
    }

    int node = map.root;
    while (node != -1) {
        Stack* newNode = new Stack;
        newNode->position = node;
        newNode->next = head;
        head = newNode;
        node = map.left[node];
    }

    if (head != nullptr) {
        current = head->position;
    } else {
        current = -1;
    }
}

void SMIterator::next(){
    //best case: theta(1)
    //average case:theta(1) - prea mica ramura de stanga
    //worst case:theta(n)
    //gesamt:O(n)
    exception xception;
    if(!valid())
        throw xception;

    Stack *aux = head;
    head = head->next;
    int node = aux->position;
    delete aux;
    if(map.right[node] != -1){
        node = map.right[node];
        while(node != -1){
            Stack *newNode = new Stack;
            newNode->position = node;
            newNode->next = head;
            head = newNode;
            node = map.left[node];  //node <- [node].left
        }
    }
    if(head != nullptr){
        current = head->position;   //current <- top()
    }
    else{
        current = -1;
    }
}

bool SMIterator::valid() const{
    //theta(1)
    return (current != -1);
}

TElem SMIterator::getCurrent() const{
    //theta(1)
    exception xception;
    if(current == -1)
//    if(head == nullptr)
        throw xception;
    return map.info[current];
}



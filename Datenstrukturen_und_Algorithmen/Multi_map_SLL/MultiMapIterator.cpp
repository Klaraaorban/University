#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {

    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    current = c.head;
}

TElem MultiMapIterator::getCurrent() const{
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    exception xeption;
    if(valid() == false)
        throw xeption;

    else return current->data;
}

bool MultiMapIterator::valid() const {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    if(current != nullptr)
        return true;
    return false;
}

void MultiMapIterator::next() {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    exception xeption;
    if(valid() == true){
        current = current->next;
    }
    else throw xeption;
}

void MultiMapIterator::first() {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    current = col.head;
}


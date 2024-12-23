#include "SetIterator.h"
#include "Set.h"
#include <exception>
#include <stdexcept>

using namespace std;

SetIterator::SetIterator(const Set& m) : set(m)
{
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    position = 0;
}


void SetIterator::first() {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    position = 0;
}


void SetIterator::next() {
//the function increases the iterator, if the next position is valid
//->else returns an exception
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)

    exception xeption;
    if(valid() == true)
    {
        position++;
    }
    else throw xeption;

}


TElem SetIterator::getCurrent()
{
//returns the current element if its valild
//->else returns an exception
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    exception xeption;
    if(valid() == false)
        throw xeption;
    else return *&set.arr[position];
}


TElem SetIterator::modifyCurrent(TElem new_form) {
    if(!valid()){
        throw std::out_of_range("not valid");
    }
    if(new_form < 0){
        throw std::out_of_range("not existing element");
    }
    return set.arr[position] = new_form;
}

bool SetIterator::valid() const {
//verifies whether the iterator is valid
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    if(set.isEmpty() == false && set.m_size != position)
        return true;
    return false;
}




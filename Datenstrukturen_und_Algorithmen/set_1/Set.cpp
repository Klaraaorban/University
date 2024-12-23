#include "Set.h"
#include "SetIterator.h"

using namespace std;

void Set::resize_up() {
    //BEST CASE: theta(n)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: theta(n)
    m_length = m_length * 2;
    TElem *p = new int [m_length];
    for (int i=0; i<m_size; i++)
        p[i] = arr[i];
    delete[] arr;       //theta(n)
    arr = p;
}

void Set::resize_down() {
    //BEST CASE: theta(n)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: theta(n)
    m_length = m_length/2;
    TElem *p;
    p = new TElem [m_length];
    for(int k=0; k<m_size; k++)
        p[k] = arr[k];
    delete[] arr;       //theta(n)
    arr = p;
}

Set::Set() {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    m_size = 0;
    m_length = 5;
    arr = new TElem [m_length];
}


bool Set::add(TElem elem) {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
//element added to the initially empty array --> returns true
    //complexity: theta(1)
    if(isEmpty() == true)
    {
        arr[m_size] = elem;
        m_size++;
        return true;
    }

//element was already in the array --> returns false
    //complexity: theta(n) <-- siehe: search(elem)
    if(search(elem) == true) {
        return false;
    }

//if element wasn't in the array
        //complexity: theta(n)
    else{
        //if current capacity is the entire length of the array:
        //double the length and resize the array  --> theta(n)
        if(m_size == m_length){
            resize_up();
        }
//if there is space for a new element, add the ELEM to the end of the array(after the last element)
        arr[m_size++] = elem;
        return true;
    }

    return false;
}


bool Set::remove(TElem elem) {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
//the array is empty
    //complexity: theta(1)
    if(isEmpty() == true)
        return false;

//the element isn't in the array->return false
    //complexity: theta(n) <-- siehe: search(elem)
    if(search(elem) == false)
        return false;


//the element exists, so it needs to be removed
    //complexity: theta(n)
    int i = 0;
    while(i < m_size)
    {
        if(arr[i] == elem)
        {
                arr[i] = arr[m_size - 1];
            break;
        }
        i++;
    }
    m_size--;

//resizing the array
    //complexity: theta(n)
    if(m_size <= m_length/4)
    {
        resize_down();
    }

    return true;
}

bool Set::search(TElem elem) const {
//returns true if found, false if not
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: O(n)
    for(int i=0; i<m_size; i++)
    {
        if(arr[i] == elem)
            return true;
    }
    return false;
}


int Set::size() const {
//returns the number of elemenets from the array
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    return m_size;
}


bool Set::isEmpty() const {
//verifies if the array is empty
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    if(m_size == 0)
        return true;
    return false;
}


Set::~Set() {
    //BEST CASE: theta(n)
    //AVERAGE CASE: theta(n)
    //WORST CASE: theta(n)
    //GESAMT: theta(n)
    delete [] arr;
}


SetIterator Set::iterator() const {
    //BEST CASE: theta(1)
    //AVERAGE CASE: theta(1)
    //WORST CASE: theta(1)
    //GESAMT: theta(1)
    return SetIterator(*this);
}



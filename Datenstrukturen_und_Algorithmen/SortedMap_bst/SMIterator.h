#pragma once
#include "SortedMap.h"

struct Stack{
    int position;
    Stack *next;
    int dimension;
    int capacity;
};
//DO NOT CHANGE THIS PART
class SMIterator{
    friend class SortedMap;
private:
    const SortedMap& map;
    SMIterator(const SortedMap& mapionar);

    int current;
    Stack *head;

public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};


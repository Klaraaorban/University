#pragma once
#include "Set.h"

class SetIterator
{
    //DO NOT CHANGE THIS PART
    friend class Set;
private:
    //DO NOT CHANGE THIS PART
    const Set& set;
    SetIterator(const Set& s);

    int position;          //current position

public:
    void first();
    void next();
    TElem getCurrent();
    TElem modifyCurrent(TElem new_form);
    bool valid() const;
};



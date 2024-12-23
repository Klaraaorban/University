#pragma once

#include <list>
#include "MultiMap.h"
//inversarea listei
class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& col;
//    struct SLLIterator {
//        MultiMap::Node *current;
//    };
    MultiMap::Node *current;        //current position
	MultiMapIterator(const MultiMap& c);

public:
	TElem getCurrent()const;
	bool valid() const;
	void next();
	void first();
};


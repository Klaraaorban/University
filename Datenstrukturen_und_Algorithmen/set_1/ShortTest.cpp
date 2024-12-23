#include "ShortTest.h"
#include <assert.h>
#include "Set.h"
#include "SetIterator.h"

void testAll() {
    Set s;
    assert(s.isEmpty() == true);
    assert(s.size() == 0);
    assert(s.add(5)==true);
    assert(s.add(1)==true);
    assert(s.add(10)==true);
    assert(s.add(7)==true);
    assert(s.add(1)==false);
    assert(s.add(10)==false);
    assert(s.add(-3)==true);
    assert(s.size() == 5);
    assert(s.search(10) == true);
    assert(s.search(16) == false);
    assert(s.remove(1) == true);
    assert(s.remove(6) == false);
    assert(s.size() == 4);


    SetIterator it = s.iterator();
    it.first();
    int sum = 0;
    while (it.valid()) {
        TElem e = it.getCurrent();
        sum += e;
        it.next();
    }
    assert(sum == 19);


    //implementation and assertion of the modifyCurrent function
    Set s2;
    assert(s2.add(5)==true);
    assert(s2.add(1)==true);
    assert(s2.add(10)==true);
    SetIterator it2 = s2.iterator();
    it2.first();
    it2.next();
    int modified = 2;
    assert(it2.getCurrent() == 1);
    it2.modifyCurrent(modified);
    assert(it2.getCurrent() == modified);

}


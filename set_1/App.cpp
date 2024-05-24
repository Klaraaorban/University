#include "Set.h"
#include "SetIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

//10. ADT Set – repräsentiert mithilfe eines dynamischen Arrays von Elementen

int main() {

    testAll();
    testAllExtended();

    cout << "That's all!" << endl;
    system("pause");

}
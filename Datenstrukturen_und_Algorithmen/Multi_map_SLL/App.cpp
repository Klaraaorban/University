#include <iostream>
#include "MultiMap.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include "MultiMapIterator.h"

using namespace std;

//17. ADT MultiMap – repräsentiert mithilfe einer SLL von Paaren der Form (key, value). Ein
//Schlüssel kann mehrmals vorkommen.

int main() {


	testAll();
	testAllExtended();
	cout << "End" << endl;
	system("pause");

}

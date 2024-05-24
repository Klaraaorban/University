#include <iostream>
#include "duration.h"
#include <cassert>

using namespace std;

void test(){
    Duration a("min", 12.0);
    Duration b("min", 8.0);
    double number = 2;

    Duration r_add = a+b;               // test_ a+b
    assert(r_add.get_value() == 20.0);

    Duration r_subs = a-b;
    assert(r_subs.get_value() == 4.0);  // test_ a-b

    a*number;
    double test1 = a.get_value();
    assert(test1 == 24.0);
    cout<<endl;

    b/number;
    assert(b.get_value() == 4.0);
//    cout<<endl;

    assert(a.compare(b) == 1);
}

//int main(){
//    test();
//    return 0;
//}
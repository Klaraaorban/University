#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
#include <sstream>
#include "DSM.h"
using namespace std;

void test_constr2(){
    string myElements[9] = {"CPU", "GPU", "RAM", "Motherboard", "PSU", "InDEV", "OutDEV", "SpecialDEV", "IOController"};
    DSM s(myElements, 9);

    s.addLink("Motherboard", "CPU", 1);
    s.addLink("Motherboard", "GPU", 1);
    s.addLink("Motherboard", "RAM", 1);
    s.addLink("Motherboard", "PSU", 1);
    s.addLink("Motherboard", "InDEV", 1);
    s.addLink("Motherboard", "OutDEV", 1);
    s.addLink("GPU", "PSU", 2);
    s.addLink("CPU", "SpecialDEV", 3);
    s.addLink("InDEV", "IOController", 3);
    s.addLink("OutDEV", "IOController", 3);
    assert(s.hasLink("GPU", "PSU") == true);
    assert(s.linkWeight("GPU", "PSU") == 2);
    assert(s.countToLinks("GPU") == 1);
    assert(s.countFromLinks("GPU") == 1);
    assert(s.countAllLinks() == 10);
}

void test_constr1(){
    DSM destr(5);

    destr.setElementName(0, "a");
    destr.setElementName(1, "b");
    destr.setElementName(2, "c");
    destr.setElementName(3, "d");
    destr.setElementName(4, "e");
    destr.setElementName(5, "f");
    assert (destr.size() == 6);
    assert (destr.getName(1) == "b");

    destr.addLink("c", "e", 1);
    destr.addLink("a", "c", 1);
    destr.addLink("e", "g", 8);

    assert(destr.hasLink("c", "e") == true);
    assert(destr.linkWeight("e", "g") == 8);
    assert(destr.countToLinks("c") == 1);
    assert(destr.countFromLinks("c") == 1);
    assert(destr.countAllLinks() == 3);
}

string* left_elements(const string& filename, int count) {
    ifstream f(filename);
    string line;
    count = 0;
    const int max_line = 100;
    string* e_left = new string[max_line];

    while (getline(f, line) && count < max_line) {
        istringstream s(line);
        getline(s, e_left[count], ',');
        count++;
    }

    return e_left;
}

int* middle_elements(const string& filename, int& count) {
    ifstream f(filename);
    string line;
    count = 0;
    const int max_line = 100;
    int* e_middle = new int[max_line];

    while (getline(f, line) && count < max_line) {
        istringstream s(line);
        string element;
        getline(s, element, ',');
        getline(s, element, ',');
        e_middle[count] = stoi(element);
        ++count;
    }

    return e_middle;
}

string* right_elements(const string& filename, int& count) {
    ifstream f(filename);
    string line;
    count = 0;
    const int max_line = 100;
    string* e_right = new string[max_line];

    while (getline(f, line) && count < max_line) {
        istringstream s(line);
        string element;
        getline(s, element, ','); // Skip the left and middle elements
        getline(s, element);
        e_right[count] = element;
        ++count;
    }

    return e_right;
}

int main() {
    DSM destr(5);

    destr.setElementName(0, "a");
    destr.setElementName(1, "b");
    destr.setElementName(2, "c");
    destr.setElementName(3, "d");
    destr.setElementName(4, "e");
    destr.setElementName(5, "f");
    assert (destr.size() == 6);
    assert (destr.getName(1) == "b");

    destr.addLink("c", "e", 1);
    destr.addLink("a", "c", 1);
    destr.addLink("e", "g", 8);
    destr.printEverything();
    cout<<endl;
//    DSM s2 = destr;
//    s2.printEverything();
    cout<<endl;

    string myElements[9] = {"CPU", "GPU", "RAM", "Motherboard", "PSU", "InDEV", "OutDEV", "SpecialDEV", "IOController"};
    DSM s(myElements, 9);

    s.addLink("Motherboard", "CPU", 1);
    s.addLink("Motherboard", "GPU", 1);
    s.addLink("Motherboard", "RAM", 1);
    s.addLink("Motherboard", "PSU", 1);
    s.addLink("Motherboard", "InDEV", 1);
    s.addLink("Motherboard", "OutDEV", 1);

    s.addLink("GPU", "PSU", 2);

    s.addLink("CPU", "SpecialDEV", 3);
    s.addLink("InDEV", "IOController", 3);
    s.addLink("OutDEV", "IOController", 3);
    assert(s.hasLink("GPU", "PSU") == true);

//    s.deleteLink("CPU", "SpecialDEV");

    s.printEverything();
    cout << endl;
    cout << "Link weight: " << s.linkWeight("GPU", "PSU") << endl;
    cout << s.countToLinks("GPU") << endl;
    cout << s.countFromLinks("GPU") << endl;
    cout << s.countAllLinks() << endl;



//    int count = 9;
//
//    string* left_elems = left_elements("date.csv", 9);
//    int* middle_elems = middle_elements("date.csv", count);
//    string* right_elems = right_elements("date.csv", count);
//
//    DSM file(left_elems,9);
////    cout<<endl;
//    for(int i=0; i<count; i++){
//        file.addLink(left_elems[i], right_elems[i], middle_elems[i]);
//    }
//
//    file.printEverything();
//    delete[] left_elems;
//    delete[] middle_elems;
//    delete[] right_elems;

//TODO test
//    test_constr1();
//    test_constr2();
    return 0;

}

#include <iostream>
#include "duration.h"

using namespace std;

void main_duration() {
    Duration a("",0);
    a.read();
    Duration b("",0);
    b.read();
    double number;
    cout << "Write a number: ";
    cin>>number;

//      time conversions
    Duration converted_a = a.convert(b);
    Duration converted_b = b.convert(a);
    cout << "Convert: " << converted_a.get_value() << "(min)" << endl;
    cout << "Convert: " << converted_b.get_value() << "(min)"   << endl;
        //    Duration result_add = a.add(b);
    Duration result_add = converted_a + converted_b;
    cout <<"Add: " <<result_add.get_value() << " (min)" << endl;

//    Duration result_substract = a.substract(b);
    Duration result_substract = converted_a - converted_b;
    cout <<"Substract: " <<result_substract.get_value() << " (min)" <<endl;

//    a.scale(number);      cout << "Multiply: " << a.get_value()<<endl;
    cout << "Multiply: ";   converted_a * number;     cout<< " (min)" << endl;

    //    b.divide(number);   cout << "Divide: " << b.get_value() << endl;
    cout << "Divide: ";     converted_b / number;     cout << " (min)" << endl;

    string my_string = b.text();
    cout << "String repr: " <<typeid(my_string).name()<<endl;


    cout << "Comparation: ";
    if(converted_a.compare(converted_b) == -1) {cout << "a < b";}
    else if(converted_a.compare(converted_b) == 1) {cout << "a > b";}
    else if(converted_a.compare(converted_b) == 0) {cout << "a = b";}

    cout<<endl;
}


int main(){
    main_duration();
    return 0;
}
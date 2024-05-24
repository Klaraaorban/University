#include <iostream>
#include <string>
using namespace std;
struct Kundendaten{int nummer; string name; int post; string ort;} list[10];
int main(){
    list[0].nummer = 1;
    list[0].name = "Anna";
    list[0].post = 535200;
    list[0].ort = "here";
    cout<<list[0].post;
    return 0;

}
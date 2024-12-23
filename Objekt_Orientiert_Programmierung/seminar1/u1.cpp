#include <iostream>
#include <string>
using namespace std;
int main(){
    string nach, vor;
    cout <<"Nachname:";
    cin>>nach;
    cout <<"Vorname:";
    cin>>vor;
    cout<<nach<<" "<<vor;
    int len_name = nach.length() + vor.length();
    cout<<len_name;
    return 0;

}
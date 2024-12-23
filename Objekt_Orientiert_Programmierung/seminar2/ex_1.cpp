#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_vector(){
    int n = 0;
    vector <string> a;
    string line;
    ifstream f("date.in");
    ofstream g("date.out");
    while(getline(f, line) and n < 5){
        a.push_back(line);
        n++;
    }
    for(int i=0; i<a.size(); i++) {
        cout << a[i] << "\n";
        g << a[i] << "\n";
    }
    f.close();
}



void read_line(){
    string line;
    int x, n = 0;
    string file_in_name, file_out_name;
    cout << "Give the name of the in-file:";
    cin >> file_in_name;
    ifstream f(file_in_name);
    cout << "Give the name of the out-file:";
    cin >> file_out_name;
    ofstream g(file_out_name);
    while(getline(f, line) and n<5){
        cout << line << "\n";
        g << line << "\n";
        n++;
    }
}
int main(){
//    read();
//    read_line();
    read_vector();
}
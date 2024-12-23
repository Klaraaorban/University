#include "Konto.h"
#include <iostream>
#include <fstream>

using namespace std;

Konto ::Konto(float soldo) {
    soldo = 10;
}

void Konto::auszahlen(float betrag) {
    if(soldo - betrag >= 0){soldo -= betrag;}
    else {cout<< "n-ai bani";}
    soldo -= betrag;
}

void Konto::einzahlen(float betrag) {
    soldo += betrag;
}

float Konto::kontostand(){
    return soldo;
}

void Konto::print_transaction() {
    string in_out;
    float betrag, saldo;
    ifstream f("datei.txt");
    ofstream g("datei.out");
    while(f>>in_out>>betrag>>saldo){
        g<< in_out << " " << betrag << " " << saldo << "\n";
    }
}
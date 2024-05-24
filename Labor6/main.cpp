#include <iostream>
#include "GewichteterGraph.h"
using namespace std;

int main() {
    GewichteterGraph g("data.txt");
    g.findHamiltonian();
    g.nachstenNachbarHeuristik();
    return 0;
}

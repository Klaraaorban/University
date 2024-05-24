#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph g("date.in");
    g.printGraph();
    g.AngrenzendeKnoten(4);
    g.printPfad(1,4);
    return 0;
}

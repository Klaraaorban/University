#include <iostream>
#include "Graph.h"

int main() {
    Graph g("date.in");
//    g.printGraph();
    g.topologicalSort();
    return 0;
}
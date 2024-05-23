#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph g("data.txt");
//    g.printEdges();
    g.DFS(0);
    g.zussamenhangskomponente();
    return 0;
}
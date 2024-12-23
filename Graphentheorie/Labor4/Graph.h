#ifndef LABOR4_GRAPH_H
#define LABOR4_GRAPH_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Graph {
private:
    map<int, list<int>> adj;
    map<int, int> in_degree;

public:
    Graph(const string& filename);
    void addEdge(int start, int end);
    void printGraph() const;
    void topologicalSort();
};



#endif //LABOR4_GRAPH_H

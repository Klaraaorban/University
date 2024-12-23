#ifndef LABOR2_GRAPH_H
#define LABOR2_GRAPH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Graph {
private:

    int n;
    int m;
    string filename;
    std::vector <int> adjList[100];

public:

    Graph(string filename);

    void addEdge(int x, int y);

    void printGraph();

    void AngrenzendeKnoten(int n);

    void printPfad(int x, int y);
};

#endif //LABOR2_GRAPH_H

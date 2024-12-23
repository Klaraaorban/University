//
// Created by dellg3 on 3/14/2024.
//

#ifndef GRAPHENTHEORIE_GRAPH_H
#define GRAPHENTHEORIE_GRAPH_H


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

    bool isEdge(int x, int y);

    void printGraph();

    void printDegrees();

    void kreis(int x, string filename);
};


#endif //GRAPHENTHEORIE_GRAPH_H


#ifndef LABOR5_GRAPH_H
#define LABOR5_GRAPH_H


#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;
class Graph {
private:
    struct Kante {
        int fromNode, toNode;
        Kante* next;
    };
    Kante* head;
    int n, m;

public:
    Graph(std::string filename);
    void addEdge(int x, int y);
    void printEdges();
    void kantenzug();
    void dfs(int k, map<int, list<int>>& adj_list, list<int>& path);

};


#endif //LABOR5_GRAPH_H

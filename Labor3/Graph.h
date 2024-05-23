#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

#ifndef LABOR3_GRAPH_H
#define LABOR3_GRAPH_H
using namespace std;

class Graph {
private:
    int n, m;
    std::vector<std::pair<int, int>> Kanten;
    std::vector<bool> visited;

//tests if its conex or not, while also adding the not connected ones
    void DFS_alk(int v, std::set<int>& component) {
        visited[v] = true; //only visit the Kante only once
        component.insert(v);
        for (auto& kante : Kanten) { //if its not connected-then add
            if (kante.first == v && !visited[kante.second]) { //unvisited Kante
                DFS_alk(kante.second, component);
            } else if (kante.second == v && !visited[kante.first]) { //connected to another one
                DFS_alk(kante.first, component);
            }
        }
    }

public:
    Graph(const std::string& filename);

    void printEdges();

    void DFS(int x);

    void zussamenhangskomponente();
};
#endif //LABOR3_GRAPH_H

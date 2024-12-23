#include "Graph.h"
#include <iostream>
#include <string>
using namespace std;

Graph::Graph(const std::string &filename) {
    ifstream file(filename);
    file >> n >> m;
    visited.resize(n, false);
    int u, v;
    while (m--) {
        file >> u >> v;
        Kanten.emplace_back(u-1, v-1);
//        append the new element to the container
    }
    file.close();

}

void Graph::DFS(int x) {
    set<int> component;
    DFS_alk(x, component);
    cout<<"DFS: ";
    for (int Knote : component) {
        cout <<Knote + 1 << " ";
    }
    cout << endl;
}

void Graph::zussamenhangskomponente() {

    int count = 0;
    fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            set<int> component;
            DFS_alk(i, component);
            count++;
            cout << "Group of connected elements: ";

            for (int Knote : component) {
                cout << Knote + 1<< " ";
            }
            cout << endl;
        }
    }
    cout << "Anzahl der Zusammenhangskomponenten: " << count << endl;

}

void Graph::printEdges() {
    for (const auto& kante : Kanten) {
        cout << kante.first << " - " << kante.second << endl;
    }
}
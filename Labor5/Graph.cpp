#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include "Graph.h"

using namespace std;

Graph::Graph(std::string filename):head(nullptr), n(0), m(0) {
    ifstream f(filename);
    f >> n >> m;
    for (int i = 0; i < m; i++) {
        f >> n >> m;
        addEdge(n, m);
    }
    f.close();
}

void Graph::addEdge(int x, int y) {
    Kante* newEdge = new Kante{x, y, head};
    head = newEdge;
}

void Graph::printEdges() {
    Kante* current = head;
    cout << "Kanten: ";
    while (current != nullptr) {
        cout << "(" << current->fromNode << ", " << current->toNode << "), ";
        current = current->next;
    }
}

void Graph::kantenzug() {
    //kantenlist-->adj liste
    map<int, list<int>> adj_list;
    Kante* current = head;
    while (current) {
        adj_list[current->fromNode].push_back(current->toNode);
        adj_list[current->toNode].push_back(current->fromNode);
        current = current->next;
    }

    int count_old = 0;
    int starting_point = 0;
    for (auto i : adj_list) {
        if (i.second.size() % 2 != 0) {
            count_old++;
            starting_point = i.first;
        }
    }

//    if(count_old != 0 || count_old != 2){
//        cout << "existiert nicht";
//    }

    list<int> kantenzug;
    dfs(starting_point, adj_list, kantenzug);

    for(int i: kantenzug){
        cout << i << " - " << endl;
    }
}

void Graph::dfs(int k, map<int, list<int>> &adj_list, list<int> &kantenzug) {
    while (!adj_list[k].empty()) {
        int next = adj_list[k].front();
        adj_list[k].pop_front();
        adj_list[next].remove(k);
        dfs(next, adj_list, kantenzug);
    }
    kantenzug.push_front(k);
}
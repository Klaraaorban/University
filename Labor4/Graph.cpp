#include <queue>
#include "Graph.h"
using namespace std;
Graph::Graph(const string &filename) {
    ifstream f(filename);
    int n, m, start, end;
    f >> n >> m;
    while (m--) {
        f >> start >> end;
        addEdge(start, end);
    }

    f.close();
}

void Graph::addEdge(int start, int end) {
    adj[start].push_back(end);
}

void Graph::printGraph() const {
    for (const auto& i : adj) {
        cout << i.first << ": ";
        for (int j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Graph::topologicalSort() {
    std::queue<int> S;
    std::vector<int> L;
    int visited_count = 0;

    // cauti toate nodurile cu in-degree 0
    for (auto& i : in_degree) {
        if (i.second == 0) {
            S.push(i.first);        // si le salvezi
        }
    }

    while (!S.empty()) {
        int knote = S.front();
        S.pop();
        L.push_back(knote);
        visited_count++;

        //decrementezi in_degree
        //current order is in topological order
        for (int i : adj[knote]) {
            in_degree[i]--;

            //if in_degree == 0 save it in the queue
            if (in_degree[i] == 0) {
                S.push(i);
            }
        }
    }

    //daca visited_count != marimea de adj --> ciclu
    if (visited_count != adj.size())
    {
        cout << "Graph enthalt einen Kreis" << endl;
    }
    else {
        for (int i : L) {
            cout << i << " ";
        }
        cout << endl;
    }
}
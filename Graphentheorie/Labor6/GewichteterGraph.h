#ifndef LABOR6_GEWICHTETERGRAPH_H
#define LABOR6_GEWICHTETERGRAPH_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class GewichteterGraph {

private:
    int n,m;
    vector<vector<int>> kosten_matrix;

public:
    GewichteterGraph(string file);
    void addEdge(int x, int y, int k);
    bool isEdge(int x, int y);
    void findHamiltonian();
    void print_hamiltonian(vector<int> &path, vector<bool> &visited);
    void nachstenNachbarHeuristik();
};

#endif //LABOR6_GEWICHTETERGRAPH_H

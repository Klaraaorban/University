#include "GewichteterGraph.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

GewichteterGraph::GewichteterGraph(std::string file) {
    ifstream f(file);
    f>>n;
    f>>m;
    kosten_matrix.resize(n, vector<int>(n,0));
    int a, b, k;
    for(int i = 0; i<m; i++){
        f>>a>>b>>k;
        addEdge(a,b,k);
    }
    f.close();
}

void GewichteterGraph::addEdge(int x, int y, int k) {
    kosten_matrix[x][y] = k;
    kosten_matrix[y][x] = k;
}

bool GewichteterGraph::isEdge(int x, int y) {
    if(kosten_matrix[x][y] != 0){
        return true;
    } else return false;
}

void GewichteterGraph::print_hamiltonian(vector<int> &path, vector<bool> &visited) {
    if(path.size() == n){
        int cost = 0;
        //kreis?
        if(isEdge(path.back(), path[0])){
            for(int i = 0; i<n-1; i++){
                cost += kosten_matrix[path[i]][path[i+1]];
            }
            cost += kosten_matrix[path[n-1]][path[0]];

            cout << "Hamiltonian Cycle: ";
            for(int i: path){
                cout << i << ", ";
            }
            cout << " start: " << path[0] << " (cost: " << cost << " )" << endl;
        }
        return;
    }
    //nod in kreis?
    for(int j = 0; j<n; j++){
        if(!visited[j]){
            path.push_back(j);
            visited[j] = true;
            //reapelez
            print_hamiltonian(path, visited);

            path.pop_back();
            visited[j] = false;

        }
    }
}

void GewichteterGraph::findHamiltonian() {
    vector<int> path;
    vector<bool> visited(n, false);

    for(int i=0; i<n; i++){
        path.clear();
        path.push_back(i);
        visited[i]=true;
        print_hamiltonian(path, visited);
        visited[i] = false;
    }
}


void GewichteterGraph::nachstenNachbarHeuristik() {
    vector<bool> visited(n, false);
    vector<int> path;
    int cost = 0;

    int current = 0;
    path.push_back(current);
    visited[current] = true;

    for(int i=0; i < n-1; i++){
        int next = -1;
        int min_cost = INT_MAX;

        //not visited smallest neighbour
        for(int j=0; j<n; j++){
            if(!visited[j] && kosten_matrix[current][j] !=0 && kosten_matrix[current][j] < min_cost){
                min_cost = kosten_matrix[current][j];
                next = j;
            }
        }
        if(next != -1){
            //found->psuh
            path.push_back(next);
            visited[next] = true;
            cost += min_cost;
            current = next;
        }
        else{
            cerr << "No neighbour for vertex: " << current << endl;
            break;
        }
    }
    cost += kosten_matrix[path.back()][path[0]];
    cout << endl;
    cout << "Heuristik Hamiltonian: ";
    for(int k: path){
        cout << k << ", ";
    }
    cout <<endl << "Starting point: " << path[0] << " (cost: " << cost << " )" << endl;
}


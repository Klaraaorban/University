//
// Created by dellg3 on 3/14/2024.
//

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Graph::Graph(string filename) {

    ifstream f(filename);
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x,y);
    }
    f.close();
}

void Graph::addEdge(int x, int y){
    adjList[y].push_back(x);
    adjList[x].push_back(y);
}

bool Graph::isEdge(int x, int y){
    return find(adjList[x].begin(), adjList[x].end(), y) != adjList[x].end();
}

void Graph::printGraph(){
    for (int i = 0; i < n; i++) {
        cout<<i<<":[";
        for (int j: adjList[i]) {
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
}

void Graph::printDegrees(){
    int k = 0;
    unsigned long long degrees[100];
    for (int i = 0; i < n; i++) {
        degrees[k++] = adjList[i].size();
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k - i; j++)
            if(degrees[j] < degrees[j+1])
                swap(degrees[j],degrees[j+1]);
    }
    for (int i = 0; i < k; i++)
        cout<<degrees[i]<<endl;
}

void Graph::kreis(int x, string filename){

}
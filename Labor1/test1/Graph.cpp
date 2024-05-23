#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph(){

    ifstream f;
    f.open("data.in");
    f >> n;
    f >> m;
    int x,y;
    for(int i=0; i<m; i++){
        f>>x>>y;
        addEdge(x,y);
    }

}

void Graph::addEdge(int x, int y){
    matrix[x][y] = 1;
    matrix[y][x] = 1;
}

bool Graph::isEdge(int x, int y){
    return matrix[x][y] == 1;
}

void Graph::printGraph(){
    for (int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int Graph::maximalGrad() {
    int maxi = 0;
    for (int i=1; i<n;i++){
        int s=0;
        for(int j=1; j<n; j++) {
            s += matrix[i][j];
        }
        if(s>maxi)
            maxi = s;
    }
    return maxi;
}

int Graph::minimalGrad() {
    int mini = 0;
    for (int i=1; i<n;i++){
        int s=0;
        for(int j=1; j<n; j++) {
            s += matrix[i][j];
        }
        if(s<mini)
            mini = s;
    }
    return mini;
}
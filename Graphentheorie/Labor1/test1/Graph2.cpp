#include "Graph2.h"
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

Graph2::Graph2(){

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

void Graph2::addEdge(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

bool Graph2::isEdge(int x, int y){
    //alternativ literati prin vector si cautati-l pe x in lista adiacenta
    //a lui y
    return find(adjList[x].begin(), adjList[x].end(),y)!= adjList[x].end();
}

void Graph2::printGraph(){
    for (int i=0; i<n; i++) {
        cout<<i<<":[";
        for(int j: adjList[i]){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;

    }
}

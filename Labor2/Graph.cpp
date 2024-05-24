#include "Graph.h"
#include <fstream>
#include <iostream>

using namespace std;

Graph::Graph(string filename){

    ifstream f;
    f.open(filename);
    f >> n;
    f >> m;
    int x,y;

    for(int i=1; i<=m; i++){
        f>>x>>y;
        addEdge(x,y);
    }

}

void Graph::addEdge(int x, int y){
    adjList[x].push_back(y);
    adjList[y].push_back(x);
}

void Graph::printGraph(){
    for (int i=1; i<=n; i++) {
        cout<<i<<":[";
        for(int j: adjList[i]){
            cout<<j<<" ";
        }
        cout<<"]"<<endl;

    }
}

void Graph::AngrenzendeKnoten(int n) {
    cout<<"Angrenzenden knoten mit " << n << ": ";
    int grad = 0;
    for(int i: adjList[n]){
        grad ++;
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Grad " << n << " == " << grad;
    cout<<endl;


}

void Graph::printPfad(int x, int y) {
    cout<<"Print all the roads with the lenght 2 betweeen "<<x<<" and "<<y<<" : ";
    for(int i: adjList[y]){
        for(int j: adjList[x]){
            if(i == j)
                cout<<"( "<<x<<","<<i<<","<<y<<" )";
        }
    }
    cout<<endl;
}


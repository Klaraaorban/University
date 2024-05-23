//
// Created by zaxx4 on 13.03.2024.
//
#include "Graph.h"

#include<iostream>
#include<fstream>

using namespace std;

int main(){

    Graph g("data.in");
    g.printGraph();
    g.printDegrees();

}
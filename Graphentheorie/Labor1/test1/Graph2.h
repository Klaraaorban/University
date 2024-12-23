
#include <vector>

class Graph2 {
private:

    int n;
    int m;
    std::vector <int> adjList[100];

public:

    Graph2();

    void addEdge(int x, int y);

    bool isEdge(int x, int y);

    void printGraph();


};
#ifndef L3_ORBAN_KLARA_DSM_H
#define L3_ORBAN_KLARA_DSM_H
#include <string>
#include <iostream>
using namespace std;

class DSM {
private:

    int m_size, m_capacity;
    string* elementNames;
    int ** matrix;
    int initial_size = 0;


public:
    DSM(int elementCount);
    DSM(string elementNames[], int elementCount);
    DSM(const DSM &original);  //copy constructor
    ~DSM();

    int size();
    string getName(int index);
    void setElementName(int index, string elementName);
    void addLink(string fromElement, string toElement, int weight);
    void deleteLink(string fromElement, string toElement);
    bool hasLink(string fromElement, string toElement);
    int linkWeight(string fromElement, string toElement);
    int countToLinks(string elementName);
    int countFromLinks(string elementName);
    int countAllLinks();
    void printEverything();
    void _resize();
//    void resize_down();

};



#endif //L3_ORBAN_KLARA_DSM_H

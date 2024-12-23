#include "DSM.h"
#include <iostream>
using namespace std;

DSM::DSM(int elementCount) {
    initial_size = elementCount;
    m_capacity = elementCount;
    this->matrix = new int*[elementCount];
    for(int i = 0; i < elementCount; i++) {
        matrix[i] = new int[elementCount];
        for(int j=0; j<m_capacity; j++)
            matrix[i][j] = 0;
    }
    elementNames = new string[elementCount];
    for(int i=0;i<m_capacity; i++)
        elementNames[i] = "empty";
    m_size = elementCount;
}

DSM::DSM(std::string elementNames[], int elementCount) {
//    initial_size = elementCount;
    m_capacity = elementCount;
   this->elementNames = new string [elementCount];
   for(int i=0; i<elementCount; i++){
       this-> elementNames[i] = elementNames[i];
   }
   matrix = new int*[elementCount];
   for(int  i=0; i<elementCount; i++){
       matrix[i] = new int [elementCount];
       for(int j=0; j<m_capacity; j++)
            matrix[i][j] = 0;
    }
    m_size = elementCount;
}
//  copy constructor
DSM::DSM(const DSM &original){
//    first_size = original.first_size;
    m_size = original.m_size;
    m_capacity = original.m_capacity;

    elementNames = new std::string [m_capacity];
    for(int i=0; i<m_capacity; i++){
        elementNames[i] = original.elementNames[i];
    }

    matrix = new int*[m_capacity];
    for(int i=0; i<m_capacity; i++){
        matrix[i] = new int[m_capacity];
        for(int j=0; j<m_capacity; j++){
            matrix[i][j] = original.matrix[i][j];
        }
    }
}

DSM::~DSM(){
    for (int i = 0; i < m_size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    delete[] elementNames;
    elementNames = nullptr;
    cout<<"complete deletion" << " ";
    cout << "\n";
}


void DSM::setElementName(int index, std::string elementName) {
    if(index >= m_capacity)
        _resize();
    elementNames[index] = elementName;
    m_size = max(m_size, index + 1);
}


int DSM::size(){
    return m_size;
}


string DSM::getName(int index) {
    return this->elementNames[index];
}


void DSM::_resize() {
    int aux_size = m_capacity;
    m_capacity = 2 * m_capacity;
    string *aux_elementNames = new string [m_capacity];
    for(int i=0; i<m_capacity; i++)
        aux_elementNames[i] = "None";
    for(int i=0; i<aux_size; i++)
        aux_elementNames[i] = elementNames[i];
    delete[] elementNames;
    elementNames = aux_elementNames;

    int **aux_matrix = new int*[m_capacity];
    for(int i=0;i<m_capacity; i++)
        aux_matrix[i] = new int [m_capacity];
    for(int i=0; i<m_capacity; i++)
        for(int j=0; j<m_capacity; j++){
            aux_matrix[i][j] = 0;
        }

    for(int i=0; i<aux_size; i++)
        for(int j=0; j<aux_size; j++)
            aux_matrix[i][j] = matrix[i][j];
    for(int i=0; i<aux_size; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = aux_matrix;
}

void DSM::addLink(std::string fromElement, std::string toElement, int weight) {
    //TODO change to if
//    while (m_size >= m_capacity)
//        _resize();
    if(m_size >= m_capacity)
        _resize();
    int fromIDX = -1, toIDX = -1;
    for(int i=0; i<m_size; i++) {
        if(elementNames[i] == fromElement)
            fromIDX = i;
        if(elementNames[i] == toElement)
            toIDX = i;
    }

    if (fromElement == toElement) {matrix[fromIDX][toIDX] = 0;}
    else {
        if(fromIDX == -1){
        fromIDX = m_size;
        elementNames[fromIDX] = fromElement;
        m_size++;
    }

    if(toIDX == -1){
        toIDX = m_size;
        elementNames[toIDX] = toElement;
        m_size++;
    }
    matrix[fromIDX][toIDX] = weight;
    }
}

 void DSM::deleteLink(std::string fromElement, std::string toElement) {
     int fromIDX = -1;
     int toIDX = -1;
     for(int i=0; i<m_capacity; i++){
         if(elementNames[i] == fromElement)
             fromIDX = i;
         if(elementNames[i] == toElement)
             toIDX = i;
     }
     if(fromIDX == -1 || toIDX == -1){
         cout << "ELEMENT not found";
     }
     else
         matrix[fromIDX][toIDX] = 0;
 }

void DSM::printEverything() {
    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++)
            cout << matrix[i][j] << " ";
    cout << "\n";
    }
    for (int i = 0; i < m_size; i++)
        cout << elementNames[i] << " ";
    cout << "\n";
}

bool DSM::hasLink(std::string fromElement, std::string toElement) {
    int fromIDX = -1;
    int toIDX = -1;
    for(int i=0; i<m_capacity; i++){
        if(elementNames[i] == fromElement)
            fromIDX = i;
        if(elementNames[i] == toElement)
            toIDX = i;
    }
    if(matrix[fromIDX][toIDX]!=0)
        return true;
    return false;
}

int DSM::linkWeight(std::string fromElement, std::string toElement) {
    int fromIDX = -1;
    int toIDX = -1;
    for(int i=0; i<m_capacity; i++){
        if(elementNames[i] == fromElement)
            fromIDX = i;
        if(elementNames[i] == toElement)
            toIDX = i;
    }
    if (fromIDX == -1 || toIDX == -1){
        cout << "doesn't exist";
        return 0;
    }

        return matrix[fromIDX][toIDX];
}

int DSM::countToLinks(std::string elementName) {
    int idx = -1;
    for(int i=0; i<m_size; i++)
        if(elementNames[i] == elementName)
            idx = i;
    if(idx != -1){
        int count = 0;
        for(int i=0;i<m_capacity; i++)
            if(matrix[i][idx] != 0)
                count++;
        cout << "Number of TO-Links: ";
        return count;
    }
    return 0;
}

int DSM::countFromLinks(std::string elementName) {
    int idx = -1;
    for(int i=0; i<m_size; i++)
        if(elementNames[i] == elementName)
            idx = i;
    if(idx != -1){
        int count = 0;
        for(int i=0;i<m_capacity; i++)
            if(matrix[idx][i] != 0)
                count++;
        cout << "Number of FROM-Links: ";
        return count;
    }
    return 0;
}

int DSM::countAllLinks() {
    int count = 0;
    for(int i=0; i<m_capacity; i++)
        for(int j=0; j<m_capacity; j++)
            if(matrix[i][j] != 0)
                count++;
    cout << "Number of ALL-Links: ";
    return count;
}

//void DSM::resize_down(){
//    cout<<initial_size;
//    int new_capacity = m_capacity / 2;
//
//    if(m_size <= new_capacity && new_capacity >= initial_size){
//        string* aux_names = new string[new_capacity];
//        int** aux_matrix = new int*[new_capacity];
//        for(int i=0; i<new_capacity; i++){
//            aux_names[i] = elementNames[i];
//            aux_matrix = new int*[new_capacity];
//            for(int j=0; j<new_capacity; j++){
//                aux_matrix[i][j] = matrix[i][j];
//            }
//        }
//        for(int i=0;i<m_capacity; i++){
//            delete[] matrix[i];
//        }
//        delete[] matrix;
//        delete[] elementNames;
//
//        m_capacity = new_capacity;
//        elementNames = aux_names;
//        matrix = aux_matrix;
//    }
//}
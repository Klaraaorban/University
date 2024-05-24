#include "Matrix.h"
#include <exception>
using namespace std;

Matrix::Matrix(int nrLines, int nrCols) {
    //best case: theta(n)
    //average case: theta(n)
    //worst case: theta(n)
    //gesamt: theta(n)
    capacity = 10;
    nrCol = nrCols;
    nrLine = nrLines;
    arr = new Node*[capacity];
    for(int i = 0; i < capacity; i++){
        arr[i] = nullptr;
    }
}

void Matrix::resize() {
    //best case: theta(n)
    //average case: theta(n)
    //worst case: theta(n)
    //gesamt: theta(n)
    int old_capacity = capacity;
    capacity *= 2;
    Node** new_arr = new Node*[capacity];
    for(int i = 0; i < capacity; i++){
        new_arr[i] = nullptr;
    }

    for(int i = 0; i < old_capacity; i++){
        Node* current = arr[i];
        while(current != nullptr){
            Node* next = current->next;
            int new_idx = hash(current->row, current->column);
            current->next = new_arr[new_idx];
            new_arr[new_idx] = current;
            current = next;
        }
    }
    delete[] arr;
    arr = new_arr;
}

int Matrix::hash(int i, int j) const {
    return (i * nrCol + j) % capacity;
}

int Matrix::nrLines() const {
	return nrLine;
}

int Matrix::nrColumns() const {
	return nrCol;
}


TElem Matrix::element(int i, int j) const {
    exception xception;
    if(i < nrLine && i >= 0 && j < nrCol && j >= 0){
        Node* current;
        int idx = hash(i,j);
        current = arr[idx];
        while (current != nullptr) {
            if (current->row == i && current->column == j) {
                    return current->elem;
            }
            current = current->next;
        }
        return NULL_TELEM;
    }
    else{
        throw xception;
    }
}

TElem Matrix::modify(int i, int j, TElem e) {
    exception xception;
    if(i >= nrLine || i < 0 || j >= nrCol || j < 0){
        throw xception;
    }
    //resize function implementation
    int count = 0;
    for(int i = 0; i < capacity; i ++){
        Node* current = arr[i];
        while(current != nullptr){
            count++;
            current = current->next;
        }
    }
    if(count >= capacity/2){
        resize();
    }

    int idx = hash(i,j);
    Node* current = arr[idx];
    Node* prev = nullptr;
    TElem old_value = NULL_TELEM;
    while (current != nullptr) {
        if (current->row == i && current->column == j) {
            old_value = current->elem;
            if (e == NULL_TELEM) {
                //remove the element
                if (prev) {
                    prev->next = current->next;
                }
                else {
                    //update head
                    arr[idx] = current->next;
                }
                delete current;
                return old_value;
            }
            else {
                //modify node
                current->elem = e;
                return old_value;
            }
        }
        prev = current;
        current = current->next;
    }
    //not found and not null --> add new element
    if(e != NULL_TELEM){
        //add new element
        Node* new_value = new Node{i,j,e,arr[idx]};
        arr[idx] = new_value;
        old_value = NULL_TELEM;
        return old_value;
    }
    return old_value;
}

Matrix::~Matrix() {
    for(int i = 0; i < capacity; i++){
        Node* current = arr[i];
        while(current != nullptr){
            Node* del = current;
            current = current->next;
            delete del;
        }
    }
    delete[] arr;
}
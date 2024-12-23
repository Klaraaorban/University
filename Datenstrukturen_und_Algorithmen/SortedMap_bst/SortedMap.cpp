#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <vector>

using namespace std;

SortedMap::SortedMap(Relation r) {
    //best case: theta(n)
    //average case:theta(n)
    //worst case:theta(n)
    //gesamt:theta(n)
    capacity = 10;
    size_nr = 0;
    info = new TElem[capacity];
    left = new int[capacity];
    right = new int[capacity];
    this->r = r;
    for(int i = 0; i < capacity; i++){
        left[i] = i+1;
        right[i] = -1;
    }
    root = -1;
    firstEmpty = 0;
    left[capacity - 1] = -1;
}

TValue SortedMap::add(TKey k, TValue v) {
    //best case: theta(1)
    //average case:theta(log n)
    //worst case:theta(n) - dezechilibrat
    //gesamt:O(n)
    //bst empty
    if(root == -1){
        root = firstEmpty;
        firstEmpty = left[firstEmpty];
        info[root] = TElem(k,v);
        right[root] = -1;
        left[root] = -1;
        size_nr++;
        return NULL_TVALUE;
    }
    int current_node = root;
    int parent = -1;
    //find position for node
    while(current_node != -1){
        if(info[current_node].first == k){
            TValue old = info[current_node].second;     //update old node
            info[current_node].second = v;
            return old;
        }
        parent = current_node;
        if(r(info[current_node].first, k)){
            current_node = right[current_node];
        }
        else{
            current_node = left[current_node];
        }
    }
    if(firstEmpty == - 1){
        resize();

    }
    //firstEmpty
    int new_position = firstEmpty;
    firstEmpty = left[firstEmpty];
    info[new_position] = TElem(k,v);
    size_nr++;
    if(r(info[parent].first, k)){
        right[parent] = new_position;
        right[new_position] = -1;
        left[new_position] = -1;
    }
    else{
        left[parent] = new_position;
        right[new_position] = -1;
        left[new_position] = -1;
    }
    return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
    //best case: theta(1)
    //average case:theta(log n)
    //worst case:theta(n)
    //gesamt:O(n)
    int current_node = root;
    while(current_node != -1  && (r(info[current_node].first, k) || r(k, info[current_node].first))){
        //k == key(current)
        if(info[current_node].first == k){
            return info[current_node].second;
        }
        //k > key(current) -> moves to right branch/child
        if(r(info[current_node].first, k)){
            current_node = right[current_node];
        }
            //k < key(current) -> moves to left branch/child
        else{
            current_node = left[current_node];
        }
    }
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
    //best case: theta(1)
    //average case:theta(log(2)n)
    //worst case:theta(n)
    //gesamt:O(n)
    if (root == -1) {   //->empty bst
        return NULL_TVALUE;
    }

    int current_node = root;
    int parent = -1;
    bool left_child = true;

    //find to be removed node
    while (current_node != -1 && info[current_node].first != k) {
        parent = current_node;
        if (r(k, info[current_node].first)) {
            left_child = true;
            current_node = left[current_node];
        } else {
            left_child = false;
            current_node = right[current_node];
        }
    }

    if (current_node == -1) {   //not found
        return NULL_TVALUE;
    }

    TValue removed_value = info[current_node].second;

    //case 1: no children
    if (left[current_node] == -1 && right[current_node] == -1) {
        if (parent == -1) {
            root = -1;
        } else if (left_child) {
            left[parent] = -1;
        } else {
            right[parent] = -1;
        }
    }
    //case 2: 1 child
    else if (left[current_node] == -1 || right[current_node] == -1) {
        int child = (left[current_node] != -1) ? left[current_node] : right[current_node];
        if (parent == -1) {
            //remove root
            root = child;
        } else if (left_child) {
            left[parent] = child;
        } else {
            right[parent] = child;
        }
    }
    //case 3: 2 children
    else {
        //smallest node on the right
        int nach_parent = current_node;
        int nachfolger = right[current_node];
        while (left[nachfolger] != -1) {
            nach_parent = nachfolger;
            nachfolger = left[nachfolger];
        }

        info[current_node] = info[nachfolger];

        //remove nachfolger
        if (nach_parent == current_node) {
            right[nach_parent] = right[nachfolger];
        } else {
            left[nach_parent] = right[nachfolger];
        }

        current_node = nachfolger;
    }

    left[current_node] = firstEmpty;    //new firstEmpty
    firstEmpty = current_node;
    size_nr--;

    return removed_value;

}

int SortedMap::size() const {
    //theta(1)
    //add: size_nr++
    //remove: size_nr--
    return size_nr;
}

bool SortedMap::isEmpty() const {
    //theta(1)
	return (size_nr == 0);
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
    //theta(n)
    delete[] info;
    delete[] right;
    delete[] left;
}


void SortedMap::resize() {
    //theta(n)
    int oldCap = capacity;
    capacity *= 2;
    TElem  *new_info = new TElem [capacity];
    int *new_left = new int[capacity];
    int *new_right = new int[capacity];

    for(int i = 0; i < oldCap; i++){
        new_info[i] = info[i];
        new_right[i] = right[i];
        new_left[i] = left[i];
    }
    delete[] info;
    delete[] right;
    delete[] left;
    info = new_info;
    right = new_right;
    left = new_left;
    for(int i = oldCap; i < capacity; i++){
        left[i] = i+1;
        right[i] = -1;
    }
    firstEmpty = oldCap;
    left[capacity - 1] = -1;
}

void SortedMap::inorder_travelsal(int current_node, TElem *elems, int idx) const {
    if (current_node == -1) return;
    inorder_travelsal(left[current_node], elems, idx);
    elems[idx++] = info[current_node];
    inorder_travelsal(right[current_node], elems, idx);
}

bool SortedMap::operator==(SortedMap &container2) const {
    if (size_nr != container2.size_nr) {
        return false;
    }
    TElem* elem1 = new TElem[size_nr];
    TElem* elem2 = new TElem[size_nr];
    int idx1=0, idx2=0;

    inorder_travelsal(root, elem1, idx1);
    container2.inorder_travelsal(container2.root, elem2, idx2);

    bool egal = true;
    for (int i = 0; i < size_nr; ++i) {
        if (elem1[i] != elem2[i]) {
            egal = false;
            break;
        }
    }
    delete[] elem1;
    delete[] elem2;

    return egal;
}


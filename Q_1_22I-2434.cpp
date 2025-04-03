
#include <iostream>
#include <fstream>
#include <sstream>

template <class T>
class Heap {
    T* arr;
    int size;
    int top;
    bool isMinHeap;
    int nChild;

public:
    Heap() {
        this.size = 0;
        this.top = -1;
        this->nChild = 2; // suppose its a binary heap initially
        this->isMinHeap = false; // tentative
        this.arr = new T[0];
    }

    Heap() {
        delete[] arr;
    }
    void insert() {

    }

    T extract_min() {
        
    }

    T extract_max() {
        return arr[top];
    }

    T extract() {
        T ele = heapType == 'max'? extract_max() : extract_min();
        return ele;
    }

    void print() {

    }
private:
    int parent(int c) {
        return (c - 1) / nChild;
    }

    int child(int p) {
        return p * nChild;
    }
    void heapify() {

    }
};

int main() {
    Heap<int> h;

    ("text.txt");
    return 0;
}
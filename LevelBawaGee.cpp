
#include "LevelBawaGee.hpp"

#include <iostream>
#include <sstream>
#include <fstream>


/*
    Utility Methods for dynamic resizing of containers
*/

template <class T>
T*& LevelBawaGee<T>::inc(T*& arr, int old_size, T newEle) {
    T *newArr = new T[old_size + 1];
    int i = 0;
    while (i < old_size) { 
        newArr[i] = arr[i];
        i++;
    }
    delete[] arr;

    newArr[old_size] = newEle;
    arr = newArr;
    old_size++;

    return arr;
}

template <class T>
T*& LevelBawaGee<T>::dec(T*& arr, int size) {
    T *newArr = new int[size - 1];
    int i = 0;

    size--;
    while (i < size) {
        newArr[i] = arr[i];
        i++;
    }
    delete[] arr;
    arr = newArr;
    return arr;
}

/*
    Question 4
*/
  
template <class T>
void LevelBawaGee<T>::read_q4(Gadgets* gadgets, const char* fileNameWithExtension) {
    std::ifstream in(fileNameWithExtension);
    std::stringstream ss;

    in >> gadgets->nTestCases;

    gadgets->arr = new int*[gadgets->nTestCases];
    for (int i = 0; i < gadgets->nTestCases; i++) {
        // get the number of products
        int nProducts;
        in >> nProducts;
        
        // allocate memory
        gadgets->arr[i] = new int[nProducts];
        // make the productSizes array work as a map to keep track of products of each test case
        gadgets->productSizes = LevelBawaGee<int>::inc(gadgets->productSizes, i, nProducts);
        for (int p = 0; p < nProducts; p++) {
            in >> gadgets->arr[i][p];
        }
    }
    in.close();
}

template <class T>
void LevelBawaGee<T>::print_gadgets_q4(Gadgets gadgets) {
    for (int i = 0; i < gadgets.nTestCases; i++)
    {
        for (int j = 0; j < gadgets.productSizes[i]; j++)
        {
            std::cout << gadgets.arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

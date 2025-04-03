
#include "LevelBawaGee.hpp"
#include <iostream>

template <class T>
T*& LevelBawaGee<T>::inc(T*& arr, int& size, T newEle) {
    T *newArr = new T[size + 1];
    int i = 0;
    while (i < size) { 
        newArr[i] = arr[i];
        i++;
    }
    delete[] arr;

    newArr[size] = newEle;
    arr = newArr;
    size++;

    return arr;
}

template <class T>
T*& LevelBawaGee<T>::dec(T*& arr, int& size) {
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
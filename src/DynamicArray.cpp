#include "../include/DynamicArray.h"
#include <iostream>
#include <algorithm>
using namespace std;

DynamicArray::DynamicArray(int n) : data(new int[n]()), size(n) {}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::show(){
    for (int i = 0;i < size;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void DynamicArray::set(int index, int value){
    if (0 <= index && index < size && -100 <= value && value <= 100){
        data[index] = value;
    }
}

int DynamicArray::get(int index) const {
    if (0 <= index && index < size){
        return data[index];
    }
    return 0;
}

DynamicArray::DynamicArray(DynamicArray& other){
    size = other.size;
    data = new int[size];
    for (int i = 0;i < size;i++){
        data[i] = other.data[i];
    }
}

void DynamicArray::append(int value){
    if (-100 <= value && value <= 100){
        int* newdata = new int[size+1];
        for (int i = 0; i < size; i++) {
            newdata[i] = data[i];
        }
        newdata[size] = value;

        delete[] data;
        data = newdata;
        size++;
    }
}

void DynamicArray::add(DynamicArray& other){
    for (int i = 0; i < min(other.size, size);i++){
        data[i] += other.data[i];
    }
}

void DynamicArray::sub(DynamicArray& other){
    for (int i = 0; i < min(other.size, size);i++){
        data[i] -= other.data[i];
    }
}

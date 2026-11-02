#include "../include/DynamicArray.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

DynamicArray::DynamicArray(int n){
    if (n < 0){
        throw invalid_argument("Size cannot be negative");
    }
    size = n;
    data = new int[size]();
}

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
    if (index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    if (value < -100 || value > 100){
        throw invalid_argument("Value must be from -100 to 100");
    }
    data[index] = value;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    return data[index];
}

DynamicArray::DynamicArray(DynamicArray& other){
    size = other.size;
    data = new int[size];
    for (int i = 0;i < size;i++){
        data[i] = other.data[i];
    }
}

void DynamicArray::append(int value){
    if (value < -100 || value > 100){
        throw invalid_argument("Value must be from -100 to 100");
    }
    int* newdata = new int[size+1];
    for (int i = 0; i < size; i++) {
        newdata[i] = data[i];
    }
    newdata[size] = value;

    delete[] data;
    data = newdata;
    size++;
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

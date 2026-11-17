#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <typeinfo>
using namespace std;

template <typename T>
class DynamicArray {
    T* data;
    int size;

    void checkIndex(int index){
        if (index < 0 || index >= size){
            throw out_of_range("Index out of range");
        }
    }

    void checkValue(T value, true_type){
        if (static_cast<long double>(value) < -100 || static_cast<long double>(value) > 100){
            throw invalid_argument("Value must be from -100 to 100");
        }
    }

    void checkValue(T, false_type){}

    double calculateDistance(DynamicArray& other, true_type){
        if (size != other.size){
            throw invalid_argument("Arrays must have the same size");
        }
        double sum = 0;
        for (int i = 0; i < size; i++){
            double difference = static_cast<double>(data[i]) - static_cast<double>(other.data[i]);
            sum += difference * difference;
        }
        return sqrt(sum);
    }

    double calculateDistance(DynamicArray&, false_type){
        throw bad_typeid();
    }

public:
    class Element {
        DynamicArray& array;
        int index;

    public:
        Element(DynamicArray& array, int index) : array(array), index(index) {}

        Element& operator=(T value){
            array.set(index, value);
            return *this;
        }

        Element& operator=(const Element& other){
            array.set(index, other.array.get(other.index));
            return *this;
        }

        operator T(){
            return array.get(index);
        }
    };

    DynamicArray(int n){
        if (n < 0){
            throw invalid_argument("Size cannot be negative");
        }
        size = n;
        data = new T[size]();
    }

    DynamicArray(DynamicArray& other){
        size = other.size;
        data = new T[size];
        for (int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }

    ~DynamicArray(){
        delete[] data;
    }

    void show(){
        for (int i = 0; i < size; i++){
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void set(int index, T value){
        checkIndex(index);
        checkValue(value, is_integral<T>());
        data[index] = value;
    }

    T get(int index) {
        checkIndex(index);
        return data[index];
    }

    Element operator[](int index){
        checkIndex(index);
        return Element(*this, index);
    }

    void append(T value){
        checkValue(value, is_integral<T>());
        T* newdata = new T[size+1];
        for (int i = 0; i < size; i++){
            newdata[i] = data[i];
        }
        newdata[size] = value;

        delete[] data;
        data = newdata;
        size++;
    }

    void add(DynamicArray& other){
        for (int i = 0; i < min(other.size, size); i++){
            data[i] += other.data[i];
        }
    }

    void sub(DynamicArray& other){
        for (int i = 0; i < min(other.size, size); i++){
            data[i] -= other.data[i];
        }
    }

    bool operator==(DynamicArray& other){
        if (size != other.size){
            return false;
        }
        for (int i = 0; i < size; i++){
            if (!(data[i] == other.data[i])){
                return false;
            }
        }
        return true;
    }

    bool operator!=(DynamicArray& other){
        return !(*this == other);
    }

    DynamicArray& operator+=(DynamicArray& other){
        add(other);
        return *this;
    }

    DynamicArray& operator-=(DynamicArray& other){
        sub(other);
        return *this;
    }

    DynamicArray& operator+=(T value){
        for (int i = 0; i < size; i++){
            data[i] += value;
        }
        return *this;
    }

    DynamicArray& operator-=(T value){
        for (int i = 0; i < size; i++){
            data[i] -= value;
        }
        return *this;
    }

    T* begin(){
        return data;
    }

    T* end(){
        return data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }

    double distance(DynamicArray& other){
        return calculateDistance(other, is_arithmetic<T>());
    }

    friend ostream& operator<<(ostream& out, DynamicArray& array){
        for (int i = 0; i < array.size; i++){
            out << array.data[i] << " ";
        }
        return out;
    }
};

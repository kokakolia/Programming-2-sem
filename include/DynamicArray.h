#pragma once

class DynamicArray {
    int* data;
    int size;

public:
    DynamicArray(int n);
    DynamicArray(DynamicArray& other);
    ~DynamicArray();

    void show();
    void set(int index, int value);
    int get(int index) const;
    void append(int value);
    void add(DynamicArray& other);
    void sub(DynamicArray& other);
};

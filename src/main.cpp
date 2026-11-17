#include "../include/DynamicArray.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    DynamicArray<int> a(2);
    a[0] = 3;
    a[1] = 4;
    cout << "a: " << a << endl;
    int first = a[0];
    cout << "a[0]: " << first << endl;

    try {
        a[2] = 10;
    }
    catch (out_of_range& e){
        cout << e.what() << endl;
    }

    try {
        a[0] = 101;
    }
    catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    DynamicArray<int> copy = a;
    cout << boolalpha;
    cout << "a == copy: " << (a == copy) << endl;
    copy[0] = 5;
    cout << "a != copy: " << (a != copy) << endl;

    DynamicArray<int> b(1);
    b[0] = 10;
    a += b;
    cout << "a += b: " << a << endl;
    a -= b;
    cout << "a -= b: " << a << endl;

    a += 2;
    cout << "a += 2: " << a << endl;
    a -= 1;
    cout << "a -= 1: " << a << endl;

    for (auto& x : a){
        x *= 2;
    }
    cout << "after loop: ";
    const auto& view = a;
    for (const auto& x : view){
        cout << x << " ";
    }
    cout << endl;

    DynamicArray<string> words(2);
    words[0] = "hello";
    words[1] = words[0];
    cout << "words: " << words << endl;

    return 0;
}

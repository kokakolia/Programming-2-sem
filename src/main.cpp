#include "../include/DynamicArray.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    DynamicArray<int> a(2);
    a.set(0, 3);
    a.set(1, 4);
    cout << "a: " << a << endl;

    DynamicArray<int> b(2);
    b.set(0, 0);
    b.set(1, 0);
    cout << "b: " << b << endl;
    cout << "distance: " << a.distance(b) << endl;

    DynamicArray<int> copy = a;
    copy.append(10);
    cout << "copy: " << copy << endl;

    a.add(b);
    a.sub(b);
    a.show();

    try {
        a.set(0, 101);
    }
    catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    try {
        a.get(2);
    }
    catch (out_of_range& e){
        cout << e.what() << endl;
    }

    try {
        a.distance(copy);
    }
    catch (invalid_argument& e){
        cout << e.what() << endl;
    }

    DynamicArray<double> numbers(2);
    numbers.set(0, 150.5);
    numbers.set(1, 2.5);
    cout << "numbers: " << numbers << endl;

    DynamicArray<string> words(2);
    words.set(0, "hello");
    words.set(1, "world");
    words.append("C++");
    cout << "words: " << words << endl;

    try {
        words.distance(words);
    }
    catch (bad_typeid& e){
        cout << e.what() << endl;
    }

    return 0;
}

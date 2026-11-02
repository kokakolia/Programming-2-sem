#include "../include/DynamicArray.h"
#include <iostream>
#include <stdexcept>
#include <new>
using namespace std;

int main() {
    DynamicArray a(3);
    a.show();
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, -30);
    a.show();

    cout << a.get(1) << endl;

    try {
        a.set(5, 1);
    }
    catch (const out_of_range& e){
        cout << e.what() << endl;
    }

    try {
        a.get(-1);
    }
    catch (const out_of_range& e){
        cout << e.what() << endl;
    }

    try {
        a.set(0, 500);
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }
    a.show();

    DynamicArray b = a;
    b.set(0, 99);
    cout << "a: ";
    a.show();
    cout << "b: ";
    b.show();

    a.append(40);
    try {
        a.append(200);
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }
    a.show();

    DynamicArray c(2);
    c.set(0, 1);
    c.set(1, 2);
    cout << "c: ";
    c.show();

    a.add(c);
    a.show();

    a.sub(c);
    a.show();

    c.add(a);
    c.show();

    try {
        DynamicArray d(-1);
    }
    catch (const invalid_argument& e){
        cout << e.what() << endl;
    }
    return 0;
}

#include "../include/DynamicArray.h"
#include <iostream>
using namespace std;

int main() {
    DynamicArray a(3);
    a.show();// 0 0 0
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, -30);
    a.show();// 10 20 -30

    a.set(5, 1);// ignored
    a.set(0, 500);// ignored
    a.show();// 10 20 -30

    DynamicArray b = a;
    b.set(0, 99);
    cout << "a: ";
    a.show();// 10 20 -30
    cout << "b: ";
    b.show();// 99 20 -30

    a.append(40);
    a.append(200);// ignored
    a.show();// 10 20 -30 40

    DynamicArray c(2);
    c.set(0, 1);
    c.set(1, 2);
    cout << "c: ";
    c.show();// 1 2

    a.add(c);
    a.show();// 11 22 -30 40

    a.sub(c);
    a.show();// 10 20 -30 40

    c.add(a);
    c.show();// 11 22

    return 0;
}

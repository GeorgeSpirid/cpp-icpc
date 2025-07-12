#include <iostream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

// pointers, smart pointers, and assert

class Rectangle {
    int length;
    int breadth;

public:
    Rectangle(int l, int b) {
        length = l;
        breadth = b;
    }
    int area() { return length * breadth; }
};

void increaase(void* data, int psize){
    if (psize == sizeof(int)){
        int* pint; pint=(int*)data;++(*pint);}
    else if (psize == sizeof(char)){
        char* pchar; pchar=(char*)data;++(*pchar);}
}

int addition (int a, int b){
    return a+b;
}

int substraction (int a, int b){
    return a-b;
}

int operation(int x, int y, int (*functocall)(int,int)){
    int g;
    g = (*functocall)(x,y);
    return g;
}

int main(){
    int a = 10;
    int* w = &a;
    // assert: checks if the argument compares unequal to zero and does nothing
    // otherwise, assert creates a diagnostic on the standard error stream and calls std::abort()
    assert(&a == w);

    int b;
    int* q = &b;
    *q = 20;
    cout<<b<<'\n';

    int numbers[5];
    int * p;
    p = numbers;  *p = 10;
    p++;  *p = 20;
    p = &numbers[2];  *p = 30;
    p = numbers + 3;  *p = 40;
    p = numbers;  *(p+4) = 50;
    for (int n=0; n<5; n++)
        cout << numbers[n] << " ";
    cout << '\n';

    char f ='a';
    int g = 1602;
    increaase(&f, sizeof(f));
    increaase(&g, sizeof(g));
    cout << f << " " << g << '\n';

    int m,n;
    int (*minus)(int,int) = substraction;

    m = operation(7,5,addition);
    n = operation(20,m,minus);
    cout << "m: " << m << ", n: " << n << '\n';

    // smart pointers: wrapper class over a pointer that automatically manages memory
    // auto_ptr, uniquwe_ptr, shared_ptr, weak_ptr
    
    // automatically manages the lifetime of a dynamically allocated object
    // deprecated in C++11, removed in C++17, use unique_ptr instead
    auto_ptr<int> p5(new int(10));
    cout << "auto_ptr value: " << *p5 << '\n';

    // stores one pointer only at a time, cannot be copied, can be transfered
    unique_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout << P1->area() << endl;

    unique_ptr<Rectangle> P2;

    P2 = move(P1);
    cout << P2->area();

    // more than one pointer can point to the same object at a time, maintains reference counter
    shared_ptr<Rectangle> P3(new Rectangle(10, 5));
    cout << P3->area() << endl;

    shared_ptr<Rectangle> P4;

    P4 = P3;
    cout << P4->area() << endl;
    cout << P3->area() << endl;
    cout << P3.use_count();

    // holds a non-owning reference to an object, similar to shared_ptr withouth the reference counter
    shared_ptr<Rectangle> P9(new Rectangle(10, 5));

    weak_ptr<Rectangle> P8 (P9);
    cout << P9->area() << endl;
    
    cout << P8.use_count();
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// pair, tuple, set, unordered_set, multiset, map, unordered_map, bitset

int main(){
    // pair: store two heterogeneous objects as a single unit (tuple with 2 elements)
    // functions: first, second, make_pair, swap
    pair<int, string> p1 = {1, "one"};
    pair<int, string> p2 = make_pair(2, "two");
    p1.first = 3;
    p1.second = "three";
    cout << p1.first << " " << p1.second << "\n";

    int a;
    string s;
    tie(a, s) = p1;
    cout << a << " " << s << "\n";

    // tuple: fixed-size collection of heterogeneous values
    // functions: make_tuple, tie, get, swap, tuple_size, tuple_element
    tuple<char,int,float> t1 = make_tuple('a', 1, 3.14);
    cout << get<0>(t1) << " " << get<1>(t1) << " " << get<2>(t1) << "\n";
    cout << "tuple size: " << tuple_size<decltype(t1)>::value << "\n";
    tuple<int, string, double> t2 = make_tuple(2, "two", 2.718);
    auto t3 = tuple_cat(t1, t2);
    cout << get<0>(t3) << " " << get<1>(t3) << " " << get<2>(t3) << " "
         << get<3>(t3) << " " << get<4>(t3) << " " << get<5>(t3) << "\n";

    // set: sorted collections of unique objects of same type
    // functions: begin, end, empty, size, max_size, clear, insert, insert_range, erase, swap, merge, count, find, contains
    set<int> s1 = {1, 2, 3, 4, 5};
    auto it1 = s1.begin(); 
    auto it2 = next(it1, 2);
    cout << *it1 << " " << *it2 << "\n";
    auto it3 = s1.find(3);
    if (it3 != s1.end()) {
        cout << "Found: " << *it3 << "\n";
    } else {
        cout << "Not found\n";
    }
    for (auto it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";
    cout << "\n";
    s1.erase(3);
    s1.erase(s1.begin());

    // unordered_set: stores unique objects in no particular order using hashing -> O(1)
    // functions: begin, end, empty, size, max_size, clear, insert, insert_range, erase, swap, count, find, contains
    unordered_set<int> us = {1, 2, 3, 4, 5};
    us.insert(6);
    us.insert(7);
    us.erase(3);
    for (const auto& elem : us) {
        cout << elem << " ";
    } cout << "\n";
    auto it4 = next(us.begin(), 2);
    cout << "Third element (unordered): " << *it4 << "\n";
    auto it5 = us.find(4);
    if (it5 != us.end()) {
        cout << "Found: " << *it5 << "\n";
    } else {
        cout << "Not found\n";
    }
    for(auto it = us.begin(); it != us.end(); it++)
        cout << *it << " ";
    cout << "\n";

    // multiset: sorted set of elements that allows duplicates
    multiset<int> ms = {1, 2, 2, 3, 4, 5};
    ms.insert(3);
    ms.insert(6);
    for (const auto& elem : ms) {
        cout << elem << " ";
    } cout << "\n";
    auto it6 = ms.find(2);
    if (it6 != ms.end()) {
        cout << "Found: " << *it6 << "\n";
    } else {
        cout << "Not found\n";
    }
    ms.erase(2);
    for (auto it = ms.begin(); it != ms.end(); it++)
        cout << *it << " ";
    cout << "\n";
    cout<<count(ms.begin(), ms.end(), 3) << "\n";

    // map: 

    return 0;
}

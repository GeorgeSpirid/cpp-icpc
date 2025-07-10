#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <array>
#include <iterator>
#include <ranges>


using namespace std;

// list, vector, array

int main() {
    // list: container with constant time for insertion/deletion, doesn't support fast random access
    // functions: assign, assign_range, front, back, empty, size, max_size, clear, insert, insert_range, erase, push_back, pop_back, resize, swap, merge, sort
    list<int> l = {7,5,16,8};
    l.push_front(25);
    l.push_back(13);
    // insert int before 16
    auto it = find(l.begin(), l.end(), 16);
    if (it != l.end())
        l.insert(it, 15);

    for (int n:l) {
        cout << n << " ";
    }
    cout << endl;


    // vector: container with dynamic size arrays, elements are accessed by iterator or offset, storage is handeled automatically
    // reallocates only when needed (not in every insertion)
    // random access and insertion/deletion at the end is O(1), regular insertion/deletion is O(n)
    // functions: at, front, back, [], empty, size, max_size, reserve, capacity, shrink_to_fit, clear, insert, insert_range, erase, push_back, pop_back, resize, swap
    vector<int> v = {8,4,5,9};
    v.push_back(6);
    v.push_back(9);
    v[2]=-1;

    for (int n:v) {
        cout << n << " ";
    }
    cout << endl;

    // array: encapsulates fixed size arrays
    // functions: at, [], front, back, data, empty, size, max_size, fill, swap, get, to_array
    array<int, 3> a1{{1, 2, 3}};
    array<int, 3> a2 = {1, 2, 3};
    sort(a1.begin(), a1.end());

    return 0;
}
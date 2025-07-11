#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <array>
#include <iterator>
#include <ranges>
#include <string>
#include <string_view>
#include <stack>
#include <queue>
#include <deque>
#include <cassert>
#include <functional>

using namespace std;

// use '\n' instead of endl for performance cause endl flushes the output buffer

// list, vector, array, string, string_view, stack, queue, deque, priority_queue

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

    // string
    // functions: at, [], front, back, data, c_str, empty, size, length, max_size, clear, insert, erase, push_back, pop_back, append, +=, replace, replace_with_range, resize, find, find_first_of, find_first_not_of, find_last, find_last_of, find_last_not_of, swap, compare, starts_with, ends_with, contains, substr, stoi, stof, stod, to_string
    string str1 = "Hello";
    auto str2 = "world"s;
    string str3 = str1 + " " + str2;
    string::size_type pos = str3.find(" ");
    str1 = str3.substr(pos+1);
    str2 = str3.substr(0, pos);

    cout << str1 << " " << str2 << endl;
    cout<<str1[0]<<endl;
    str1[0] = 'W'; // single quote for single character
    cout<<str1<<endl;

    // string-view: doesn't own the data
    // functions: at, [], front, back, data, size, length, max_size, empty, remove_prefix, remove_suffix, swap, copy, substr, compare, ...
    #define A "▀"
    #define B "▄"
    #define C "─"
 
    constexpr string_view blocks[]{A B C, B A C, A C B, B C A};
 
    for (int y{}, p{}; y != 8; ++y, p = ((p + 1) % 4))
    {
        for (char x{}; x != 29; ++x)
            cout << blocks[p];
        cout << '\n';
    }

    // stack
    // functions: top, empty, size, push, push_range, emplace, pop, swap
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.top()<<'\n';
    s.pop();
    cout<<s.top()<<'\n';
    cout<<s.size()<<'\n';
    cout<<(s.empty() ? "ye":"no")<<'\n';

    // reverse a string using a stack
    string str = "hello";
    stack<char> st;

    for (char c : str)
        st.push(c);

    string reversed;
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    cout << "reversed: " << reversed << '\n';

    // queue
    // functions: front, back, empty, size, push, push_range, emplace, pop, swap
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);

    assert(q.front() == 0);
    assert(q.back() == 3);
    assert(q.size() == 4);

    q.pop();
    assert(q.front() == 1);
    for (; !q.empty(); q.pop()) {
        cout << q.front() << " ";
    }
    cout << endl;
    assert(q.size() == 0);

    // deque: double-ended queue, fast insertion/deletion from both ends, indexed access to deque must perform two pointer dereferences
    // large minimal memory cost
    // random access is O(1), insertion/deletion at both ends is O(1), insertion/deletion in the middle is O(n)
    // functions: assign, at, [], front, back, empty, size, max_size, shrink-to_fit, clear, insert, insert_range, erase, push_back, pop_back, push_front, pop_front, resize, swap
    deque<int> d = {7,5,16,8};
    d.push_front(13);
    d.push_back(25);

    for (int n:d) {
        cout << n << " ";
    }
    cout << endl;

    // priority_queue: provides constant time lookup of the largest element and logarithmic insertion/extraction
    // like working with a heap in a random access container but you cannot invallidate the heap
    // functions: top, empty, size, push, push_range, pop, swap

    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);

    cout<<pq.top()<<'\n';
    pq.pop();
    cout<<pq.top()<<'\n';
    cout<<pq.size()<<'\n';

    return 0;
}
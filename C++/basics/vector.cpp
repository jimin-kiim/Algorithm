//
// Created by 김지민 on 2023/06/30.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1(3, 5); // {5, 5, 5}
    cout << v1.size() << '\n';
    v1.push_back(7); // {5, 5, 5, 7} O(1)

    vector<int> v2(2); // {0, 0}
    v2.insert(v2.begin() + 1, 3); // {0, 3, 0} O(N)

    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin() + 2); // {1, 2, 4} O(N)

    vector<int> v4; // {}
    v4 = v3; // {1, 2, 4} DEEP COPY
    cout << v4[0] << v4[1] << v4[2] << '\n'; // 124
    v4.pop_back(); // {1, 2} O(1)
    v4.clear(); // {}

    vector<int> v5 = {1, 2, 3, 4, 5, 6};

    // 1. range-based for loop (since C++11)
    for (int e : v1) {
        cout << e << ' ';
    }

    // 2. not bad
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << ' ';
    }

    // 3. WRONG
    for (int i = 0; i <= v1.size() - 1; i++) {
        cout << v1[i] << ' ';
    }
}

/**
 * push_back, pop_back: O(1)
 * push_front, pop_front: O(N)
 * insert, erase: O(N)
 */
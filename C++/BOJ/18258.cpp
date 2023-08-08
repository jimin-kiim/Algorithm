//
// Created by 김지민 on 2023/08/08.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios:: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> q;
    string command;
    int data;
    while (n--) {
        cin >> command;
        if (command == "push") {
            cin >> data;
            q.push(data);
        } else if (command == "pop") {
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (command == "size") {
            cout << q.size() << "\n";
        } else if (command == "empty") {
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        } else if (command == "front") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        } else if (command == "back") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}

/*
 * 10845와 다른 점: 시간 제한 값이 다르다.
 * 파이썬의 경우 시간을 단축하기 위해 수정할 부분이 생기지만
 * cpp은 수정할 부분이 없는 것 같다.
 */
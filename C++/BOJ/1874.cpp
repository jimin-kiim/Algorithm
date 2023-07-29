//
// Created by 김지민 on 2023/07/27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

//    list<int> base;
    int tracker = 1;
//    for (int i = 1; i < n + 1; i++) base.push_back(i);
    stack<int> s;
    bool flag = true;
    while(n--) {
        int input;
        cin >> input;
        if (input > tracker) {
            while (input != tracker) {
                s.push(tracker++);
                cout << "+\n";
            }
            tracker++;
            cout << "+\n";
            cout << "-\n";
        } else {
            while (s.top() != input) {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                s.pop();
                cout << "-\n";
            }
            if (!flag) {
                break;
            }
            s.pop();
            cout << "-\n";
        }
    }
    if (!flag) cout << "NO";
}

/*
 *
 * 4가 들어옴: 1부터 4까지 푸시 (들어온 수까지 푸시) 후 팝. 트래킹: 5
 * 5보다 작은 수인 3이 들어옴 -> 나올 때까지 pop
 * 5보다 큰 수인 6이 들어옴 -> 6까지 푸시. 후 팝. 트래킹: 7
 *
 * 트래킹 1에서 시작.
 * 들어온 수가 트래킹보다 크면 들어온 수까지 푸시 후 팝. 푸시할 때 트래킹 값 변화.
 * 작은 수가 들어오면 그 수가 나올 때까지 팝.
 *
 */
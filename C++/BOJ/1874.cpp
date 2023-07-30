//
// Created by 김지민 on 2023/07/27.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int tracker = 1;
    stack<int> s;
    bool flag = true;
    string ans;
    while(n--) {
        int input;
        cin >> input;
        while (input >= tracker) {
            s.push(tracker++);
            ans += "+\n";
        }
        if (input != s.top()) {
            flag = false;
            break;
        }
        s.pop();
        ans +=  "-\n";
    }
    if (!flag) cout << "NO";
    else for (char c: ans) cout << c;
}

/*
 *
 * 4가 들어옴: 1부터 4까지 푸시 (들어온 수까지 푸시) 후 팝. 트래킹: 5
 * 5보다 작은 수인 3이 들어옴 -> 팝
 * 5보다 큰 수인 6이 들어옴 -> 6까지 푸시. 후 팝. 트래킹: 7
 *
 * 트래킹 1에서 시작.
 * 들어온 수가 트래킹보다 크면 들어온 수까지 푸시 후 팝. 푸시할 때 트래킹 값 변화.
 * 작은 수가 들어오면 팝.
 * 이때 인풋과 팝할 대상이 다르면 오류 -> NO 출력 
 *
 */
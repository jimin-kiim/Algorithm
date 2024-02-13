//
// Created by 김지민 on 2/13/24.
//
#include <bits/stdc++.h>
using namespace std;

// a < b
int calculate_gcd(int a, int b) {
    if (a == 0) return b; // GCD(0, A) = A
    return calculate_gcd(b % a, a); // GCD(A, B) = GCD(r, A)
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dis;
    int input;
    int prev;
    cin >> prev;
    n--;
    while (n--) {
        cin >> input;
        dis.push_back(input - prev);
        prev = input;
    }

    sort(dis.begin(), dis.end());

    int gcd = dis[0];
//    cout << gcd << "\n";
    for (int i = 1; i < dis.size(); i++) {
        gcd = calculate_gcd(gcd, dis[i]);
    }
//    cout << gcd << "\n";
    int sum = 0;
    for (int i = 0; i < dis.size(); i++) {
        sum += dis[i] / gcd - 1;
    }
    cout << sum;
}

/*
 * 1, 3, 7, 13
 * -> dis: 2, 4, 6
 * -> 최대 공약수 : 2
 * -> 0, 1, 2
 * (2 / 2 - 1, 4 / 2 - 1, 6 / 2 - 1)
 *
 * dis: 2, 3, 6
 * -> 최대 공약수: 1
 * -> 1, 2, 5
 */
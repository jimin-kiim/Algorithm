//
// Created by 김지민 on 3/13/24.
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> v;
    ll in_a_day = a - b;
    ll res = (v - a) / in_a_day;
    if ((v - a) % in_a_day != 0) res++; // worst. if ((v - a) % in_a_day != 0) : at the location v-a,
    // the next step would be less than a. (a-b) so it cannot reach v. so it should move on one more additional day
    cout << res + 1; // unless, it should just move on one more day
}
/*
 * as the maximum value of v is 1,000,000,000 it would exceed the time limit 0.25s
 * if I use for-statement to find the answer
 *
 * so I thought it would be better to find out how long it takes to get closer to v
 * and then calculate the exact value
 *
 * going closer to v: use division
 * finding the exact value: use subtraction and addition
 *
 * at the end when it reaches or exceeds the distance v, it's when the snail moved 'a'
 * so first calculated how long it takes to get right before it meets the ending condition
 * -> (v-a) / (distance it moves in a day)
 */
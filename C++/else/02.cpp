//
// Created by 김지민 on 2023/08/15.
//
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int t, m;
    cin >> t;
    cin >> m;

    int time;
    while (n--) {
        cin >> time;
        m += time;
    }

    t += m / 60;
    m = m % 60;
    t = t % 24;

    cout << t << " " << m;
    return 0;
}
//
// Created by 김지민 on 3/10/24.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int res_indices[8];
int palette[8];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // getting numbers that would be used as components of the permutations
    for (int i = 0; i < n; i++) {
        cin >> palette[i];
    }
    sort(palette, palette + n);
    // to select the numbers in ascending order in each permutation

    // placing first m zeros at front and making remainders 1
    for (int i = 0; i < n; i++) res_indices[i] = (i < m ? 0 : 1);

    // traversing all the possibilities of selecting m indices for the number palette where the value 0 can be placed
    do {
        // as the zeros move towards back and it always traverses from index 0,
        // the permutations would be resulted in ascending order
        for (int i = 0; i < n; i++) {
            if (res_indices[i] == 0) cout << palette[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(res_indices, res_indices + n));
}
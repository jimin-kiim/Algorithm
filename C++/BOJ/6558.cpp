//
// Created by 김지민 on 2/13/24.
//
#include <bits/stdc++.h>
using namespace std;

#define limit 1000001
int prime[limit];

void validate_prime_numbers() {
    for (int i = 2; i < limit; i++) { // 범위 내 수 모두 돌며 소수 판별
        if (prime[i] == 0) continue; // 이미 소수가 아닌 걸로 판별한 수면 패스
        for (int j = 2 * i; j < limit; j += i) { // 해당 수에 대한 배수들 invalid 표시하기
            prime[j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(prime + 1, prime + limit, 1); // 초기화; 판별 전엔 모두 valid 상태
    validate_prime_numbers();

    while (true) {
        int input;
        cin >> input;
        if (input == 0) break;
        int a = 0, b; // 0으로의 초기화; wrong 경우 출력 조건에 필요
        for (int i = 3; i < input; i++) {
            if (prime[i] && prime[input - i]) {
                a = i;
                b = input - i;
                break; // b - a가 가장 큰 것을 출력하는 조건
            }
        }
        if (a == 0) cout << "Goldbach's conjecture is wrong.\n";
        else cout << input << " = " << a << " + " << b << "\n";
    }
}
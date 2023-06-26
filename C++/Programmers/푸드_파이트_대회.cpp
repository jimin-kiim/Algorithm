//
// Created by 김지민 on 2023/06/26.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// food
// - name = index of food
// - amount = value of food[name]
using namespace std;

string solution(vector<int> food) {
    string answer = "";

    // the first half
    for (int i = 1; i < food.size(); i++) {
        for (int j = 0; j < food[i]/2; j++) {
            answer.append(to_string(i));
        }
    }

    string half_answer = answer;

    // water
    answer.append("0");

    // the remaining half
    reverse(half_answer.begin(), half_answer.end());
    answer.append(half_answer);
    return answer;
}

int main() {
    int testcase1[] = {1, 3, 4, 6};
    vector<int> food (testcase1, testcase1 + sizeof(testcase1) / sizeof(int));
    string res = solution(food);
    cout << res;
    assert("1223330333221" == res);
}
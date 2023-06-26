//
// Created by 김지민 on 2023/06/26.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// food
// - name = index of food + 1
// - amount = value of food[name + 1]
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    for (int i = 0; i < food.size(); i++) {
        for (int j = 1; j<food[i]/2+1; j++) {
            answer.append(to_string(i));
        }
    } // til right before 0
    string half_answer = answer;
//    cout << half_answer << "\n";
    answer.append("0");
    reverse(half_answer.begin(), half_answer.end());
    answer.append(half_answer);
//    strrev(half_answer);
//    int half_size = half_answer.size();
//    for (int i = 0; i < half_size; i++) {
//        cout << half_answer[half_size - i - 1] << "\n";
//        answer.append(half_answer[half_size - i - 1]);
//    }
    return answer;
}

int main() {
    int testcase1[] = {1, 3, 4, 6};
    vector<int> food (testcase1, testcase1 + sizeof(testcase1) / sizeof(int));
    string res = solution(food);
    cout << res;
    assert("1223330333221" == res);
}
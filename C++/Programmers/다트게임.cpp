//
// Created by 김지민 on 6/13/25.
//
#include <string>
#include <bits/stdc++.h>

using namespace std;

int solutions(string dartResult) {
    int answer = 0;
    vector<int> scores;
    string string_score;
    for (int i = 0; i < dartResult.length(); i++) {

        // if (dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9) {
        if (isdigit(dartResult[i])) {
            string_score += dartResult[i];
            //int score = dartResult[i] - '0';
//            scores.push_back(score);
//            cout << score <<",";
            continue;
        }

        if (!string_score.empty()) {
            scores.push_back(stoi(string_score));
            string_score = "";
        }

        int score = scores.back();
        scores.pop_back();

        if (dartResult[i] == 'S') {
            scores.push_back(score);
        } else if (dartResult[i] == 'D') {
            scores.push_back(pow(score, 2));
        } else if (dartResult[i] == 'T') {
            scores.push_back(pow(score, 3));
        } else if (dartResult[i] == '*') {
            if(!scores.empty()) {
                int previous_score = scores.back();
                scores.pop_back();
                scores.push_back(previous_score*2);
            }
            scores.push_back(score *2);
        } else if (dartResult[i] == '#') {
            scores.push_back(-score);
        }
    }

    for (int i = 0; i < scores.size(); i++) {
        answer += scores[i];
        cout << scores[i] << " ";
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer = solutions("1S2D*3T");
    cout << endl;
    cout << answer;
}
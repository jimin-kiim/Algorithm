//
// Created by 김지민 on 6/13/25.
//
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // 동명이인 케이스 대응 못함
    // set<string> completion_set(completion.begin(), completion.end());

    // for (int i = 0; i < participant.size(); i++) {
    //     string comparison = participant[i];
    //     if (!completion_set.count(comparison)) {
    //set.erase(completion[i]);
    //         answer += comparison;
    //         break;
    //     }
    // }

    // 동명이인 처리...
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i])  {
            answer = participant[i];
            break;
        }
    }

    if (answer.empty()) answer = participant[participant.size() - 1];

    return answer;
}
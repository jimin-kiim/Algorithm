//
// Created by 김지민 on 2023/09/26.
//
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> dolls;
    int count = 0;

    for (int m = 0; m < moves.size(); m++) {
        for (int i = 0; i < board[0].size(); i++) {
            if (board[moves[m]][i] != 0) {
                if (!dolls.empty() && dolls.top() == board[moves[m]][i]) {
                    dolls.pop();
                    count += 2;
                } else if (!dolls.empty() && dolls.top() != board[moves[m]][i]) {
                    dolls.push(board[moves[m]][i]);
                } else if (dolls.empty()) {
                    dolls.push(board[moves[m]][i]);
                }
                board[moves[m]][i] = 0;
                break;
            }
        }
    }
    return count;
}
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
            int doll = board[i][moves[m] - 1];
            if (doll != 0) {
                if (dolls.empty()) {
                    dolls.push(doll);
                } else if (!dolls.empty() && dolls.top() != doll) {
                    dolls.push(doll);
                } else if (!dolls.empty() && dolls.top() == doll) {
                    dolls.pop();
                    count += 2;
                }
                board[i][moves[m] - 1] = 0;
                break;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> board = {
            {0,0,0,0,0},
            {0,0,1,0,3},
            {0,2,5,0,1},
            {4,2,4,4,2},
            {3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    cout << solution(board, moves);
}

//4
//3
//2
//1
//1
//3
//4
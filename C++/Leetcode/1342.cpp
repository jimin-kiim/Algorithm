//
// Created by 김지민 on 2023/06/28.
//

class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;
        while(num != 0) {
            if(num%2) {
                num -= 1;
            } else {
                num /= 2;
            }
            step += 1;
        }
        return step;
    }
};
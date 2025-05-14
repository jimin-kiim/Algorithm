#include <stdc++.h>
using namespace std;

// input: array consists of digits which can be duplicated.
// output: array of unique three-digit even numbers, which can be formed from the digits of the input array.

/*
 * ~= BOJ 15663, 15656(less similar)
 * difference: input is an array, not a consecutive numbers.
 *
 * solution
 * - using recursive function
 * - using 'next_permutation' method
 */

int length = 3;
int n;

int three_digit_number[4];
int palette[10];
vector<int> input_numbers;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = length(digits);
        vector<int> is_used(0, n);

        sort(digits, digits + n);

        for (int i = current; i < n; i++) {
            if (is_used[i] != 1) {
                if (i != 0 && digits[i] !=0) {
                }
            }

            do {

            } while (next_permutation(three_digit_number, three_digit_number + n));
        }
    }
};

int main() {

    // setting
    ios::sync_with_stdio(0);
    cin.tie(0);

    // getting input array
    int digit;

    while (cin >> digit) {
        palette.push_back(digit);
    }

    // leetcode solution
    Solution solution = new Solution();
    solution.findEvenNumbers(digit);
}

/*
 *  solution:
 * 1. the input should be classified if the digits are even or not.
 * 2. the last digit should be selected among the even digits.
 * 3. the middle one and the first digit can be selected from the rest of the digits.
 * -> thought of using 'tree'
 * -> the nodes that would be visited first are the even numbers and then visit the rest of the input digits.
 * -> then thought about that backtracking would be a great approach.
 * -> at first, I have thought that selecting the even numbers to be at the ones' place and the fill out the rest of the digits
 * but then I thought that the order, selecting from the ones place or from hundred's place would have the same Time Complexity.
 * and if it is, just ordering the digits starting from the front not the back would be intuitive.
 *
 * -> permutation => backtracking
 *
 */
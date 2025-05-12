#include <stdc++.h>
using namespace std;

// input: array consists of digits which can be duplicated.
// output: array of unique three-digit even numbers, which can be formed from the digits of the input array.

/*
 * solution:
 * 1. the input should be classified if the digits are even or not.
 * 2. the last digit should be selected among the even digits.
 * 3. the middle one and the first digit can be selected from the rest of the digits.
 * -> thought of using 'tree'
 * -> the nodes that would be visited first are the even numbers and then visit the rest of the input digits.
 * -> then thought about that backtracking would be a great approach.
 * -> at first, I have thought that selecting the even numbers to be at the ones' place and the fill out the rest of the digits
 * but then I thought that the order, selecting from the ones place or from hundred's place would have the same Time Complexity.
 * and if it is, just ordering the digits starting from the front not the back would be intuitive.
 */
int main() {

}
//
// Created by 김지민 on 2023/04/28.
//

/*
 * recursive Binary Search
 *
 * 1. Design Approach: Divide and Conquer
 *      Step 1. Divide the array into 2 sub arrays
 *      Step 2. Conquer the chosen array - conquering method is also D&C
 *      Step 3. Combine the solution (X)  Step 3 is omitted in this problem
 */

/*
 * 2. Implement
 */

#include <iostream>
using namespace std;

// returns the location of x in given array arr[l..r] is present, otherwise -1.
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    //  reach here when the element is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not in array"
        : cout << "Element is present at index " << result;
    return 0;
}

/*
 * 3. Analysis
 *
 * T(n) = Divide + Conquer + Combine
 *      = 1 + T(n/2) + 0
 *      = 1 + 1 + T(n/4)
 *      = 1 + 1 + 1 + T(n/8)
 *      ...
 *      = k + T(n/2^k)
 *      = log2n + T(n/n) (suppose n = 2^k)
 *      = log2n + T(1)
 *      = log2n + 1
 *      <= O(logn)
 */
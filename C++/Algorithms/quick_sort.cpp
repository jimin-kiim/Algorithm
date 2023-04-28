//
// Created by 김지민 on 2023/04/28.
//

/*
 * quick sort
 *
 * 1. Design Approach: Divide and Conquer
 *      Step 1. Divide the array into 2 sub arrays
 *      Step 2. Conquer each array - conquering method is also D&C
 *      Step 3. Combine the solution (X)  Step 3 is omitted in this problem
 */

/*
 * 2. Implement
 */
#include <iostream>
using namespace std;

// places all smaller to the left of the pivot and all greater elements to right of the pivot
int partition(int arr[], int low, int high) {

    // choosing the pivot
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot ) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high){

        // partitioning index
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, N - 1);
    cout << "Sorted Array: "<< endl;
    for (int i = 0; i < N; i ++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
 * 3. Analysis
 *
 * T(n) = Divide + Conquer + Combine
 *      = n - 1 + T(left) + T(right) + 0
 *
 *      = n - 1 + T(n-1) + T(1)     (worst case)
 *      = n - 1 + T(n-1)
 *      = T(n-2) + n - 2 + n - 1
 *      ...
 *      = T(1) + 1 + 2 + 3 + .. + n - 1
 *      = T(1) + n(n-1)/2
 *      <= O(n^2)
 *
 *      or
 *
 *      = n - 1 + T(n/2) + T(n/2)   (best case)
 *      <= 2T(n/2)
 *      = 2^kT(n/2^k) + kn
 *      = nT(n/n) + nlogn
 *      = nlogn
 *      <=O(nlogn)
 *
 */
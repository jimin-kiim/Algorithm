//
// Created by 김지민 on 2023/04/28.
//

/*
 * merge sort
 *
 * Design Approach: Divide & Conquer
 *      Step 1. Divide the given array into more than 2 sub arrays
 *      Step 2. Conquer(Solve) each subarray
 *      Step 3. Combine the sub solutions
 */

/*
 * 2. Implement
 */
#include <iostream>
using namespace std;

// merge two subarrays of array[]
void merge(int array[], int const left, int const mid, int const right) {

    // size of the subarrays
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // temp arrays
    auto *leftArray = new int[subArrayOne],
    *rightArray = new int[subArrayTwo];

    // copying arrays to temp arrays
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    // intial index of subarrays and merged array
    auto indexOfSubArrayOne = 0,
    indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // merge the temp arrays back into array
    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // copying the remaining elements of left[]
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // copying the remaining elements of right[]
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}


void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Utility Function
void printArray(int A[], int size) {
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver Code
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size -1);

    cout << "\n Sorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

/*
 * 3. Analysis
 *
 * T(n) = Divide + Conquer + Combine
 *      = 0 + solve Left + solve Right + Combine
 *      = 0 + T(n/2) + T(n/2) + Combine
 *      = 2*T(n/2) + n/2 + n/2 - 1
 *      = 2*T(n/2) + n - 1
 *      <= 2*T(n/2) + n
 *      = 2(2T(n/4) + n/2) + n = 4T(n/4) + 2n
 *      = 8T(n/8) + 3n
 *      ...
 *      = 2^kT(n/2^k) + kn
 *      = nT(n/n) + nlogn  (suppose n = 2^k)
 *      = nT(1) + nlogn
 *      = nlogn
 *      <= O(nlogn)
 *
 */
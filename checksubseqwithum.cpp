#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int ind, int s, int sum, int arr[], int n) {
    if (ind == n) {
        return s == sum;
    }

    // Pick the current element
    s += arr[ind];
    if (isSubsetSum(ind + 1, s, sum, arr, n)) return true;

    // Backtrack and try without picking
    s -= arr[ind];
    if (isSubsetSum(ind + 1, s, sum, arr, n)) return true;

    return false;
}

int main() {
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    if (isSubsetSum(0, 0, sum, arr, n)) {
        cout << "Yes, a subsequence with sum " << sum << " exists." << endl;
    } else {
        cout << "No, such subsequence exists." << endl;
    }

    return 0;
}

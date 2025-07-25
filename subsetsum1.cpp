#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void func(int ind, int sum, vector<int> &arr, int N, vector<int> &sumSubset) {
        if (ind == N) {
            sumSubset.push_back(sum);
            return;
        }

        // Pick the element
        func(ind + 1, sum + arr[ind], arr, N, sumSubset);

        // Do not pick the element
        func(ind + 1, sum, arr, N, sumSubset);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> sumSubset;
        func(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    int N = arr.size();

    vector<int> result = sol.subsetSums(arr, N);

    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

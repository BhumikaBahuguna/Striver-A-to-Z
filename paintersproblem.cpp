#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int>& boards, int maxLoad) {
    int painters = 1, currLoad = 0;
    for (int len : boards) {
        if (currLoad + len <= maxLoad) {
            currLoad += len;
        } else {
            painters++;
            currLoad = len;
        }
    }
    return painters;
}

int paintersPartition(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        int requiredPainters = countPainters(boards, mid);

        if (requiredPainters <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> boards(n);
    for (int i = 0; i < n; i++) {
        cin >> boards[i];
    }
    
    int result = paintersPartition(boards, k);
    cout << result << endl;
    
    return 0;
}
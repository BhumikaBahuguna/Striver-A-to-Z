#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int n1, int n2, int k) {
    // Ensure 'a' is the smaller array
    if (n1 > n2) return kthElement(b, a, n2, n1, k);

    int low = max(0, k - n2), high = min(k, n1);
    int left = k;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0; // fallback
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    int k = 5;

    cout << "The " << k << "-th smallest element is: "
         << kthElement(a, b, a.size(), b.size(), k) << endl;

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
 double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
    int n2 = b.size();

    // Always binary search on the smaller array
    if (n1 > n2) return findMedianSortedArrays(b, a);

    int low = 0, high = n1;
    int total = n1 + n2;
    int half = (total + 1) / 2;

    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = half - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1) {
            if (total % 2 == 1)
                return max(l1, l2);
            else
                return (max(l1, l2) + min(r1, r2)) / 2.0;
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }

    return 0.0; // unreachable
}
int main(){
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> a(n1), b(n2);
    for(int i = 0; i < n1; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n2; i++) {
        cin >> b[i];
    }
    double median = findMedianSortedArrays(a, b);
    cout << fixed << setprecision(6) << median << endl;
    return 0;
}
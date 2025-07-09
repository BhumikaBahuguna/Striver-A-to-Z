#include <bits/stdc++.h>
using namespace std;

int noofgasstations(long double dist, vector<int>& arr) {
    int c = 0;
    for (int i = 1; i < arr.size(); i++) {
        long double gap = arr[i] - arr[i - 1];
        int noInBetween = gap / dist;
        // Only reduce count if the gap is perfectly divisible
        if (fabs(gap - (noInBetween * dist)) < 1e-9) {
            noInBetween--;
        }
        c += noInBetween;
    }
    return c;
}

long double minimisemaxdistance(vector<int>& arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = (low + high) / 2.0;
        int noofgas = noofgasstations(mid, arr);
        if (noofgas <= k) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    long double result = minimisemaxdistance(arr, k);
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}

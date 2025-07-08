#include<bits/stdc++.h>
using namespace std;
    int countOccurrences(vector<int>& nums, int target) {
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        return end - start;
    }
int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int count = countOccurrences(nums, target);
    cout << count << endl;
    return 0;
}
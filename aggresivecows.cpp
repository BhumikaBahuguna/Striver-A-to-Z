#include<bits/stdc++.h>
using namespace std;
bool canplace(vector<int>&s,int dist,int cow){
    int cntcows=1,last=s[0];
    for(int i=0;i<s.size();i++){
        if(s[i]-last>=dist){
            cntcows++;
            last=s[i];
        }
        if(cntcows>=cow) return true;
    }
    return false;
}
int aggcows(vector<int>&s,int k){
    sort(s.begin(),s.end());
    int n=s.size();
    int low=1,high=s[n-1]-s[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canplace(s,mid,k)==true){
            low=mid+1; // Try for a larger distance
        } else {
            high=mid-1; // Try for a smaller distance
        }
    }
    return high;
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int result = aggcows(s, k);
    cout << result << endl;
    return 0;
}
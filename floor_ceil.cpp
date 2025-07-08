#include<bits/stdc++.h>
using namespace std;
int floor(vector<int>&a,int n,int x){
    int low=0,high=n-1;
    int ans=-1; // Initialize to -1 to indicate no floor found
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]<=x){
            ans=mid; // Update ans to the current mid
            low=mid+1; // Move to the right side
        }else{
            high=mid-1; // Move to the left side
        }
    }
    return ans;
}
int ceil(vector<int>&a,int n,int x){
    int low=0,high=n-1;
    int ans=-1; // Initialize to -1 to indicate no ceil found
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>=x){
            ans=mid; // Update ans to the current mid
            high=mid-1; // Move to the left side
        }else{
            low=mid+1; // Move to the right side
        }
    }
    return ans;
}
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int floorIndex = floor(a, n, x);
    int ceilIndex = ceil(a, n, x);
    cout << "Floor: " << a[floorIndex] << " at index " << floorIndex << endl;
    cout << "Ceil: " << a[ceilIndex] << " at index " << ceilIndex << endl;
    return 0;
}
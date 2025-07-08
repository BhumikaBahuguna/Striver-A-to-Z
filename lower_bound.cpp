#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>&a,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
        low=mid+1;
        }
    }
    return ans;
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=lowerBound(a,n,x);
    cout<<ans<<endl;
    return 0;
}
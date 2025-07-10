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
int maxonesrow(vector<vector<int>>&matrix,int n,int m){
    int maxCount = 0;
    int rowIndex = -1;
    for (int i = 0; i < n; i++) {
        int countones=m-lowerBound(matrix[i], m, 1);
        if (countones > maxCount) {
            maxCount = countones;
            rowIndex = i;
        }
    }
    return rowIndex;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int result = maxonesrow(matrix, n, m);
    cout << "Row with maximum number of 1s is: " << result << endl;
}
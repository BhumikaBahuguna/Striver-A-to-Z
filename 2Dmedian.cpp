#include<bits/stdc++.h>
using namespace std;
using namespace std;
int upperBound(vector<int>&a,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>x){
            ans=mid;
            high=mid-1;
        }else{
        low=mid+1;
        }
    }
    return ans;
}
int countsmallequal(vector<vector<int>>&mat,int n,int m,int x){
    int count=0;
    for(int i=0;i<n;i++){
        count+=upperBound(mat[i],m,x);
    }
    return count;
}
int median(vector<vector<int>>&mat){
    int low=INT_MAX;
    int high=INT_MIN;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }
    int req=(n*m)/2;
    while(low<=high){
        int mid=(low+high)/2;
        int count=countsmallequal(mat,n,m,mid);
        if(count<=req){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}
    int main(){
        int rows, cols;
        cin >> rows >> cols;
        vector<vector<int>> mat(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
        int result = median(mat);
        cout << "The median is: " << result << endl;
        return 0;
    }
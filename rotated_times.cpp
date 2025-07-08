#include<bits/stdc++.h>
using namespace std;
int count_rotations(vector<int>& arr) {
        int l=0,h=arr.size()-1;
        int ans=INT_MAX;
        int index=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(arr[l]<=arr[h]){
                if(arr[l]<ans){
                    index=l;
                    ans=arr[l];
                }
                break;
            }
            if(arr[l]<=arr[m]){
                if(arr[l]<ans){
                    index=l;
                    ans=arr[l];
                }
                l=m+1;
            }else{
                h=m-1;
                if(arr[m]<ans){
                    index=m;
                    ans=arr[m];
                }
            }
        }
        return index;
    }
    int main(){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int rotations = count_rotations(arr);
        cout << "number of rotations : "<< rotations <<endl;
        return 0;
    }
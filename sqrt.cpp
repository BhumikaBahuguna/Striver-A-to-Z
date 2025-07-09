#include<bits/stdc++.h>
using namespace std;
int sqrt(int n){
    int low=1,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        long long val=(mid*mid);
        if(val<=n){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return high;
}
int main(){
    int n;
    cin >> n;
    int result = sqrt(n);
    cout << "Square root of " << n << " is: " << result << endl;
    return 0;
}
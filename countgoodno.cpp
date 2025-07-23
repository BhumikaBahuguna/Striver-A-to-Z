#include<bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
long long mypow(long long x,long long n){
    if(n==0) return 1;
    long long temp=pow(x,n/2);
    if(n%2==0) return (temp*temp)%MOD;
    else return ((x%MOD) *((temp*temp)%MOD))%MOD;
}
int countgoodno(long long n){
    long long even=(n+1)/2;
    long long odd=n/2;
    long long first=mypow(5,even)%MOD;
    long long second=mypow(4,odd)%MOD;
    return (int)((first*second)%MOD);
}
int main(){
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;
    int result = countgoodno(n);
    cout << "The count of good numbers is: " << result << endl;
    return 0;
}
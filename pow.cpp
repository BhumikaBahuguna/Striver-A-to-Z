#include<bits/stdc++.h>
using namespace std;
double mypow(double x,int n){
    double ans=1.0;
    long long nn=n;
    if(nn<0) nn=-1*nn;
    while(nn){
        if(nn%2){
            ans=ans*x;
            nn=nn-1;
        }else{
            x=x*x;
            nn=nn/2;
        }
    }
    if(n<0) ans=(double)(1.0)/(double)(ans);
    return ans;
}
int main(){
    double x;
    int n;
    cout << "Enter base (x): ";
    cin >> x;
    cout << "Enter exponent (n): ";
    cin >> n;
    double result = mypow(x, n);
    cout << "Result of " << x << "^" << n << " is: " << result << endl;
    return 0;
}
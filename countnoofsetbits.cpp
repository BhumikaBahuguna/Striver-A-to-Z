#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    int cnt=0;
    while(n!=0){
        n=n & (n-1); // This operation reduces the number of set bits by 1
        cnt++; // Increment count for each set bit found
    }
    cout << "Number of set bits: " << cnt << endl;
    return 0;
}
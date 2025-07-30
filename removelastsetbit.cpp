#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    // Remove the last set bit from the number
    n = n & (n - 1);
    cout << "Number after removing the last set bit: " << n << endl;
    return 0;
}
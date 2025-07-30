#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,pos;
    cin >> n >> pos;
    // Check if the bit at position 'pos' is set (1) or not (0)
    if((n & (1 << pos))!=0) {
        cout << "Bit is set at position " << pos << endl;
    } else {
        cout << "Bit is not set at position " << pos << endl;
    }
    return 0;
}
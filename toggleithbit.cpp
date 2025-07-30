#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, pos;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Enter the position to toggle (0-indexed): ";
    cin >> pos;
    n= n ^ (1 << pos); // Toggle the bit at position 'pos'
    cout << "Number after toggling the bit at position " << pos << ": " << n << endl;
    return 0;
}
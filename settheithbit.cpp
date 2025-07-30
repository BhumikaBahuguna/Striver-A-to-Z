#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, pos;
    cout << "Enter an integer: ";
    cin >> n;
    cout << "Enter the position to set the bit: ";
    cin >> pos;
    // Set the bit at position 'pos' to 1
    n = n | (1 << pos);
    cout << "Number after setting the bit at position " << pos << ": " << n << endl;
    return 0;
}
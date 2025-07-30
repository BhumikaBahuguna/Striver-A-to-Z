#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,pos;
    cout << "Enter an integer: ";
    cin >> n;
    cout<<"enter position to clear :";
    cin>>pos;
    // clear the bit at position 'pos' to 0
    n = n & ~ (1 << pos);
    cout << "Number after clearing the bit at position " << pos << ": " << n << endl;
    return 0;
}
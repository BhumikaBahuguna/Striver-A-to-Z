#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout << "Enter two integers to swap: ";
    cin >> a >> b;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b; 
    cout << "After swapping: a = " << a << ", b = " << b << endl;
    return 0;
}
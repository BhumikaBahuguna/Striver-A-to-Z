#include<bits/stdc++.h>
using namespace std;
int binaryToDecimal(string x){
    int decimalValue = 0;
    int base = 1; // Initialize base value to 1, i.e., 2^0
    int length=x.length();
    for(int i=length-1; i>=0; i--) {
        if(x[i]== '1') {
            decimalValue += base;
        }
        base *= 2; // Increase base by power of 2
    }

    return decimalValue;
}
int main(){
    string binary;
    cout<<"Enter a binary number: ";
    cin>>binary;
    int decimal = binaryToDecimal(binary);
    cout<<"Decimal representation: "<<decimal<<endl;
    return 0;
}
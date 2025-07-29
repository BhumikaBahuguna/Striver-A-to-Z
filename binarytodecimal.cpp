#include<bits/stdc++.h>
using namespace std;
string convert2binary(int n){
    string res="";
    while(n!=0){
        if(n%2==1){
            res='1'+res;
        } else {
            res='0'+res;
        }
        n=n/2;
    }
    reverse(res.end(),res.begin());
    return res;
}
int main(){
    int n;
    cout<<"Enter a decimal number: ";
    cin>>n;
    string binary = convert2binary(n);
    cout<<"Binary representation: "<<binary<<endl;
    return 0;
}
   
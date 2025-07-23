#include<bits/stdc++.h>
using namespace std;
int length(char input[]){
    int len=0;
    for(int i=0;input[i]!='\0';i++){
        len++;
    }
    return len;
}
int stringtonumber(char input[],int last){
    if(last==0){
        return input[last]-'0';
    }
    int smallans=stringtonumber(input,last-1);
    int a=input[last]-'0';return smallans*10+a;
}
int stringtonumber(char input[]){
    int len=length(input);
    return stringtonumber(input,len-1);
}

int main(){
    char input[100];
    cout << "Enter a string representing a number: ";
    cin >> input;
    int result = stringtonumber(input);
    cout << "The integer value is: " << result << endl;
    return 0;
}
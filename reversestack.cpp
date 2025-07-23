#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int>&st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topele=st.top();
    st.pop();
    insertatbottom(st,val);
    st.push(topele);
}
void reversestack(stack<int>&st){
    if(st.empty()) return;
    int topele=st.top();
    st.pop();
    reversestack(st);
    insertatbottom(st,topele);
}
void printstack(stack<int>st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"original stack :";
    printstack(st);
    reversestack(st);
    cout<<"reversed stack:";
    printstack(st);
    return 0;
}
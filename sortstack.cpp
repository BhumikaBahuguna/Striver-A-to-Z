#include<bits/stdc++.h>
using namespace std;
void sortedinsert(stack<int>&st,int val){
    if(st.empty() || st.top()<val){
        st.push(val);
        return;
    }
    int topele=st.top();
    st.pop();
    sortedinsert(st,val);
    st.push(topele);
}
void sortstack(stack<int>&st){
    if(st.empty()) return;
    int topele=st.top();
    st.pop();
    sortstack(st);
    sortedinsert(st,topele);
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
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    cout<<"original stack :";
    printstack(st);
    sortstack(st);
    cout<<"sorted stack:";
    printstack(st);
    return 0;
}
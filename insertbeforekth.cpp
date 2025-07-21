#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node* back;
    public:
    node(int data1,node* next1,node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* converttodll(vector<int>&arr){
    node* head=new node(arr[0]);
    node* prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
node* insertbeforhead(node * head,int val){
    node * newhead=new node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}
node * insertbeforekth(node*head,int k, int val){
    if(k==1){
        return insertbeforhead(head,val);
    }
    node * temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    node* prev=temp->back;
    node* newnode=new node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}
    int main(){
    vector<int>arr={12,5,8,7};
    node*head=converttodll(arr);
    head=insertbeforekth(head, 2, 10); 
    print(head);
    return 0;
}
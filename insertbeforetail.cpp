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
node * insertbeforetail(node*head,int val){
    if(head->next==NULL){
        return insertbeforhead(head,val);
    }
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node* prev=tail->back;
    node* newnode=new node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;
}
    int main(){
    vector<int>arr={12,5,8,7};
    node*head=converttodll(arr);
    head=insertbeforetail(head,10);
    print(head);
    return 0;
}
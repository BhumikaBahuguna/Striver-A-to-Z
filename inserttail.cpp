#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * next;
    public:
    node(int data1,node* next1){
        data=data1;
        next=next1;
    }
    public:
    node(int data1){
        data=data1;
        next=nullptr;
    }

};
node* convertarr2ll(vector<int>&arr){
    node*head=new node(arr[0]);
    node* mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* inserttail(node*head,int val){
    if(head==NULL) return new node(val);
    node * temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* newnode=new node(val);
    temp->next=newnode;
    return head;
}
int main(){
    vector<int>arr={12,5,8,7};
    node*head=convertarr2ll(arr);
    head=inserttail(head,100);
    print(head);
    return 0;
}
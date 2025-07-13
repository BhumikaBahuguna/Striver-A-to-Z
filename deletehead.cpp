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
node* deletehead(node* head){
    if(head==NULL ||head->next==NULL){
        return NULL;
    }
    node * prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

int main(){
    vector<int>arr={12,5,8,7};
    node*head=converttodll(arr);
    head=deletehead(head);
    print(head);
    return 0;
}
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
node * removeshead(node* head){
    if(head==NULL) return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

int main(){
    vector<int>arr={12,5,8,7};
    node*head=convertarr2ll(arr);
    cout<<"Original Linked List: ";
    print(head);
    head = removeshead(head);
    cout<<"Linked List after removing head: ";
    print(head);
    return 0;
}
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
node* insertbeforevalue(node*head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new node(el,head);
    }
    node * temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            node *x=new node(el,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int>arr={12,5,8,7};
    node*head=convertarr2ll(arr);
    head=insertbeforevalue(head,100,5);
    print(head);
    return 0;
}
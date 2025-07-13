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
node* insertposition(node*head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new node(el);
        }else{
            return head;
        }
    }
    if(k==1){
        return new node(el,head);
    }
    int cnt=0;
    node * temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
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
    head=insertposition(head,100,3);
    print(head);
    return 0;
}
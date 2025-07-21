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
int findlength(node * slow,node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}
int lengthofloop(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return findlength(slow,fast);
        }
    }
    return 0;
}
int main(){
    vector<int>arr={1,2,15,4,13,6,7,8,9,15};
    node*head=convertarr2ll(arr);
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head->next->next->next;
    int length=lengthofloop(head);
    cout<<"Length of loop: "<<length<<endl;
    return 0;
}
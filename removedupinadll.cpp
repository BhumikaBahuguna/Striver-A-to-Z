#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* back;

    node(int data1, node* next1, node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* convertToDLL(vector<int>& arr) {
    node* head = new node(arr[0]);
    node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

node* removeDuplicates(node* head) {
    node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        node* nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data) {
            node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if (nextNode != NULL) nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 3, 4, 5, 5, 6};
    // Assuming sorted input as required by removeDuplicates logic
    node* head = convertToDLL(arr);

    cout << "Original List:\n";
    print(head);

    head = removeDuplicates(head);

    cout << "\nList After Removing Duplicates:\n";
    print(head);

    return 0;
}

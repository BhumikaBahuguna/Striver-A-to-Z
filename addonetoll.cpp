#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Helper function to recursively add one
int addHelper(Node* temp) {
    if (temp == NULL) {
        return 1;
    }

    int carry = addHelper(temp->next);
    temp->data += carry;

    if (temp->data < 10) {
        return 0;
    }

    temp->data = 0;
    return 1;
}

// Function to add one to the linked list number
Node* addOne(Node* head) {
    int carry = addHelper(head);

    if (carry == 1) {
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

// Utility to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

// Utility to create linked list from vector
Node* createList(vector<int> digits) {
    Node* head = new Node(digits[0]);
    Node* temp = head;

    for (int i = 1; i < digits.size(); i++) {
        temp->next = new Node(digits[i]);
        temp = temp->next;
    }

    return head;
}

int main() {
    // Example: 1 -> 9 -> 9 (represents 199)
    vector<int> digits = {1, 9, 9};
    Node* head = createList(digits);

    cout << "Original number: ";
    printList(head);

    head = addOne(head);

    cout << "After adding 1: ";
    printList(head);

    return 0;
}

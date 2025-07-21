#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to sort the linked list
Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    // Dummy nodes for 0s, 1s, and 2s lists
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    // Distribute nodes into 0s, 1s, and 2s lists
    while (temp) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Connect the three lists
    zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
    one->next = twoHead->next;
    two->next = nullptr;

    // Head of the new sorted list
    Node* newHead = zeroHead->next;

    // Delete dummy nodes to avoid memory leaks
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert node at end
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Main driver code
int main() {
    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 2);

    cout << "Original List: ";
    printList(head);

    Node* sortedHead = sortList(head);

    cout << "Sorted List: ";
    printList(sortedHead);

    return 0;
}

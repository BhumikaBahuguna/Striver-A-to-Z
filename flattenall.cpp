#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->child = nullptr;
    }
};

// Merge two sorted linked lists using child pointer
Node* merge(Node* list1, Node* list2) {
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        } else {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
    }

    if (list1) res->child = list1;
    else res->child = list2;

    return dummyNode->child;
}

// Flatten the multi-level linked list
Node* flattenLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursively flatten the list on right
    head->next = flattenLinkedList(head->next);

    // Merge current list with the flattened right list
    head = merge(head, head->next);

    return head;
}

// Helper function to print the flattened list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}
int main() {
    // Example: Creating 3 vertical sorted lists connected horizontally

    // First vertical list: 5 -> 7 -> 8 -> 30
    Node* head = new Node(5);
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    // Second vertical list: 10 -> 20
    Node* second = new Node(10);
    second->child = new Node(20);
    head->next = second;

    // Third vertical list: 19 -> 22 -> 50
    Node* third = new Node(19);
    third->child = new Node(22);
    third->child->child = new Node(50);
    second->next = third;

    // Fourth vertical list: 28 -> 35 -> 40 -> 45
    Node* fourth = new Node(28);
    fourth->child = new Node(35);
    fourth->child->child = new Node(40);
    fourth->child->child->child = new Node(45);
    third->next = fourth;

    // Flatten and print
    Node* result = flattenLinkedList(head);
    printList(result);

    return 0;
}
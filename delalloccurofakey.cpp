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

node* deleteAllOccurrences(node* head, int k) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == k) {
            // If this is the head of the LL
            if (temp == head) {
                head = temp->next;
            }

            node* nextNode = temp->next;
            node* prevNode = temp->back;
            if (nextNode != NULL) nextNode->back = prevNode;
            if (prevNode != NULL) prevNode->next = nextNode;

            free(temp);
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 2, 5};
    node* head = convertToDLL(arr);

    cout << "Original list: ";
    print(head);

    int k = 2;
    head = deleteAllOccurrences(head, k);

    cout << "List after deleting all occurrences of " << k << ": ";
    print(head);

    return 0;
}

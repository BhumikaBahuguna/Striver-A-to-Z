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
node* findTail(node* head) {
    node* tail = head;
    while (tail->next != NULL) tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(node* head, int k) {
    vector<pair<int, int>> ans;
    if (head == NULL) return ans;

    node* left = head;
    node* right = findTail(head); // O(N)

    while (left->data < right->data) {
        int sum = left->data + right->data;
        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->back;
        } else if (sum < k) {
            left = left->next;
        } else {
            right = right->back;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3,4,6};
    node* head = convertToDLL(arr);

    cout << "Original List:\n";
    print(head);
    int k = 7;
    vector<pair<int, int>> pairs = findPairs(head, k);
    cout << "\nPairs with sum " << k << ":\n";
    for (auto p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}

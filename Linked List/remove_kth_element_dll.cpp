#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;

    Node(int value) {
        data = value;
        next = nullptr;
        back = nullptr;
    }
    Node(int data, Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

// Build DLL from vector
Node* buildList(vector<int> arr) {
    if(arr.empty()) return nullptr;

    Node* first_node = new Node(arr[0]);
    Node* prev = first_node;

    for(int i=1; i<arr.size(); i++) {
        Node* nn = new Node(arr[i], nullptr, prev);
        prev->next = nn;
        prev = nn;
    }
    return first_node;
}

// Print DLL forward
void print(Node* head) {
    while(head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Delete first node
Node* deleteFirst(Node* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) { // only one node
        delete head;
        return nullptr;
    }
    Node* newHead = head->next;
    newHead->back = nullptr;
    head->next = nullptr;
    delete head;
    return newHead;
}

// Delete last node
Node* deleteLast(Node* head) {
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) { // only one node
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

// Delete k-th node (1-indexed)
Node* deleteKth(Node* head, int k) {
    if(head == nullptr) return nullptr;

    Node* temp = head;
    int count = 1;

    while(temp != nullptr && count < k) {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr) return head; // k > length

    Node* prev = temp->back;
    Node* next = temp->next;

    // Case 1: only one node
    if(prev == nullptr && next == nullptr) {
        delete temp;
        return nullptr;
    }
    // Case 2: deleting head
    else if(prev == nullptr) {
        return deleteFirst(head);
    }
    // Case 3: deleting tail
    else if(next == nullptr) {
        return deleteLast(head);
    }
    // Case 4: middle node
    else {
        prev->next = next;
        next->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
}

int main() {
    vector<int> num = {1,2,3,4,5};
    Node* head = buildList(num);

    cout << "Original list: ";
    print(head);

    head = deleteFirst(head);
    cout << "After deleting first: ";
    print(head);

    head = deleteLast(head);
    cout << "After deleting last: ";
    print(head);

    int k;
    cout << "Enter k to delete: ";
    cin >> k;
    head = deleteKth(head, k);
    cout << "After deleting " << k << "-th node: ";
    print(head);

    return 0;
}

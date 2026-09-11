#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* back;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->back = NULL;
    }

    Node(int val, Node* next, Node* back) {
        this->val = val;
        this->next = next;
        this->back = back;
    }
};

Node* link_list_create(vector<int> arr) {
    if (arr.empty()) return NULL;

    Node* hd = new Node(arr[0]);
    Node* prev = hd;

    for (int i = 1; i < arr.size(); i++) {
        Node* nn = new Node(arr[i], NULL, prev);
        prev->next = nn;
        prev = nn;
    }

    return hd;
}

void print(Node* hd) {
    Node* temp = hd;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* Delete_node(Node* hd, Node* del) {
    if (del == NULL) return hd;

    // If deleting head
    if (del == hd) {
        Node* newHead = hd->next;
        if (newHead != NULL) newHead->back = NULL;
        delete hd;
        return newHead;
    }

    Node* prev = del->back;
    Node* front = del->next;

    if (prev != NULL) prev->next = front;
    if (front != NULL) front->back = prev;

    delete del;
    return hd;
}

int main() {
    vector<int> num = {1, 2, 3, 4, 5};
    Node* head = link_list_create(num);

    print(head);

    // Delete the 3rd node (value 3)
    head = Delete_node(head, head->next->next);

    print(head);

    return 0;
}

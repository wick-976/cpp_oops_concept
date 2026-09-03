#include <bits/stdc++.h>
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

class Linked_list {
public:
    Node* head;
    Node* tail;
    int size;

    Linked_list() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Insert at first position
    void insert_position(int value) {

        Node* nn = new Node(value);

        nn->next = head;
        head = nn;

        if (tail == nullptr) {
            tail = head;
        }

        size++;
    }

    // Insert at a particular position
    void insert_position(int position, int val) {

        Node* temp2 = head;

        for (int i = 1; i < position - 1; i++) {
            temp2 = temp2->next;
        }

        Node* new_now = new Node(val);

        new_now->next = temp2->next;

        temp2->next = new_now;

        size++;
    }

    // Display
    void display() {

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Linked_list list;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        int value;
        cin >> value;

        list.insert_position(value);
    }

    list.display();

    int position;
    int inserted_value;

    cin >> position >> inserted_value;

    list.insert_position(position, inserted_value);

    list.display();

    return 0;
}
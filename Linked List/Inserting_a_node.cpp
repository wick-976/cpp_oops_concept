//in first function we try to insert a new node at the startingn 
//in second function we insert a node at last 
//in third we try to insert a new node before the last node
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
void insertion_before_head (Node* hd,int value)
{
    Node* nn=new Node(7,hd,NULL);

    hd->back=nn;

    print(nn);

}
void insert_at_end(Node* hd,int val)
{
    Node* temp=hd;
    Node* nn=new Node(val,NULL,temp);

    while(temp->next != NULL)
    {
        temp=temp->next;
    }

    temp->next=nn;
    print(hd);
}

void insert_before_end(Node* hd,int val)
{
    Node* i=hd;

    while(i->next != NULL)
    {
        i=i->next;
    }
    Node* prev=i->back;

    Node* nn= new Node(val,i,prev);   
    prev->next=nn;
    i->back=nn;

    print(hd);

}
void insert_before_kth_element(Node* hd,int val,int k)
{
    Node* i=hd;
    int count=0;

    while(i != NULL)
    {
        count++;
        if(count==k)
        {
            break;
        }
        i=i->next;
    }
    Node* prev=i->back;
    Node* nn=new Node(val,i,prev);

    i->back=nn;
    prev->next=nn;

    print(hd);
}
int main() {
    vector<int> num = {1, 2, 3, 4, 5};
    Node* head = link_list_create(num);

    print(head);

    // Delete the 3rd node (value 3)
    head = Delete_node(head, head->next->next);

    print(head);

    cout<<"Enter the value you need to insert and kth element below";
    int value,k;
    cin>>value>>k;
    //insertion_before_head(head,value);

    //insert_at_end(head,value);

    //insert_before_end(head,value);

    insert_before_kth_element(head,value,k);


    return 0;
}

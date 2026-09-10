//here we try to remove the First node of the doubly linked list 

#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* back;

Node(int value)
{
    data=value;
    next=nullptr;
    back=nullptr;
}
Node(int data,Node* next,Node* back)
{
    this->data=data;
    this->next=next;
    this->back=back;
}
};

Node* result(vector<int> arr)
{
    Node* first_node=new Node(arr[0]);
    Node* prev=first_node;

    for(int i=1;i<arr.size();i++)
    {
        Node* nn=new Node(arr[i],nullptr,prev);
        prev->next=nn;
        prev=nn;
    }

    return first_node;
}

void print(Node* head_value)
{
    while(head_value!=nullptr)
    {
        cout<<head_value->data<<" ";
        head_value=head_value->next;
    }
}
void Delete_first_node(Node* hd)
    {
        if(hd==NULL || hd->next==NULL) return;
        Node* head=hd->next;
        head->back=nullptr;
        hd->next=nullptr;
        delete hd;
        cout<<"\n";
        print(head);
    }

int main()
{
    vector<int>num={1,2,3,4,5};

    Node* head=result(num);

    print(head);
    
    Delete_first_node(head);
}
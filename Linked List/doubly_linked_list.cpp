//this is double linked list 
//the diffence is in single linked list we have only twp value like 
//data and next pointer where in doubly linked list we have another extra 
//varaible called back which store the previois address Node

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

    return prev;
}

void print(Node* head_value)
{
    while(head_value!=nullptr)
    {
        cout<<head_value->data<<" ";
        head_value=head_value->back;
    }
}

int main()
{
    vector<int>num={1,2,3,4,5};

    Node* head=result(num);

    print(head);
    

}
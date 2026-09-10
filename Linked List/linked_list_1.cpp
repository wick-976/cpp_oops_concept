#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data)
        {
            this->data=data;
            this->next=nullptr;
        }


};

int main()
{
    Node* header=new Node(10);

    header->next=new Node(20);

    header->next->next=new Node(30);

    header->next->next->next=new Node(40);


    Node* temp = header;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

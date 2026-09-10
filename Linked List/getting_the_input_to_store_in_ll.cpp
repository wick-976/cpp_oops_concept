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
    Node* head=nullptr;
    Node* tail=nullptr;


    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        Node* new_node_creation=new Node(value);

        if(head==nullptr)
        {
            head=new_node_creation;
            tail=new_node_creation;
        }

        else
        {
            tail->next=new_node_creation;
            tail=new_node_creation;
        }

       

        
    }
     Node* temp=head;
    while(temp != nullptr)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    
}


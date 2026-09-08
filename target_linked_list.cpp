#include <bits/stdc++.h>
using namespace std;

class finding_target{
    public:
    int data;
    finding_target* next;


    finding_target(int data)
    {   
        this->data=data;
        this->next=nullptr;
    }
    
    
};
int main()

{
    int n;
    cin>>n;

    finding_target* header=nullptr;
    finding_target* tail=nullptr;

    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        finding_target* nn= new finding_target(value);
        
        if(header==nullptr)
        {
            header=nn;
            tail=nn;
        }
        else{
            tail->next=nn;
            tail=nn;
        }
    }

    finding_target* temp=header;

    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    int targ;
    cin>>targ;

    finding_target* head_check=header;
    bool found=false;

    while(head_check != nullptr)
    {
        if(head_check->data == targ)
        {
            found=true;
            break;
        }
        head_check=head_check->next;
        
        

    }

   if(found){
       cout<<"true";
   }
    else
   {
       cout<<"false";
   }
}
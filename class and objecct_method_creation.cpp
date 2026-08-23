#include <bits/stdc++.h>
using namespace std;

//in this method we create a method inside the Class itself 
class Student{
    public:
        string name;
        int roll_no;
        string class_sec;

        void display()
        {   
            cout<<name<<"\n"<<roll_no<<"\n"<< class_sec;  
        }


};
int main()
{   
    Student tharan;

    tharan.name="Tharan";
    tharan.roll_no=622;
    tharan.class_sec="ECE D";

    tharan.display();// while calling the funciton we have to call it with the instance name(object)
    //beacause we created fucntipon inisde that class for that class we craeted the instance called 
    //Tharan so that we have to access the that function with that instance 
}

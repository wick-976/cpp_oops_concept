#include <bits/stdc++.h>
using namespace std;

/*here we are writing the method outside the class so we have to mention the method name 
inside the class refer the 16th line*/

class aanime{
    public:
        string name;
        string genere;
        int rating;

        void display(string);
};

void aanime::display(string name)
{
    cout<<name<<"\n"<<genere<<"\n"<<rating;
}
int main()
{
    aanime aot;
    aot.genere="Sci_fi and Action";
    aot.rating=9.2;

    aot.display("Demon Slayer");

}
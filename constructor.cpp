#include <bits/stdc++.h>
using namespace std;

class Movie
{
    public:
        string name;
        string cast;
        int imdb;

    Movie(string name,string cast)
    {
        name=name;
        cast=cast;

        cout<<name<<"\n"<<cast;
    }
};

int main()
{
    Movie yourname("Enthiran","Rajini");

    yourname.name="Yourname";
    yourname.cast="unknown";
    yourname.imdb=9.3;

    cout<<yourname.name;

    Movie cop=yourname;

    cout<<cop.name;

}
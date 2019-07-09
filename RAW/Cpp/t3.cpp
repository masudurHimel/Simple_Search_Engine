#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream f("sample.csv");

    if(!f.is_open())
    {
        cout<<"Error -- File doesn't exist"<<endl;
        return 0;
    }

    string a,b,c,d,e;
    string word;

    f>>word;
    int count = 0;
    while(f.good())
    {
        if(count == 0)
        {
            f>>word;
            count++;
            continue;
        }

        cout<<word <<endl;
        f>>word;


    }
}


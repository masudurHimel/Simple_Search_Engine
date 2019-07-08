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
    int count = 0;
    getline(f,a,'\n');
    while(f.good())
    {
        if(count==0)
        {
            count++;
            continue;
        }
        getline(f,a,'\n');

        for(int i=0; i<a.size(); i++)
        {
            if(a[i] == ',')
            {
                if(a[i+1] == ' ')
                {
                    a[i] = '-';
                    a[i+1]= '-';
                }
            }
        }
        cout<<count<<endl;
        cout <<a<<endl;
        cout<<"-------------"<<endl;
        count++;
    }
}

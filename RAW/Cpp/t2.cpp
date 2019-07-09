#include<bits/stdc++.h>

using namespace std;

string stringModifier(string x)
{
    int flag = 0;

    for(int i =0; i<x.size(); i++)
    {
        if(x[i] == ',')
        {
             if(x[i+1] == ' ')
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1)
    {
        for(int i=0; i<x.size(); i++)
        {
            if(x[i] == ',')
            {
                if(x[i+1] == ' ')
                {
                    x[i] = '-';
                    x[i+1]= '-';
                }
            }
        }
        x = '"'+x+'"';
    }



    return x;

}


int main()
{
    string x,y;

    getline(cin,x);
    x = stringModifier(x);
    cout <<x;
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    fstream fin;

    // For opening the data file
    fin.open("sample.csv", ios::in);

    //For industry name filter
    string industryName;

    //for the csv file analysis
    vector<string> row;
    string line, word, temp,dummy;


    int count = 0;


    while (fin.good())
    {


        //to ignore the header
        if(count == 0)
        {
            count++;
            continue;
        }
        row.clear();


        // read an entire row and
        // store it in a string variable 'line'

        getline(fin, line);

        //for data preprocessing
        for(int i =0; i<line.size(); i++)
        {
            if(line[i] == ',')
            {
                if(line[i+1] == ' ')
                {
                    line[i] = '-';
                    line[i+1]= '-';
                }
            }
        }

        // used for breaking words
        stringstream s(line);

        cout<<count<<endl;

        while(getline(s,word,','))
        {
            //word contains each row values separated by the comma delimited
            row.push_back(word);
            cout<<word<<endl;

        }

        cout<<"----------------"<<endl;



        count++;
    }




}

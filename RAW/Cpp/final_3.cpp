#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fp("sample.csv");
    if(!fp.is_open())
    {
        cout<<"Error -- File not found !! "<<endl;
        cout<<"Exiting . . . . . "<<endl;
        return 0;
    }


    string industryName,level,dataSize,lineCode,value;
    int option;

    string row,word;
    vector<string> cols;
    int count = 0,flag = 0,id = 1,numberOfCols= 1;

    cout << "Industry Name" <<endl;
    cin >> industryName;



    while(fp.good() && numberOfCols <=18)
    {
        cols.clear();
        //to exclude the headers
        if(count==0)
        {
            count++;
            continue;
        }

        //for each row
        getline(fp,row,'\n');

        for(int i=0; i<row.size(); i++)
        {
            if(row[i] == ',')
            {
                if(row[i+1] == ' ')
                {
                    row[i] = '-';
                    row[i+1]= '-';
                }
            }
        }

        //here all the data are saved in cols vector
        //later will be used in searching

        stringstream s(row);
        while(getline(s,word,','))
        {
            cols.push_back(word);
        }

        if(cols[1] == industryName)
        {
            if(id == 0 )
            {
                cout <<endl << "---------------------------------------------"<<endl;
            }

            flag = 1;
            cout <<"Serial No.  : " <<id<<endl;
            cout <<"Description : " <<cols[0]<<endl;
            cout <<"Industry    : " <<cols[1]<<endl;
            cout <<"Level       : " <<cols[2] <<endl;
            cout <<"Size        : " <<cols[3] <<endl;
            cout <<"Line Code   : " <<cols[4] <<endl;
            cout <<"Value       : " <<cols[5]<<endl;
            id++;
            cout <<endl << "---------------------------------------------"<<endl;
        }



        numberOfCols++;
    }

    if(flag == 0)
    {
        cout <<endl<<"**No matching data found**" <<endl;
        return 0;
    }

}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    //file initialization
    ifstream fp("sample.csv");

    //for handling exceptions
    if(!fp.is_open())
    {
        cout<<"Error -- File not found !! "<<endl;
        cout<<"Exiting . . . . . "<<endl;
        return 0;
    }

    string row,word;
    vector<string> cols;
    string xTemp,yTemp;

    //for search criteria

    string industryName,level,dataSize,lineCode,value;
    int option;
    cout<<"Choose your option : "<<endl;
    cout<<"1.By Industry Name"<<endl;
    cout<<"2.By Level"<<endl;
    cout<<"3.By Line Code"<<endl;
    cout<<"4.By Value"<<endl;
    cin>>option;



    int count = 0,flag = 0,id = 1;
    //for reading the columns
    getline(fp,row,'\n');

    while(fp.good())
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

        //for separating the columns by the comma delimit

        stringstream s(row);
        while(getline(s,word,','))
        {
            cols.push_back(word);
        }

        //To match both uppercase and lowercase
        xTemp = cols[1];
        yTemp = industryName;

        transform(xTemp.begin(), xTemp.end(), xTemp.begin(), ::tolower);
        transform(yTemp.begin(), yTemp.end(), yTemp.begin(), ::tolower);

        //industry filter
        if(xTemp == yTemp)
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

        count++;
    }
    if(flag == 0)
    {
        cout <<endl<<"**No matching data found**" <<endl;
    }

}

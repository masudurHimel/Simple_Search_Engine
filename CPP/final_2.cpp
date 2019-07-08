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

    string industryName,level,dataSize,lineCode,value;
    int option;

    string row,word;
    vector<string> cols;
    int count = 0,flag = 0,id = 1;


    //user inputs
    fflush(stdin);
    cout<<"Choose your option : "<<endl;
    cout<<"1.By Industry Name"<<endl;
    cout<<"2.By Level"<<endl;
    cout<<"3.By Line Code"<<endl;
    cout<<"4.By Value"<<endl;
    cout<<"7.Exit"<<endl;
    cin>>option;
    fflush(stdin);

    cout<<endl;

    if(option == 1)
    {
        //For industry filter
        system("CLS");
        cout<<"Enter the name of the Industry"<<endl;
        getline(cin,industryName);
        cout << industryName<<endl;
        fflush(stdin);

    }



    else if(option == 7)
    {
        cout<<"Exiting . . . .!! "<<endl;
        return 0;
    }
    else
    {
        flag =1;
        cout<<"Invalid input. Try again . . . "<<endl;
        cout<<"Exiting . . . ."<<endl;
    }


    //preprocessing part
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

        //here all the data are saved in cols vector
        //later will be used in searching

        stringstream s(row);
        while(getline(s,word,','))
        {
            cols.push_back(word);
        }




        if(option == 1)
        {

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

        }



        if(flag == 0)
        {
            cout <<endl<<"**No matching data found**" <<endl;
            return 0;
        }

    }


}



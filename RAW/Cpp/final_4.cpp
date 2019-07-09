#include<bits/stdc++.h>

using namespace std;

void searchCsv(int option,string value);

int main()
{
    int option;
    string industryName,level,dataSize,lineCode,value;

    while(1)
    {
        cout<<"Choose your option : "<<endl;
        cout<<"1.By Industry Name"<<endl;
        cout<<"2.By Level"<<endl;
        cout<<"3.By Line Code"<<endl;
        cout<<"4.By Value"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<endl<<"Option ? :";
        cin>>option;

        if(option == 1)
        {
            system("CLS");
            cout <<endl<< "Enter the name of the Industry :" <<endl;
            cin >> industryName;
            system("CLS");
            searchCsv(1,industryName);
        }

        else if(option == 2){
            system("CLS");
            cout <<endl<< "Enter the value of the Level :" <<endl;
            cin >> level;
            system("CLS");
            searchCsv(2,level);
        }

        else if(option == 3){
            system("CLS");
            cout <<endl<< "Enter the Line Code" <<endl;
            cin >> lineCode;
            system("CLS");
            searchCsv(4,lineCode);
        }

        else if(option == 4){
            system("CLS");
            cout <<endl<< "Enter the Value" <<endl;
            cin >> lineCode;
            system("CLS");
            searchCsv(5,lineCode);
        }

        else if(option == 7)
        {
            cout<<endl<<"Exiting !! . . . . "<<endl;
            return 0;
        }

        else
        {
            cout<<endl<<"Invalid input Try again !! "<<endl<<endl<<endl;
        }
    }
}

void searchCsv(int option,string value)
{
    ifstream fp("sample.csv");
    if(!fp.is_open())
    {
        cout<<"Error -- File not found !! "<<endl;
        cout<<"Exiting . . . . . "<<endl;
        return;
    }


    string row,word;
    vector<string> cols;
    int count = 0,flag = 0,id = 1,numberOfCols= 1;
    char temp;


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

        if(cols[option] == value)
        {
            if(id == 1 )
            {
                cout<<"Result(s) : "<<endl<<endl;
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
        cout <<endl<<"**No matching data found**" <<endl<<endl<<endl;
    }

    else{
        cout << endl<< "Total Result(s) : "<<id-1<<endl;
    }

    cout<<endl<<endl;

    cout<<"Search Again ?? -> (y/n)"<<endl;
    cin >>temp;

    if(temp == 'y')
    {
        system("CLS");
    }
    else
    {
        cout << "Exiting . . . ."<<endl;
        exit(1);
    }

}

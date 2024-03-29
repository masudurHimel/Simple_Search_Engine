#include<bits/stdc++.h>

using namespace std;

void searchCsv(int option,string value);
string stringModifier(string x);
string sizeProcessing(string x);
int matchingCriteria(string cols,string value);

int main()
{
    int option;
    string industryName,level,dataSize,lineCode,value,sizeValue,description;

    while(1)
    {
        try
        {
            fflush(stdin);
            cout << "Searching On : Survey data set of New Zealand citizens"<<endl;
            cout << "Topic        : Changing nature of work"<<endl<<endl<<endl;

            cout<<"Choose your option : "<<endl;
            cout<<"1.By Industry Name"<<endl;
            cout<<"2.By Level"<<endl;
            cout<<"3.By Line Code"<<endl;
            cout<<"4.By Value"<<endl;
            cout<<"5.By Size"<<endl;
            cout<<"6.By Description"<<endl;
            cout<<"7.Exit"<<endl;
            cout<<endl<<"Option ? :";
            cin>>option;


            if(option == 1)
            {
                fflush(stdin);
                system("CLS");
                cout <<endl<< "Enter the name of the Industry :" <<endl;
                getline(cin,industryName);
                industryName = stringModifier(industryName);
                system("CLS");
                searchCsv(1,industryName);
            }

            else if(option == 2)
            {
                system("CLS");
                cout <<endl<< "Enter the value of the Level :" <<endl;
                cin >> level;
                system("CLS");
                searchCsv(2,level);
            }

            else if(option == 3)
            {
                system("CLS");
                cout <<endl<< "Enter the Line Code" <<endl;
                cin >> lineCode;
                system("CLS");
                searchCsv(4,lineCode);
            }

            else if(option == 4)
            {
                system("CLS");
                cout <<endl<< "Enter the Value" <<endl;
                cin >> lineCode;
                system("CLS");
                searchCsv(5,lineCode);
            }

            else if(option == 5)
            {
                system("CLS");
                cout <<endl<< "Enter the Size" <<endl;
                fflush(stdin);
                getline(cin,sizeValue);


                //for processing the size Value
                for(int i =0; i<sizeValue.size(); i++)
                {
                    if(sizeValue[i] == '-')
                    {
                        sizeValue[i] = -106;
                    }
                }

                system("CLS");
                searchCsv(3,sizeValue);
            }

            else if(option == 6)
            {
                system("CLS");
                cout <<endl<< "Enter the Description" <<endl;
                fflush(stdin);
                getline(cin,description);
                system("CLS");
                searchCsv(0,description);
            }
            else if(option == 7)
            {
                cout<<endl<<"Exiting !! . . . . "<<endl;
                return 0;
            }

            else
            {
                throw option;
                cout<<endl<<"Invalid input Try again !! "<<endl<<endl<<endl;
            }
        }
        catch (int x )
        {
            cout << "Exception Caught.. . .. Program is exiting . . . \n";
            break;
        }
    }
}

void searchCsv(int option,string value)
{
    ifstream fp("data.csv");
    if(!fp.is_open())
    {
        cout<<"Error -- File not found !! "<<endl;
        cout<<"Exiting . . . . . "<<endl;
        return;
    }


    string row,word,sizeTemp;
    vector<string> cols;
    int count = 0,flag = 0,id = 1,numberOfCols= 1,match;
    char temp;

//12832
    while(fp.good() && numberOfCols <=12832)
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

        //main searching starts here

        match = matchingCriteria(cols[option],value);
        if(match)
        {
            if(id == 1 )
            {
                cout<<"Result(s) : "<<endl<<endl;
                cout <<endl << "---------------------------------------------"<<endl;
            }

            //Size stringProcessing
            sizeTemp = sizeProcessing(cols[3]);
            flag = 1;
            cout <<"Serial No.  : " <<id<<endl;
            cout <<"Description : " <<cols[0]<<endl;
            cout <<"Industry    : " <<cols[1]<<endl;
            cout <<"Level       : " <<cols[2]<<endl;
            cout <<"Size        : " <<sizeTemp<<endl;
            cout <<"Line Code   : " <<cols[4]<<endl;
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

    else
    {
        cout << endl<< "Total Result(s) : "<<id-1<<endl;
    }

    cout<<endl<<endl;

    fflush(stdin);
    cout<<"Search Again ?? -> (y/n)"<<endl;
    cin >>temp;
    fflush(stdin);

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

string sizeProcessing(string x)
{

    for(int i =0; i<x.size(); i++)
    {
        if(x[i] == -106)
        {
            x[i] = 45;
        }
    }
    return x;
}

int matchingCriteria(string cols,string value)
{
    transform(cols.begin(), cols.end(), cols.begin(), ::tolower);
    transform(value.begin(), value.end(), value.begin(), ::tolower);

    if(cols == value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

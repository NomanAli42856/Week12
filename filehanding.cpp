#include<iostream>
#include<fstream>
using namespace std;

void filewrite();
void fileread();
void readwholefile();
main()
{
    system("cls");
    
    filewrite();

    fileread();

    readwholefile();
}

void filewrite()
{
    fstream myfiles;
    myfiles.open("Rough.txt",ios::out);
    myfiles << "My name is Noman." << endl;
    myfiles << "I am almost happy." << endl;
    myfiles << "Programming is my passion." << endl;
    myfiles << 19 << endl;
    myfiles << 78.8 ;
    myfiles.close();
}

void fileread()
{
    string name,comment;
    char ch;
    fstream myfiles;
    myfiles.open("Rough.txt",ios::in);
    getline(myfiles,name);
    getline(myfiles,comment);
    myfiles >> ch;
    cout << name << endl << comment << endl << ch << endl;
    myfiles.close();
}

void readwholefile()
{
    int count=0;
    string line;
    fstream myfiles;
    myfiles.open("Rough.txt",ios::in);
    while(!myfiles.eof())
    {
        getline(myfiles,line);
        cout << line << endl;
        count++;
    }
    myfiles.close();
    cout << count;
}
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void topHeader();
void signInterface();
void signup();
void signin();
void allUsers();

string names[10] = {};
string passwords[10] = {};
string roles[10] = {};


main()
{

    system("cls");

    topHeader();
    int choice;
    while(choice !=3)
    {
        signInterface();
        cout << "Enter your choice : ";
        cin >> choice;
        
        if(choice == 1)
        {
            cout << "     Signup Menu" << endl << "-----------------------"<< endl;
            signup();
        }
        else if(choice == 2)
        {

            cout << "     Signin Menu" << endl << "-----------------------"<< endl;
            signin();
        }
    }
    
    

}

void topHeader()
{
    cout << "##########################################" << endl;
    cout << "####                                  ####" << endl;
    cout << "####    RESTAURANT MANAGMENT SYSTEM   ####" << endl;
    cout << "####                                  ####" << endl;
    cout << "##########################################" << endl;
}

void signInterface()
{
    system("cls");
    topHeader();
    cout << "1-       Signup" << endl ;
    cout << "2-       Signin" << endl; 
    cout << "3-       All the users" << endl;

}

void signup()
{
    fstream files;
    files.open("Signup.txt",ios::app);
    string name,password;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter password : ";
    cin >> password;
    for(int i=0;i<10;i++)
    {
        if(names[i]=="" && names[i] != name)
        {
            files << name << endl; 
            files << password << endl; 
            names[i]=name;
            passwords[i] = password;
            files.close();
            cout << "Loguped Successfully";
            getch();
            break;
        }
        else
        {
            cout << "Username already exists";
            getch();
        }


    }
}
void signin()
{
    bool flag = false;
    fstream files;
    files.open("Signup.txt",ios::in);
    string checkname,checkpassword;
    string name,password;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter password : ";
    cin >> password;
    while(!files.eof())
    {
        getline(files,checkname);
        getline(files,checkpassword);
        if(checkname == name && checkpassword == password)
        {
            flag = true;
        }
    }
    if(flag)
    {
        cout << "Logined Successfully";
        getch();
    }
}
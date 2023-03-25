#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

void topHeader();
int signInterface();
void signup(string userName,string password);
void storeInFile(string userName,string password);
bool signin(string userName,string password);
bool isValidUserName(string userName);
void allUsers();
void arrayfilling();

string names[10] = {};
string passwords[10] = {};
int userCount = 0;


main()
{

    system("cls");

    arrayfilling();
    topHeader();
    int choice = 0;
    while(choice != 4)
    {
        choice = signInterface();
        string name,password;
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter password : ";
        cin >> password;
        if(choice == 1)
        {
            cout << "     Signup Menu" << endl << "-----------------------"<< endl;
            if(isValidUserName(name))
            {
                signup(name,password);
            }
            else
            {
                cout << "UserName already exists" << endl;
            }
        }
        else if(choice == 2)
        {

            cout << "     Signin Menu" << endl << "-----------------------"<< endl;
            if(signin(name,password))
                cout << "SignIn sucessfully" << endl;
            else
                cout << "USer name or password is incorrect" << endl;
        }
        else if(choice == 3)
        {
            allUsers();
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
int signInterface()
{
    int choice;
    cout << "1-       Signup" << endl ;
    cout << "2-       Signin" << endl; 
    cout << "3-       All the users" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;

}
void signup(string userName,string password)
{
    names[userCount]=userName;
    passwords[userCount] = password;
    userCount++;
    storeInFile(userName,password);
    cout << "Signed up sucessfully";
}

void storeInFile(string userName,string password)
{
    fstream files;
    files.open("Sign.txt",ios::app);
    files << userName << endl; 
    files << password << endl; 
    files.close();

}
bool signin(string userName,string password)
{
    bool flag = false;
    for(int i = 0; i < userCount; i++)
    {
        if(userName == names[i] && password == passwords[i])
        {
            flag = true;
        }
    }
    return flag;
}

void allUsers()
{
    for(int i = 0; i < userCount; i++)
    {
        cout << names[i] << "\t" << passwords[i] << endl;
    }
}

bool isValidUserName(string userName)
{
    int flag = true;
    for(int i = 0; i < userCount; i++)
    {
        if(userName == names[i])
        {
            flag = false;
        }
    }
    return flag;

}

void arrayfilling()
{
    int i = 0;
    fstream files;
    files.open("Sign.txt",ios::in);
    while(!files.eof())
    {
    

        string name,password;
        getline(files,name);
        getline(files,password);
        names[i] = name;
        passwords[i] = password;
        i++;
        userCount = i;
            
    }

}
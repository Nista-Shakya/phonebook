#include "Login.h"

Login::Login()
{

}
void Login::loginPage()
{
    char tempName[10];
    gotoxy(30, 9);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    gotoxy(55, 10);
    cout << "LOGIN";
    gotoxy(30, 11);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    gotoxy(30, 20);
    cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
    gotoxy(42, 14);
    cout << "USERNAME:";
    cin >> username;
    gotoxy(42, 16);
    cout << "PASSWORD:";
    for (int i = 0;;)
    {
        a = getch();//stores char typed in a
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'))
            //check if a is numeric or alphabet
        {
            password[i] = a;//stores a in password
            ++i;
            cout << "*";
        }
        if (a == '\b' && i >= 1)//if user typed backspace
              //i should be greater than 1.
        {
            cout << "\b \b";//rub the character behind the cursor.
            --i;
        }
        if (a == '\r')//if enter is pressed
        {
            password[i] = '\0';//null means end of string.
            break;//break the loop
        }
    }
    int found=0;
    ifstream fin("userrecord.txt",ios::binary);
    while(fin.read(reinterpret_cast<char*>(&user),sizeof(user)))
    {
        if(strcmp(user.getUserName(),username)==0 && strcmp(user.getPassword(),password)==0)
        {
            if(strcmp(user.getUserName(),"Admin")==0)
            {
                found=1;
            }
            else
            {
                found=2;
                strcpy(tempName,username);

            }
        }
    }
    fin.close();
    if(found==1)
    {
        adminPage admin;
        admin.homePage("Admin");
    }
    else if(found==2)
    {
        userPage user;
        user.homePage(tempName);
    }
    else if(found==0)
    {
        char choose;
        gotoxy(40, 24);
        cout << "Invalid Username or Password";
        gotoxy(40, 26);
        cout << "Do you want to continue? y/n:";
        cin>>choose;
        if (choose == 'y' || choose == 'Y')
        {
            system("cls");
            loginPage();
        }
        else
        {
            exit(0);
        }
    }
}

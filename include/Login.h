#ifndef LOGIN_H
#define LOGIN_H
//inbuilt headerfiles
#include <iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<ctype.h>
#include<cstring>
#include<regex>
#include<algorithm>
//created headerfiles
#include"gotoxy.h"
#include"Person.h"
#include"adminPage.h"
#include"userPage.h"
using namespace std;
class Login
{
    private:
        int a, b;
        char username[10];
        char password[10];
        Person user;
    public:
        Login();
        void loginPage();

};

#endif // LOGIN_H

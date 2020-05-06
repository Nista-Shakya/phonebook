#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include<conio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<ctype.h>
#include<cstring>
#include<algorithm>

#include"Capital.h"
using namespace std;
class Person
{
    private:
        char userName[10];
        char password[10];
    public:
        Person();
        void addUser();
        void showUser();
        void deleteUser();
        char* getUserName();
        char* getPassword();

};
 char *capital(char a[20]);
#endif // PERSON_H

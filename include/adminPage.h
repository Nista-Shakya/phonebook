#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include"Phonebook.h"
#include"Login.h"
#include"Person.h"
class adminPage : public Phonebook
{
    private:
       Person person;
    public:
        adminPage();
        void homePage(char* name);
};

#endif // ADMINPAGE_H

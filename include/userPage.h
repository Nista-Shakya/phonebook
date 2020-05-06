#ifndef USERPAGE_H
#define USERPAGE_H

#include"Phonebook.h"
#include"Login.h"
#include"Person.h"

class userPage : public Phonebook
{
    private:
        Person person;
    public:
        userPage();
        void homePage(char* name);
};

#endif // USERPAGE_H

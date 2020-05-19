#ifndef PHONEBOOK_H
#define PHONEBOOK_H

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

#include"utilities.h"
#include"gotoxy.h"
#include"Capital.h"
using namespace std;

class Phonebook
{
      protected:
        char firstname[20],lastname[20],address[20],phone_number[11],homeNum[10],email[30],fullname[25];
        int idNumber;


      public:
       Phonebook();
       char *getName();    //returns first name
       char *getNumber();  //returns work number
       char *getHomeNum(); //returns home number
       char *getAddress();//returns address
       char *getFullName();//return full name
       int getIdNumber();//return id number
       void addData(int id);   //information to add data
       void showData();   //shows the added data
       void storeData();  //stores data into file by writing the data into the file
       void readData();   //reads the added data from the file
       void searchData();  //searches for the matched data
       void deleteData();  //deletes the data from the file
       void editData();    //edits the data from the matched name
       void editData_copy(char* name,int id); //reduces repeated code for multiple names to edit data
       int getId();        //return id number to get new id,also to get last id number from the file
       int totalDataEntry(); //total entry in the file

};

#endif // PHONEBOOK_H

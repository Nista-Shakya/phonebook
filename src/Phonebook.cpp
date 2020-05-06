#include "Phonebook.h"

Phonebook::Phonebook()
{ }
char* Phonebook::getName()    //returns first name
{
   return firstname;
}
char* Phonebook::getNumber()  //returns number
{
   return phone_number;
}
char* Phonebook::getAddress()  //returns address
{
   return address;
}
char* Phonebook::getFullName()
{
    return fullname;
}
int Phonebook::getIdNumber()
{
    return idNumber;
}
void Phonebook::addData()
{
        int l;
        cout<<"\nENTER YOUR NAME \n";
        cout<<"First name:";
        cin>>firstname;
        cin.ignore();
        cout<<"Last name:";
        cin>>lastname;
        cin.ignore();
        cout<<"Address:";
        cin>>address;
        cin.ignore();
        cout<<"Enter phone number:";
        cin>>phone_number;
        cin.ignore();
        l=strlen(phone_number);
        while(l!=10 || phone_number[0]!='9' || (phone_number[1]>='a' && phone_number[10]<='z') || (phone_number[1]>='A' && phone_number[10]<='Z'))
          {
            cout<<"You have entered wrong number!\n";
            cout<<"Re enter phone number:";
            cin>>phone_number;
            l=strlen(phone_number);

          }
          char cemail;
        cout<<"Do you have an email(y/n)?:";
        cin>>cemail;
        if(cemail=='y' || cemail=='Y')
        {
            cout<<"Enter email:";
    while(1)
       {
        cin>>email;
        cin.ignore();
        regex emailCheck("(\\w+)(\\.|_|-|\\+|\\*|\\$|\\#|\\!|\\%|\\=)?(\\w*)@(gmail|yahoo|outlook|live|hotmail|aol|msn|rediffmail)+(\\.(com|org|gov|net|edu|int|mil|fr|state))+");
        bool match=regex_match(email,emailCheck);  //attempts to match a regular expression to an entire character sequence
        if(match)
        {
            break;
        }
        else
           {
             cout<<"Invalid Email\n";
             cout<<"Enter again:";
           }
        }
        }
        else
            {
                strcpy(email,"---");
            }
            strcpy(fullname,firstname);
            strcat(fullname," ");
            strcat(fullname,lastname);
            idNumber=rand()%1000+1;
}

void Phonebook::showData()
{
    cout.setf(ios::left,ios::adjustfield);
    cout<<setw(15)<<fullname<<setw(15)<<"\t"<<address<<setw(10)<<"\t"<<phone_number<<"\t"<<email<<endl;
}

void Phonebook::storeData()
{
           ofstream fout;
           fout.open("phonebook2.txt",ios::out|ios::app|ios::binary);
           addData();
           fout.write((char*)this,sizeof(*this));
           fout.close();
           gotoxy(45,25);
           cout<<"RECORD SUCCESSFULLY ADDED!!!";
           gotoxy(45,26);
           cout<<"Press any key to continue";
           _getch();
}

void Phonebook::readData()
{
    int cnt=0;
    ifstream fin;
    fin.open("phonebook2.txt", ios::in);
    fin.read((char*)this, sizeof(*this));
    while (!fin.eof())
    {
        //showData();
        cnt++;
        fin.read((char*)this, sizeof(*this));
    }
    fin.close();
    ifstream fin1;
    fin1.open("phonebook2.txt", ios::in);
    string *ptr;
    ptr=new string[cnt];
    int i=0;
    fin1.read((char*)this, sizeof(*this));
    while (!fin1.eof())
    {
        *(ptr+i)=this->getFullName();
        i++;
        fin1.read((char*)this, sizeof(*this));
    }
    fin1.close();
    sort(ptr,ptr+cnt);
    ifstream fin2;
    fin2.open("phonebook2.txt", ios::in);
    for(int i=0;i<cnt;i++)
    {
         while (fin2.read((char*)this, sizeof(*this)))
        {
            const char* c=ptr[i].c_str();
            std::string d;
            if(i>0)
            {
                d=ptr[i-1];
            }
            if (strcmp(c,this->getFullName()) == 0 && strcmp(c,d.c_str())!=0)
            {
                showData();
                break;
            }
             if (strcmp(c,this->getFullName()) == 0 && strcmp(c,d.c_str())==0)
             {
                 fin2.read((char*)this, sizeof(*this));
                 while(strcmp(c,this->getFullName()) != 0)
                 {
                     fin2.read((char*)this, sizeof(*this));
                 }
                 showData();
                 break;
             }
        }
        fin2.seekg(ios::beg);
    }
    fin2.close();
    delete []ptr;


}
  void Phonebook::searchData()
    {

       char fname[20];
       char phonenumber[11];
       char Address[20];
       ifstream fin;
       int flag=0;
       string choose;
       fin.open("phonebook2.txt",ios::in);
       gotoxy(55,3);
       cout<<"Search by:";
       gotoxy(24,4);
       cout<<"------------------------------------------------------------------"<<endl;
       cout<<"\t\t\t1.First name\t 2.Phone number\t   3.Address"<<endl;
       gotoxy(24,6);
       cout<<"------------------------------------------------------------------"<<endl;
       cout<<"Enter your choice:";


       top:
       cin>>choose;
       if(choose=="1")
          {
           cout<<"Enter name to display:";
           cin>>fname;
           strcpy(fname,capital(fname));
           char chkname[20];
          while(fin.read((char*)this,sizeof(*this)))
           {
              strcpy(chkname,getName());
              if(strcmp(fname,capital(chkname))==0)
                {
                showData();
                flag++;
                }
           }
        if(flag>0)
        {
            cout<<"\n\t\t\t\t\t\t RECORD FOUND!!";
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t\t\t\tSORRY!NO RESULT FOUND!!";
        }

    }
    else if(choose=="2")
    {
        cout<<"Enter phonenumber to display:";
        cin>>phonenumber;
        while(fin.read((char*)this,sizeof(*this)))
    {
        if(strcmp(phonenumber,getNumber())==0)
        {
            showData();
            flag++;
        }
    }
      if(flag>0)
        {
            cout<<"\n\t\t\t\t\t\t RECORD FOUND!!";
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t\t\t\tSORRY!NO RESULT FOUND!!";
        }
     }
    else if(choose=="3")
    {
           cout<<"Enter address to display:";
            cin>>Address;
            strcpy(Address,capital(Address));
            char chkAddress[20];
            while(fin.read((char*)this,sizeof(*this)))
          {
              strcpy(chkAddress,getAddress());
               if(strcmp(Address,capital(chkAddress))==0)
            {
               showData();
               flag++;
            }
          }

        if(flag>0)
        {
            cout<<"\n\t\t\t\t\t\t RECORD FOUND!!";
        }
        if(flag==0)
        {
            cout<<"\n\t\t\t\t\t\tSORRY!NO RESULT FOUND!!";
        }
    }
    else
    {
       cout<<"Invalid!!Choose number from 1 to 3:";
       goto top;
    }
  }
    void Phonebook::deleteData()
    {

        char name[20];
        char chkname[20];
        char del;
        int flag=0,flag1=0;
        ifstream fin;
        ofstream fout;
        fin.open("phonebook2.txt",ios::in|ios::binary);
        cout<<"Enter name to delete data:";
        cin>>name;
        strcpy(name,capital(name));
        cin.ignore();
        fout.open("temporaryfile2.txt",ios::out|ios::binary);
         fin.read((char*)this,sizeof(*this));
         while(!fin.eof())
         {
             strcpy(chkname,getName());

                 if(strcmp(name,capital(chkname))==0)
                 {
                     cout<<"Id Number:"<<idNumber<<endl;
                       showData();
                       flag1++;
                 }
               fin.read((char*)this,sizeof(*this));
         }

                fin.clear();
                fin.seekg(0,ios::beg);

         if(flag1==1)
         {
             while(!fin.eof())
         {

                 strcpy(chkname,getName());

                 if(strcmp(name,capital(chkname))==0)
                 {

                       cout<<"Are you sure you want to delete this data? y/n:";
                       cin>>del;
                       if(del=='y' || del=='Y')
                         {
                                fin.clear();
                                fin.seekg(0,ios::beg);
                                flag++;

                             while(!fin.eof())
                            {
                                strcpy(chkname,getName());
                              if(strcmp(name,capital(chkname))!=0)
                           {
                             fout.write((char*)this,sizeof(*this));
                           }
                    fin.read((char*)this,sizeof(*this));
                           }
                       }

                   else
                    {
                        break;

                   }
                 }
                  if(strcmp(name,getName())!=0)
                  {
                      fin.read((char*)this,sizeof(*this));

                  }

             }
         }
         else if(flag1>1)
         {
             int id;
             cout<<"Enter id number to delete:";
             cin>>id;
             if(cin.fail())
             {
                 cin.clear();
                 cin.ignore(32767,'\n');
             }
                while(!fin.eof())
         {

                 if(id==getIdNumber())
                 {
                        showData();
                       cout<<"Are you sure you want to delete this data? y/n:";
                       cin>>del;
                       if(del=='y' || del=='Y')
                         {
                                fin.clear();
                                fin.seekg(0,ios::beg);
                                flag++;

                             while(!fin.eof())
                            {

                              if(id!=getIdNumber())
                           {
                             fout.write((char*)this,sizeof(*this));
                           }
                    fin.read((char*)this,sizeof(*this));
                           }
                       }

                   else
                    {
                        break;

                   }
                 }
                  if(id!=getIdNumber())
                  {
                      fin.read((char*)this,sizeof(*this));

                  }

             }
         }
         fin.close();
         fout.close();

         if(flag>0)
         {
              remove("phonebook2.txt");
         rename("temporaryfile2.txt","phonebook2.txt");

             cout<<"\n\n\t\t\t\t\t\tDELETE SUCCESSFULL!!";
         }

        if(flag==0 && toupper(del)!='N')
         {
             cout<<"\n\n\t\t\t\t\t\tSORRY!RECORD NOT FOUND!!";
         }
         if(toupper(del)=='N')
         {
             cout<<"\n\n\t\t\t\t\t\tPress any key to continue";
         }
    }

 void Phonebook::editData()
 {

    char name[20];
    int flag=0;
    cout<<"Enter the name to modify:";
    cin>>name;
    strcpy(name,capital(name));
    fstream finout;
    finout.open("phonebook2.txt",ios::in|ios::out|ios::ate|ios::binary);
    finout.seekg(0);
    finout.read((char*)this,sizeof(*this));
    while(!finout.eof())
      {
        char chkname[20];
        strcpy(chkname,getName());
        if (strcmp(name,capital(chkname))==0)
        {
            char option;
            cout<<"\n The following record will be modified:\n";
            showData();
            cout<<"\n What do you want to modify?"<<endl;
            cout<<"1.First name"<<endl;
            cout<<"2.Last name"<<endl;
            cout<<"3.Address"<<endl;
            cout<<"4.Phone Number"<<endl;
            cout<<"5.Email"<<endl;
            cout<<"Enter choice:"<<endl;
            cin>>option;
              switch(option)
            {
                case '1':
                    cout<<"Enter first name:"<<endl;
                    cin>>firstname;
                    cin.ignore();
                    break;
                case '2':
                    cout<<"Enter last name:"<<endl;
                    cin>>lastname;
                    cin.ignore();
                    break;
                case '3':
                    cout<<"Enter address:"<<endl;
                    cin>>address;
                    cin.ignore();
                    break;
                case '4':
                    cout<<"Enter Phone Number:"<<endl;
                   cin>>phone_number;
        cin.ignore();
        int l;
        l=strlen(phone_number);
        while(l!=10 || phone_number[0]!='9' || (phone_number[1]>='a' && phone_number[10]<='z') || (phone_number[1]>='A' && phone_number[10]<='Z'))
          {
            cout<<"You have entered wrong number!\n";
            cout<<"Re enter phone number:";
            cin>>phone_number;
            l=strlen(phone_number);

          }
                    break;
                     case '5':
                     cout<<"Enter email:";
                    while(1)
                       {
                        cin>>email;
                        cin.ignore();
                        regex emailCheck("(\\w+)(\\.|_|-|\\+|\\*|\\$|\\#|\\!|\\%|\\=)?(\\w*)@(gmail|yahoo|outlook|live|hotmail|aol|msn|rediffmail)+(\\.(com|org|gov|net|edu|int|mil|fr|state))+");
                        bool match=regex_match(email,emailCheck);  //attempts to match a regular expression to an entire character sequence
                        if(match)
                        {
                            break;
                        }
                        else
                           {
                             cout<<"Invalid Email\n";
                             cout<<"Enter again:";
                           }
                        }
                        break;
                default:
                    cout<<"Choose number between 1 to 5";
                    _getch();
                    break;
            }
             strcpy(fullname,firstname);
            strcat(fullname," ");
            strcat(fullname,lastname);
            finout.seekp(finout.tellp()-sizeof(*this));
            finout.write((char*)this,sizeof(*this));
               flag++;
        }
         finout.read((char*)this,sizeof(*this));
      }
    finout.close();
    if(flag>0)
    {
        cout<<"Data Modified Successfully!!";
    }
    if(flag==0)
        cout<<"\n Record of the name is not in the file \n";
     _getch();
 }

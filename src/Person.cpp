#include "Person.h"
char* capital(char a[20])//to make all the string in capital letter
{
   int l;
   l=strlen(a);
   for(int i=0;i<l;i++)
   {
       a[i]=toupper(a[i]);
   }
  return a;
}

Person::Person()
{
    //ctor
}
void Person::addUser()
{
    int a;
    char tempname[3][10];
    cout<<"Enter username:";
    cin>>tempname[1];
    ifstream fin("userrecord.txt",ios::binary);
    fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!fin.eof())
    {
        strcpy(tempname[2],tempname[1]);
        strcpy(tempname[3],userName);
        if(strcmp(capital(tempname[2]),capital(tempname[3]))==0)
        {
          cout<<"User already exists!!"<<endl;
          cout<<"Re-enter username:";
          cin>>tempname[1];
          fin.seekg(ios::beg);
        }
         fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    fin.close();
    strcpy(userName,tempname[1]);
    cout<<"Enter password:";
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
        ofstream fout("userrecord.txt",ios::binary|ios::app);
        fout.write(reinterpret_cast<char*>(this),sizeof(*this));
        fout.close();
        cout<<"\nRECORD SUCCESSFULLY ADDED!!!";
        cout<<"\nPress any key to continue";
        getch();
}
void Person::showUser()
{
    int cnt=0;
    ifstream fin("userrecord.txt",ios::in);
    fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!fin.eof())
    {
            cnt++;
        fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    fin.close();
    ifstream fin1("userrecord.txt",ios::in);
    string *ptr;
    ptr=new string[cnt];
    int i=0;
    fin1.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!fin1.eof())
    {
        *(ptr+i)=this->getUserName();
        i++;
        fin1.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
    fin1.close();
    sort(ptr,ptr+cnt);
    ifstream fin2("userrecord.txt",ios::in);
     cout.setf(ios::left,ios::adjustfield);
     int sn=1;
    for(int i=0;i<cnt;i++)
    {
        while(fin2.read(reinterpret_cast<char*>(this),sizeof(*this)))
        {
            const char* c=ptr[i].c_str();
            if(strcmp(c,"Admin")==0)
            {
                break;
            }
            if(strcmp(c,getUserName())==0)
            {
                cout<<setw(4)<<sn<<"\t"<<setw(15)<<userName<<"\t"<<setw(15)<<password<<endl;
                sn++;
                break;
            }
        }
        fin2.seekg(ios::beg);
    }
    fin2.close();
    delete []ptr;
}
void Person::deleteUser()
{
    char name[10];
    char chkname[10];
    char del;
    int i=0,flag=0;
    ifstream fin;
    ofstream fout;
    fin.open("userrecord.txt",ios::in|ios::binary);
    fout.open("temporaryfile.txt",ios::out|ios::binary);
    cout<<"Enter user to delete:";
    cin>>name;
    strcpy(name,capital(name));
    cin.ignore();
    fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    while(!fin.eof())
    {
        strcpy(chkname,getUserName());
        if(strcmp(name,capital(chkname))==0)
        {
             cout<<userName<<"\t"<<password<<endl;
            cout<<"Record Found!!"<<endl;
            i++;
        }
        fin.read(reinterpret_cast<char*>(this),sizeof(*this));
    }
      fin.clear();
        fin.seekg(0,ios::beg);
    if(i==1)
    {
           while(!fin.eof())
         {
            strcpy(chkname,getUserName());
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
                        strcpy(chkname,getUserName());
                        if(strcmp(name,capital(chkname))!=0)
                        {
                            fout.write(reinterpret_cast<char*>(this),sizeof(*this));
                        }
                        fin.read(reinterpret_cast<char*>(this),sizeof(*this));
                    }
                }
                else
                {
                    break;
                }
            }
            if(strcmp(name,getUserName())!=0)
            {
                fin.read(reinterpret_cast<char*>(this),sizeof(*this));
            }
        }
    }
    else
    {
        cout<<"No Record Found"<<endl;
    }
    fin.close();
    fout.close();
    if(flag>0 && toupper(del)!='N')
    {
        remove("userrecord.txt");
        rename("temporaryfile.txt","userrecord.txt");
        cout<<"User Deleted!!!"<<endl;
    }
    cout<<"Press any key to continue..";
    getch();
}
char* Person::getUserName()
{
    return userName;
}
char* Person::getPassword()
{
    return password;
}


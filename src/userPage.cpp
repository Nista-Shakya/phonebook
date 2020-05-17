#include "userPage.h"

userPage::userPage()
{
    //ctor
}
void userPage::homePage(char* name)
{
    int a;
    int totEntry;
     while (1)
    {
        system("cls");
        totEntry=totalDataEntry();
        system("COLOR 3f");
        gotoxy(0, 1);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        gotoxy(50, 2);
        cout << "WELCOME TO PHONEBOOK";
        gotoxy(0, 3);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout<<"Username:"<<name;
        gotoxy(40, 6);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        gotoxy(40, 10);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        gotoxy(50, 7);
        cout << "1.Display\n";
        gotoxy(50, 8);
        cout << "2.Search\n";
        gotoxy(50, 9);
        cout << "3.Log Out\n";
        gotoxy(50, 12);
        cout << "Enter a choice:";
        cin>>a;
          while(cin.fail())
        {
            cin.clear();
            cin.ignore(32767,'\n');
            cout<<"\n\t\t\t\t\t\tEnter a choice in integer:";
            cin>>a;
        }
         switch (a)
        {
        case 1:
             system("cls");
            system("COLOR f5");
            cout<<"Total Entry:"<<totEntry;
            gotoxy(0, 1);
             //cout<<setw(12)<<firstname<<setw(15)<<"\t"<<address<<setw(10)<<"\t"<<phone_number<<"\t"<<email<<endl;
             cout.setf(ios::left,ios::adjustfield);
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << setw(20) << "Name" << setw(15) << "\t" << "Address" << setw(10) << "\t" << "Phone no: Work"<<"\t\tHome" << "\t\t" << "Email" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            readData();
            cout << "\n\n\t\t\t\t\tPress any key to continue";
            getch();
            break;

        case 2:
            system("COLOR f5");
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(45, 1);
            cout << "SEARCH YOUR RECORD";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            searchData();
            char cont;
            while (1)
            {
                cout << "\n\nDo you want to continue y/n?";
                cin>>cont;
                if (cont == 'y' || cont == 'Y')
                {
                    system("cls");
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                    gotoxy(52, 1);
                    cout << "SEARCH YOUR RECORD";
                    gotoxy(0, 2);
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                    searchData();
                }
                else
                {
                    break;
                }
            }
            cout << "\n\n\t\t\t\t\tPress any key to continue";
            getch();
            break;
        case 3:
           char log;
            gotoxy(40,15);
            cout<<"Are you sure you want to log out(y/n)?";
            cin>>log;
            if(log=='y' || log=='Y')
            {
                system("cls");
                system("COLOR 3f");
                Login login1;
                login1.loginPage();
            }
            else
            {
                system("cls");
                system("COLOR f5");
                homePage(name);
            }
            break;

        default:
            gotoxy(44, 14);
            cout << "Choose a number between 1 and 3:";
            getch();
            break;
        }
}
}

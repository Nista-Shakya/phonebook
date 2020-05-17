#include "adminPage.h"

adminPage::adminPage()
{
    //ctor
}
void adminPage::homePage(char* name)
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
        cout << "WELCOME TO PHONEBOOK ";
        gotoxy(0, 3);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
        cout<<"Username:"<<name;
        gotoxy(40, 6);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        gotoxy(40, 16);
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        gotoxy(50, 7);
        cout << "1.Add Contacts\n";
        gotoxy(50, 8);
        cout << "2.Edit Contacts\n";
        gotoxy(50, 9);
        cout << "3.Display Contacts\n";
        gotoxy(50, 10);
        cout << "4.Search Contacts\n";
        gotoxy(50, 11);
        cout << "5.Delete Contacts\n";
        gotoxy(50, 12);
        cout << "6.Add Users\n";
        gotoxy(50,13);
        cout << "7.Display Users\n";
        gotoxy(50,14);
        cout << "8.Delete Users\n";
        gotoxy(50,15);
        cout << "9.Log Out\n";
        gotoxy(50, 19);
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
            system("COLOR f5");
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(52, 1);
            cout << "ADD YOUR RECORD";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            storeData();
            break;
        case 2:
            system("COLOR f5");
            system("cls");
             cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(52, 1);
            cout << "EDIT YOUR RECORD";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            editData();
            break;
        case 3:
            system("cls");
            system("COLOR f5");

              cout<<"Total Entry:"<<totEntry<<"\t\t\t\t\t\t\t\t\t\t\tRemaining Entry:"<<MAX_ENTRY-totEntry;
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

        case 4:
            system("COLOR f5");
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(52, 1);
            cout << "SEARCH YOUR RECORD";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
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

        case 5:
            system("cls");
            system("COLOR F5");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(52, 1);
            cout << "DELETE YOUR RECORD";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            deleteData();
            getch();
            break;
        case 6:
            system("cls");
            system("COLOR f5");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(54, 1);
            cout << "ADD USER";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            person.addUser();
            break;
        case 7:
            system("cls");
            system("COLOR f5");
            cout<<"\n";
             cout<<setw(4)<<"S.N\t"<<setw(8)<<"Username\t"<<setw(8)<<"Password"<<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            person.showUser();
             cout << "\n\n\t\t\t\t\tPress any key to continue";
            getch();
            break;
        case 8:
            system("cls");
            system("COLOR f5");
             cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            gotoxy(54, 1);
            cout << "DELETE USER";
            gotoxy(0, 2);
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            person.deleteUser();
            break;
        case 9:
            char log;
            gotoxy(40,19);
            cout<<"Are you sure you want to log out(y/n)?";
            cin>>log;
            if(log=='y' || log=='Y')
            { system("COLOR f5"); gotoxy(50,19);
                 system("cls");
                system("COLOR 3f");
                Login lo;
                lo.loginPage();
            }
            else
            {
                system("cls");
                system("COLOR f5");
                homePage(name);
            }
            break;

        default:
            gotoxy(48, 20);
            cout << "Choose a number between 1 and 9:";
            getch();
            break;
        }
    }
}

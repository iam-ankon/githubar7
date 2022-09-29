#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class bank
    {
    private:
        int total;
        string id;
        struct person
        {
            string name,id,address;
            int contact,cash;
        }person[10000];
        
    public:
        bank(){
            total=0;
        }
        void choice();
        void persondata();
        void show();
        void update();
        void search();
        void transaction();
        void remove();
        void login();
        void registr();
        void forgot();
        void start();
    };
main(){
    bank b;
    b.start();
    return 0;
}
void bank::start(){
    int choice;
     cout<<"\n\n\n\t   __      __   ___  | |   ___    ___    _ __ ___     ___ \n ";
			cout<<"\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ \n";
            cout<<"\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ \n";
            cout<<"\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| \n"<<endl;
                cout<<"\n\t\t\t      TO BANKING MANAGEMENT"<<endl;
            cout << "\n\t    ________________________ SYSTEM _________________________\n\n\n";

    cout << "\t\t\t* Press 1 For Login            " << endl;
    cout << "\t\t\t* Press 2 For Registration     " << endl;
    cout << "\t\t\t* Press 3 For Forgot Password  " << endl;
    cout << "\t\t\t* Press 4 For Quit             " << endl;

    cout << "\n\t\t\t\t Enter Your choice : ";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        bank::login();
        break;
    case 2:
       bank::registr();
        break;
    case 3:
        bank::forgot();
        break;
    case 4:

        cout << "Thanks for using this program!!!\n\n";
        break;
    default:
        system("cls");
        cout << "You've made a mistake , give it a try again\n"
             << endl;
    }
}
void bank::login(){
    {
    int count;
    string user, pass, u, p;
    system("cls");
    cout << "please enter the following Details." << endl;
    cout << "Enter  The USERNAME : ";
    cin >> user;
    cout << "Enter  The PASSWORD : ";
    cin >> pass;

    ifstream input("Bank.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << "\n\t\t\tHello " << user << "\n\t\t\tLOGIN SUCCESS\n\t\t\tWe're glad that you're here.\n\t\t\tThanks for logging in!!!\n";
        cin.get();
        cin.get();
        bank::choice();
    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease Check your Username and Password\n";
        main();
    }
}
}
void bank::registr(){
    string reguser, regpass, ru, rp;
    system("cls");
    cout << "Enter the Username : ";
    cin >> reguser;
    cout << "\nEnter the Password : ";
    cin >> regpass;

    ofstream reg("Bank.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    system("cls");
    cout << "\nRegistration Successful\n";
    bank::login();
}
void bank::forgot(){
        int ch;
    system("cls");
    cout << "\n\t$$Are You Forgotten Your Password ? Don't Worry we are Here For Help!!$$\n";
    cout << "\n\t\t----------------------------------------------------------"<<endl;
    cout << "\t\t| If You Search your Id by Username Then Choose Option 1 |" << endl;
    cout << "\t\t----------------------------------------------------------"<<endl;
    cout << "\t\t| If You Search your ID by Password Then Choose Option 2 |" << endl;
    cout << "\t\t----------------------------------------------------------"<<endl;
    cout << "\t\t| If You Want to Go Back to Main Menu Then Choose Option 3|"<< endl;
    cout << "\t\t-----------------------------------------------------------"<<endl;
    cout << "\n\n\t\t\tEnter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\nEnter your remembered Username : ";
        cin >> searchuser;

        ifstream searchu("Bank.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << "\n\nAccount found\n";
            cout << "\nYour password is : " << sp;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\nSorry, Your userID is not found in our Database.\n";
            cout << "\nPlease kindly contact your system Administrator for more details. \n";
            cin.get();
            cin.get();
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\nEnter the password you remember : ";
        cin >> searchpass;

        ifstream searchp("Bank.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\nYour Password is Found in the database : \n";
            cout << "\nYour ID is : " << su2;
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "Sorry, We cannot found your password in our Database. \n";
            cout << "\nkindly contact your Administrator for more Information.\n";
            cin.get();
            cin.get();
            main();
        }

        break;
    }

    case 3:
    {
        cin.get();
        main();
    }
    default:
        cout << "Sorry, You entered wrong choice. Try again!!!" << endl;
        forgot();
    }
}
void bank::choice(){
    char ch;
    while (1)
    {
    cout<<"\n\n USE A KEY "<<endl;
    cout<<"1. CREATE A NEW ACCOUNT "<<endl;
    cout<<"2. SHOW USER LIST "<<endl;
    cout<<"3. UPDATE INFORMATION OF AN ACCOUNT "<<endl; 
    cout<<"4. CHECK THE DETAILS OF AN ACCOUNT "<<endl;
    cout<<"5. TRANSACTIONS "<<endl;
    cout<<"6. REMOVE  ACCOUNT "<<endl;
    cout<<"7. LEAVE "<<endl;
    ch=getch();
    system("CLS");
    switch (ch)
    {
    case '1':
        bank::persondata();
        break;
    case '2':
       if(total==0){
        cout<<"NO DATA IS ENTERED "<<endl;
       }else{
        bank::show();
       }    
        break;
    case '3':
        if(total==0){
        cout<<"NO DATA IS ENTERED "<<endl;
       }else{
        bank::update();
       }
        break;
    case '4':
       if(total==0){
        cout<<"NO DATA IS ENTERED "<<endl;
       }else{
        bank::search();
       }
        break;
    case '5':
        if(total==0){
        cout<<"NO DATA IS ENTERED "<<endl;
       }else{
        bank::transaction();
       }
        break;
    case '6':
       if(total==0){
        cout<<"NO DATA IS ENTERED "<<endl;
       }else{
        bank::remove();
       }
        break; 
    case '7': 
       exit(0);
       break;                   
    }
    }
    
}
void bank::persondata(){
    cout<<"ENTER PERSON DATA"<<total+1<<endl;
    cout<<"ENTER PERSON NAME"<<endl;
    cin>>person[total].name;
    cout<<"ENTER PERSON ID"<<endl;
    cin>>person[total].id;
    cout<<"ENTER PERSON ADDRESS"<<endl;
    cin>>person[total].address;
    cout<<"ENTER PERSON CONTACT"<<endl;
    cin>>person[total].contact;
    cout<<"ENTER PERSON CASH"<<endl;
    cin>>person[total].cash;
    total++;
}
void bank::show(){
    for(int i=0;i<total;i++){
        cout<<"DATA OF A PERSON"<<i+1<<endl;
        cout<<"NAME"<<person[i].name<<endl;
        cout<<"ID"<<person[i].id<<endl;
        cout<<"ADDRESS"<<person[i].address<<endl;
        cout<<"CONTACT"<<person[i].contact<<endl;
        cout<<"CASH"<<person[i].cash<<endl;
    }
}
void bank::update(){
    cout<<"ENTER ID OF A USER THAT YOU WANT TO UPDATE"<<endl;
    cin>>id;
     for(int i=0;i<total;i++){
        if(id==person[i].id){
        cout<<"NAME"<<person[i].name<<endl;
        cout<<"ID"<<person[i].id<<endl;
        cout<<"ADDRESS"<<person[i].address<<endl;
        cout<<"CONTACT"<<person[i].contact<<endl;
        cout<<"CASH"<<person[i].cash<<endl;
        cout<<"ENTER NEW DATA"<<endl;
        cout<<"NAME";
        cin>>person[i].name;
        cout<<"ID";
        cin>>person[i].id;
        cout<<"ADDRESS";
        cin>>person[i].address;
        cout<<"CONTACT";
        cin>>person[i].contact;
        cout<<"CASH";
        cin>>person[i].cash;
    break; 
    }
    if(i==total-1){
        cout<<"NOT FOUND "<<endl;
    }
    }

}
void bank::search(){
     cout<<"ENTER ID OF A USER THAT YOU WANT TO SEARCH"<<endl;
     cin>>id;
     for(int i=0;i<total;i++){
        if(id==person[i].id){
        cout<<"NAME"<<person[i].name<<endl;
        cout<<"ID"<<person[i].id<<endl;
        cout<<"ADDRESS"<<person[i].address<<endl;
        cout<<"CONTACT"<<person[i].contact<<endl;
        cout<<"CASH"<<person[i].cash<<endl;  
        }
        break;
        if(i==total-1){
            cout<<"NOT FOUND "<<endl;
        }
     }
}
void bank::transaction(){
    int cash;
    cout<<"ENTER ID OF A USER THAT YOU WANT TO TRANSACTION"<<endl;
    cin>>id;
    char ch;
    for(int i=0;i<total;i++){
        if(id==person[i].id){
          cout<<"NAME"<<person[i].name<<endl;
          cout<<"ID"<<person[i].id<<endl;
          cout<<"ADDRESS"<<person[i].address<<endl; 
          cout<<"EXISTING CASH "<<person[i].cash<<endl;
          cout<<"PRESS 1 TO DEPOSIT"<<endl;
          cout<<"PRESS 2 TO WITHDRAW"<<endl; 
          ch=getch();
          switch (ch)
          {
          case '1':
            cout<<"HOW MUCH CASH YOU WANT TO DEPOSIT? "<<endl;
            cin>>cash;
            person[i].cash+=cash;
            cout<<"YOUR NEW CASH IS "<<person[i].cash<<endl;
            break;
          case '2':
            back:
            cout<<"HOW MUCH CASH YOU WANT TO WITHDRAW? "<<endl; 
            cin>>cash;
            if(cash>person[i].cash){
              cout <<"YOUR CASH JUST "<<person[i].cash<<endl;
              _sleep(3000);
              goto back;
            }
            person[i].cash-=cash;
            cout<<"YOUR NEW CASH IS "<<person[i].cash<<endl;
            break;
            default:
            cout<<"INVALID INPUT "<<endl;
            break;
          }
          break; 
        }
        if(i==total-1){
            cout<<"NOT FOUND "<<endl;
        }
    }
}
void bank::remove(){
     char ch;
    cout<<"PRESS 1 TO REMOVE SPECIFIC RECORD "<<endl;
    cout<<"PRESS 2 TO REMOVE ALL RECORD!!! "<<endl;
    ch=getch(); 
    switch (ch)
    {
    case '1':
        cout<<"ENTER UESER ID TO DELETE A RECORD "<<endl;
        cin>>id;
        for(int i=0;i<total;i++){
            if(id==person[i].id){
                for(int j=i;j<total;j++){
                person[j].name=person[j+1].name;
                person[j].id=person[j+1].id;
                person[j].address=person[j+1].address;
                person[j].contact=person[j+1].contact;
                person[j].cash=person[j+1].cash;
                total--;

                cout<<"YOUR DATA IS DELETED "<<endl;
                break;
               }
            }
            if(i==total-1){
                cout<<"NOT FOUND "<<endl;
            }
        }
        break;
        case '2':
            total=0;
            cout<<"ALL RECORD REMOVED "<<endl;
            break;
    
    default:
    cout<<"INVALID INPUT "<<endl;
        break;
    }
}
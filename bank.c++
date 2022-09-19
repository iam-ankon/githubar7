#include<bits/stdc++.h>
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
    };
int main(){
    bank b;
    b.choice();
    return 0;
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
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n;i++){
       cin>>s;
       if(s=="Hajj"){
        cout<<"case :"<<i+1<<" Hajj-e-Akbar"<<endl;
       }
       if(s=="Umrah"){
        cout<<"case :"<<i+1<<" Hajj-e-Asghar"<<endl;
       }
       if(s=="*"){
         break;
       }
    }
}
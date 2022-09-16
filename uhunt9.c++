#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t=0;
    cin>>n;
    string s;
    int a;
    for(int i=0;i<n;i++){
       cin>>s;
       if(s=="donate"){
        cin>>a;
         t+=a;
       }
       else{
        cout<<t<<endl;
       }
    }
    return 0;
}
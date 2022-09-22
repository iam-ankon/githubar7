#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
       int a;
       cin>>a;
       int b[a];
        int m=1;
       for(int j=0;j<a;j++){
        cin>>b[j];
         if(m<b[j]){
            m=b[j];
         }
       }  
       cout<<"Case "<<i<<": "<<m<<endl;
    }
    return 0;
}
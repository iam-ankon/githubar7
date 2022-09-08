#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l,w,h;
    cin>>n;
    for(int i=0;i<n;i++){
       cin>>l>>w>>h;
       if(l<=20&&w<=20&&h<=20){
        cout<<"Case "<<i+1<<": "<<"good"<<endl;
       }
       else{
        cout<<"Case "<<i+1<<": "<<"bad"<<endl;
       }
    }
}
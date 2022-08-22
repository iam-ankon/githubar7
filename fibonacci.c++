#include<bits/stdc++.h>
using namespace std;
int main(){
    int x ,y, t1=0,t2=1;
    cin>>x;
    cout<<t1<<" "<<t2<<" ";
    for(int i=3;i<x;i++){
        y=t1+t2;
        t1 = t2;
        t2 = y;
         cout << y << " ";
    }
   
}
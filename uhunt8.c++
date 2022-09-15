#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a=0;
    while (cin>>n,n)
    {
       a++;
        int add=0,b;
        for(int j=0;j<n;j++){
           cin>>b;
        if(b>0){
            add++;
        }
        else{
            add--;
        }
        }
        cout<<"case "<<a<<": "<<add<<endl;
    }
    return 0;
}
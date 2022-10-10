#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[30];
    while (gets(a)!=NULL)
    {
        for(int i=0;a[i]!=NULL;i++){
            if(a[i]>='A'&&a[i]<='C')cout<<2;
            if(a[i]>='D'&&a[i]<='F')cout<<3;
            if(a[i]>='G'&&a[i]<='I')cout<<4;
            if(a[i]>='J'&&a[i]<='L')cout<<5;
            if(a[i]>='M'&&a[i]<='O')cout<<6;
            if(a[i]>='P'&&a[i]<='S')cout<<7;
            if(a[i]>='T'&&a[i]<='V')cout<<8;
            if(a[i]>='W'&&a[i]<='Z')cout<<9;
            if(a[i]=='1'||a[i]=='0'||a[i]=='-')cout<<a[i];
        }
    }
    
    return 0;
}
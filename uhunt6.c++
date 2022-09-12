#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if((a>b&&a<c)||(a>c&&a<b)){
            cout<<"Case "<<i+1<<": "<<a<<endl;
        }
        else if((b>a&&b<c)||(b<a&&b>c)){
            cout<<"Case "<<i+1<<": "<<b<<endl;
        }
        else{
            cout<<"Case "<<i+1<<": "<<c<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        int e=0;
        cin>>a;
        for(int i=0;i<a;i++){
            cin>>b>>c>>d;
            e+=b*d;
        }
         cout<<e<<endl;
    }
}
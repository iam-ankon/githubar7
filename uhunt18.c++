#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,c=0,d=0;
        cin>>a;
        for(int j=0;j<a;j++){
            int b;
            cin>>b;
                c+=((b/30)+1)*10;
                d+=((b/60)+1)*15;
        }
        cout<<"Case "<<i+1<<": ";
        if(c<d){
            cout<<"Mile "<<c<<endl;
        }
        else if(d<c){
            cout<<"Juice "<<d<<endl;
        }
        else{
            cout<<"Mile Juice "<<c<<endl;
        }
    }
    return 0;
}
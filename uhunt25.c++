#include<bits/stdc++.h>
using namespace std;
int main(){
    long long unsigned a,b;
    while (cin>>a>>b)
    {
         long long unsigned c=0;
        if(a<b){
          c+=b-a;
        }
        else{
            c+=a-b;
        }
        cout<<c<<endl;
    }
    
    return 0;
}
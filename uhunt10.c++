#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n&&n!=0)
    {
        int a=n;
        while ((a/10)>0)
        {
            int s=0;
            while(n>0){
                s+=n%10;
                n/=10;
            }
            a=s;
            n=a;
        }
        cout<<a<<endl;
    }
    
    return 0;
}
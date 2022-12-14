#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,bin[100000];
    while(cin>>n)
    {
        int i=1,c=0;
        if(n==0)break;
        while(n!=0)
        {
            bin[i++]=n%2;
            n/=2;
        }
        cout<<"The parity of ";
        for(int j=i-1;j>0;j--)
        {
            cout<<bin[j];
            if(bin[j]==1)c++;
        }
        cout<<" is "<<c<<" (mod 2)."<<endl;
    }
}
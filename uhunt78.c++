#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    while(cin>>n)
    {
        if(n%2==0)break;
        n=n/2+1;
        n=n*n;
        cout<<6*n-9<<endl;
    }
}
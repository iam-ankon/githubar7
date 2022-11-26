#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        int u=0;
        while(n>=3)
        {
            u+=(n/3);
            n=n/3+n%3;
        }
        if(n==2)u++;
        if(n==0)break;
        cout<<u<<endl;
    }
    
}
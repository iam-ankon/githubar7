#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        int u=n;
        while(n>=3)
        {
            u+=(n/3);
            n=n/3+n%3;
        }
        if(n==2)u++;
        cout<<u<<endl;
    }
    
}
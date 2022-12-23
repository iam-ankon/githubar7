#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        if(n==14&&m==14)break;
        cout<<max(n,m)<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        cout<<(2*x-y)*z/(x+y)<<endl;
    }
}
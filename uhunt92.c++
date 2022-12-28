#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int a,b=0;
        for(int i=0;i<n;i++)
        {
            int ok=1;
            for(int j=0;j<m;j++)
            {
                cin>>a;
                ok=ok&a>0;
            }
            b+=ok;
        }
        cout<<b<<endl;
    }
}
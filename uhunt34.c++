#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,o;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>o;
            if(j == m/2)
            {
                cout<<"Case "<<i<<": "<<o<<endl;
            }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        x=b+c;
        while(x>a)
        {
            x=x-a;   
        }
        cout<<"Case "<<i<<": "<<x<<endl;
    }
}
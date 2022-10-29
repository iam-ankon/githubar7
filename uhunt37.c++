#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double d,v,u;
    cin>>n;
    double t1,t2;
    for(int i=1;i<=n;i++)
    {
        cin>>d>>v>>u;
        if(v>=u||v==0||u==0)
        {
            cout<<"Case "<<i<<": "<<"can't determine"<<endl;
            continue;
        }
        t1=d/u;
        t2=d/sqrt(u*u-v*v);
        cout<<fixed<<setprecision(3)<<"Case "<<i<<": "<<fabs(t2-t1)<<endl;
    }
}
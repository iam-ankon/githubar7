#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n,u,v,a,t,s;
    int test=1;
    while(cin>>n)
    {
        if(n==0)break;
        cout<<"Case "<<test++<<": ";
        if(n==1)
        {
            cin>>u>>v>>t;
            a=(v-u)/t;
            s=(v+u)*t/2;
            printf("%.3lf %.3lf\n", s, a);
        }
        else if(n==2)
        {
            cin>>u>>v>>a;
            t=(v-u)/a;
            s=(v+u)*t/2;
            printf("%.3lf %.3lf\n", s, t);
        }
        else if(n==3)
        {
            cin>>u>>a>>s;
            v=sqrt(u*u+2*a*s);
            t=(v-u)/a;
            printf("%.3lf %.3lf\n", v, t);
        }
        else if(n==4)
        {
            cin>>v>>a>>s;
            u=sqrt(v*v-2*a*s);
            t=(v-u)/a;
            printf("%.3lf %.3lf\n", u, t);
        }
    }
}
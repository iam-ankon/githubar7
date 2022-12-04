#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t=1,a;
    double f;
    cin>>n;
    while (n--)
    {
        cin>>a;
        double h=0;
        for(int i=0;i<a;i++)
        {
            cin>>f;
            h+=f;
        }
        h=h/a;
        printf("Case #%d: %.3lf\n", t, h );
    }
    
}
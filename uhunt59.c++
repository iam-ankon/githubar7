#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int s=0,f;
        cin>>a>>b>>c;
        f=a+b;
        while (f>=c)
        {
            s+=f/c;
            f=f/c+f%c;
        }
        cout<<s<<endl;
    }
}
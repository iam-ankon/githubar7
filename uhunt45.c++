#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>b>>c;
        if(b>c)
        {
            cout<<">"<<endl;
        }
        else if(b<c)
        {
            cout<<"<"<<endl;
        }
        else
        {
            cout<<"="<<endl;
        }
    }
}
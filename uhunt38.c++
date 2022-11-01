#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1;
    int r,n;
    while (cin>>r>>n,n)
    {
        --r;
        cout<<"Case "<<t++<<": ";
        if(r/n>26)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<r/n<<endl;
        }
    }
    
}
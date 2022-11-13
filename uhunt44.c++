#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int num;
        cin>>num;
        bool found(false);
        cout<<"Case #"<<i<<": "<<num<<" = ";
        int j=2;
        for(;j<num;++j)
        {
            if(num%j==0)
            {
                if(!found)
                {
                    cout<<j<<" * "<<num/j<<" = ";
                    found=true;
                }
                else 
                break;
            }
        }
        cout<<j<<" * "<<num/j<<endl;
    }
}
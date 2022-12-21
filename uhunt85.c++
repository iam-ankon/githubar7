#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s; 
    while(cin>>n)
    {
        if(n==0)break;
        cin>>s;
        int md=n,lastR=-n,lastD=-n;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='Z')
            {
                md=0;
                break;
            }
            else if(s[i]=='R')
            {
                md=min(md,i-lastD);
                lastR=i;
            }
            else if(s[i]=='D')
            {
                md=min(md,i-lastR);
                lastD=i;
            }
        }
        cout<<md<<endl;
    }
}
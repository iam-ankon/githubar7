#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,l;
    while (cin>>a>>b>>c>>d>>l)
    {
        if(!a&&!b&&!c&&!d&&!l)break;
        int k=0;
        for(int i=0;i<=l;i++)
        {
            int s=a*i*i+b*i+c;
            if(s%d==0)k++;
        }
        cout<<k<<endl;
    }
    
}

#include<bits/stdc++.h>
#include<cstdio>
#include<map>
using namespace std;
int main()
{
    int n,a;
    cin>>n;
    map<char,double> m;
    while(n--)
    {
        cin>>a;
        m.clear();

        char ch;
        int b,c;
        while (a--)
        {
            getchar();
            ch=getchar();
            cin>>b;
            m[ch]=b;
        }
        cin>>c;
        ch=getchar();
        long count=0;
        while(ch=getchar())
        {
            if(ch!=' '||ch!='\n')
            {
                count+=m[ch];
            }
        }
        printf("%0.2f$\n",count/100.0);
    }
}


#include<bits/stdc++.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string a,b;
    while(getline(cin,a),getline(cin,b))
    {
        int ac[128],bc[128];
        for(int i='a';i<='z';++i)
        {
            ac[i]=bc[i]=0;
        }
        for(int i=0;i<a.size();++i)
        {
            ++ac[a[i]];
        }
        for(int i=0;i<b.size();++i)
        {
            ++bc[b[i]];
        }
        string lon="";
        for(int i='a';i<='z';++i)
        {
            while(ac[i]>0&&bc[i]>0)
            {
                lon += (char) i;
                --ac[i];
                --bc[i];
            }
        }
        cout<<lon<<endl;
    }
}
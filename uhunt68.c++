#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    int n,a,b,l;
    char c;
    double v,total;
    string line;
    map<char,double> m;
    map<char,double>:: iterator it;
    cin>>n;
    while (n--)
    {
        total=0;
        cin>>a;
        while (a--)
        {
            cin>>c>>v;
            m[c]=v;
        }
        cin>>b;
        cin.ignore();
        while (b--)
        {
            line = "";
            getline(cin,line);
            l = line.size();
            for(int i=0;i<l;i++)
            {
                it = m.find(line[i]);
                if(it!=m.end())
                total+=it->second;
            } 
        }
        total/=100;
        printf("%0.2lf$\n",total);
        m.clear();
    }
    
}
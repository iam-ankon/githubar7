#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n , n>0)
    {
        string s;
        cin>>s;
        string::iterator b(s.begin());
        int gps = s.size()/n;
        for(;b!=s.end();b+=gps)
        {
            reverse(b,b+gps);
        }
        cout<<s<<endl;
    }
    
    return 0;
}
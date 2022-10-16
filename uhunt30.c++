#include<bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    while (getline(cin,n))
    {
        string s = "";
        vector<string> tem;
        int len = n.length();
        for(int i=0;i<len;i++)
        {
            if(n[i]!=' ')s += n[i];
            else
            {
                reverse(s.begin(),s.end());
                tem.push_back(s);
                s.clear();
            }
        }
        reverse(s.begin(),s.end());
        tem.push_back(s);
        int f = tem.size();
        for(int i=0;i<f;i++)
        {
            cout<<tem[i];
            if(i != f-1)cout<<" ";
        }
        cout<<endl;
        n.clear();
    }
    return 0;
}
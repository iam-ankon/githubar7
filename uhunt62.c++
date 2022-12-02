#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,f,g;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f>>g;
        int c=0;
        while (f>=g)
        {
            f -= (g-1);
            c++;
        }
        if(f != 1)
        {
            cout<<"cannot do this"<<endl;
        }
        else
        cout<<c<<endl;
    }
}
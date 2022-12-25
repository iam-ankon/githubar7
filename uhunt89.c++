#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        int in[n];
        for(int i=0;i<n;i++)
        {
            cin>>in[i];
        }
        int co=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(in[i]>in[j]) ++co;
               
            }
        }
        cout<<"Minimum exchange operations : "<<co<<endl;
    }
    
}
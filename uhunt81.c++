#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mat[101][101];
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat[i][j];
            }
        }
        int r[100]={0},c[100]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
            }
        }
        int er=0,ec=0,ro,co;
        for(int i=0;i<n;i++)
        {
            if(r[i]&1)er++,ro=i;
            if(c[i]&1)ec++,co=i;
        }
        if(er==0&&ec==0)
           puts("OK");
        else if(er==1&&ec==1)
               printf("Change bit (%d,%d)\n",ro+1,co+1);
        else
             puts("Corrupt");
    }
}
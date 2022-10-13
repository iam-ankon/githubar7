#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while (cin>>a>>b)
    {
        int x=0,y=0;
        x=(a>b)?a:b;
        y=(a<b)?a:b;
        int max=0;
        for(int i=y;i<=x;i++)
        {
            int k=0;
            int u=i;
            //while (u!=1)
            //{
                 k++;
            if(u%2==1)
            {
                u=u*3+1;
            }
            else
            {
                u=u/2;
            }
          //  } 
            if(k>max)
            {
                 max=k;
            }
        }
        cout<<a<<" "<<b<<" "<<max+1<<endl;
    }
    
}
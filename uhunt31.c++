#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int sum =0;
        cin>>d;
        int ar[d];
        for(int i=0;i<d;i++)
        {
            cin>>ar[i];
            sum+=ar[i];       
        }
        int avg=sum/d;
        int c=0;
        for(int i=0;i<d;i++)
        {
            if(ar[i]>avg)
            {
                c++;
            }
            
        }
       printf("%.3lf%%\n", (double) c / (double) d * 100.0);
    }
}
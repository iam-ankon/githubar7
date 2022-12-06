#include<bits/stdc++.h>
using namespace std;
int A[25000+5];
int wt[100+5];
int knapsack(int N,int W)
{
    for(int i=0;i<=W;i++)A[i]=0;

    for(int i=1;i<=N;i++)
        for(int j=W;j>0;j--)
        {
            if(wt[i]<=j)A[j]=max(A[j],wt[i]+A[j-wt[i]]);
        }
        return A[W];
}
int main()
{
    int n,m;
    
    cin>>n;
    while(n--)
    {
        cin>>m;
        int p=0;
        for(int i=1;i<=m;i++)
        {
            cin>>wt[i];
            p+=wt[i];
        }
        cout<<p-2*knapsack(m,p/2)<<endl;
    }
}
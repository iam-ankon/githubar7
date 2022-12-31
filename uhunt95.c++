#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    long long sum;
    while(cin>>n)
    {
        if(n==0)break;
        sum=0;
        priority_queue<long long> q;
        while(n--)
        {
            cin>>x;
            q.push(-x);
        }
        while(q.size()>1)
        {
            long long a=q.top();
            q.pop();
            long long b=q.top();
            q.pop();
            sum+=-a-b;
            q.push(a+b);
        }
        cout<<sum<<endl;
    }
}
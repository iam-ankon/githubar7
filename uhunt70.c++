#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,l,count,n;
    int i=1;
    while(cin>>a>>l)
    {
        if(a==-1&&l==-1)break;
        count=0;
        n=a;
        while(a<=l)
        {

            if(a==1){count++; break;}
            else if(a%2==0){a=a/2;count++;}
            else if(a%2==1){a=(3*a)+1;count++;}
        }
        cout<<"Case "<<i++<<": "<<"A "<<"= "<<n<<","<<" limit "<<"= "<<l<<", "<<"number of terms "<<"= "<<count<<endl;
    }
}
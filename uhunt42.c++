#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,a1,b1,res,carr;

    while (scanf("%lld %lld",&a,&b))
    {
        if(!a&&!b)break;
        carr=c=0;
        while (a||b)
        {
            a1=a%10;
            a/=10;
            b1=b%10;
            b/=10;

            res=a1+b1+c;
            if(res>9)
            {
                c=1;
                carr++;
            }
            else 
                c=0;
        }
        if(!carr)
        {
            cout<<"No carry operation."<<endl;
        }
        else if(carr==1)
        {
            cout<<"1 carry operation."<<endl;
        }
        else
        {
            printf("%lld carry operations.\n",carr);
        }
    }
    return 0;
}
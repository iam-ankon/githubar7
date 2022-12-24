#include<bits/stdc++.h>
using namespace std;
int main()
{
    char song[][20]={"Happy","birthday","to","you",
                    "Happy","birthday","to","you",
                    "Happy","birthday","to","Rujia",
                    "Happy","birthday","to","you"};
    char name[101][101];
    int n,flag=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name[i];
    }
    int i=0,j=0;
    while(1)
    {
        cout<<name[i]<<": "<<song[j]<<endl;
        if(i==n-1)
        {
            flag=1;
        }
        if(j==15&&flag)break;
        i++,j++;
        if(i>=n)i=0;
        if(j>=16)j=0;
    }                
}
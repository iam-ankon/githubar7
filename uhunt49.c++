#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char a[10];
        cin>>a;
        if(strlen(a) == 5)
        {
            cout<<"3"<<endl;
        }
        else
        {
            int s=0;
            if(a[0]=='o')s++;
            if(a[1]=='n')s++;
            if(a[2]=='e')s++;
            if(s>=2)
            {
            cout<<"1"<<endl;
            }
            else
            cout<<"2"<<endl;
        }
    }
}

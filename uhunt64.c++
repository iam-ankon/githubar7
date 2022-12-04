#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,e,f,g,h,j,i=1;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d>>e>>f>>g;
        if(e<=f&&e<=g)
        {
            j=(f+g)/2;
        }
        else if(f<=g&&f<=e)
        {
            j=(e+g)/2;
        }
        else if(g<=f&&g<=e)
        {
            j=(e+f)/2;
        }
        h=a+b+c+d+j;
        if(h>=90)
        {
            cout<<"Case "<<i++<<":"<<" A"<<endl;
        }
        else if(h>=80)
        {
            cout<<"Case "<<i++<<":"<<" B"<<endl;
        }
        else if(h>=70)
        {
            cout<<"Case "<<i++<<":"<<" C"<<endl;
        }
        else if(h>=60)
        {
            cout<<"Case "<<i++<<":"<<" D"<<endl;
        }
        else if(h<60)
        {
            cout<<"Case "<<i++<<":"<<" F"<<endl;
        }
    }
}
#include<bits/stdc++.h>
#define n 1000000
using namespace std;
static char s[n];
int main(){
    int a,c=1,bul,b,d;
    while (gets(s))
    {
        cin>>a;
        cout<<"Case "<<c++<<":"<<endl;
        while (a--)
        {
            bul=1;
            cin>>b>>d;
            if(b==d){
                cout<<"Yes"<<endl;
                continue;
            }
            if(b>d){
                for(int i=d;i<=b;i++){
                    if(s[i]!=s[b]){
                        bul=0;
                        cout<<"No"<<endl;
                        break;
                    }
                }
            }
            else{
                for (int  i = b; i <= d; i++)
                {
                    if(s[i]!=s[d]){
                        bul=0;
                        cout<<"No"<<endl;
                        break;
                    }
                }
                
            }
            if(bul){
                cout<<"Yes"<<endl;
            }
            
        }
           getchar();
    }
    return 0;
}
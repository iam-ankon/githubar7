#include<bits/stdc++.h>
using namespace std;
int main(){
    long int n,b,h,w;
    long int p,a;
    while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        long int cost=0;
        for(int i=0;i<h;i++)
        {
            
            cin>>p;
            for(int j=0;j<w;j++)
            {
                
                cin>>a;
                if(a>=n&&n*p<=b){
                  if(cost==0||n*p<cost){
                    cost=n*p;
                  }
                }
                
            }
           
        }
        if(cost==0){
            cout<<"stay home"<<endl;
        }
        else{
            cout<<cost<<endl;
        }
    }
    
}
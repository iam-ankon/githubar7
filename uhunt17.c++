#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int c,d,a,b;
    while ((cin>>a>>b),a!=-1)
    {
        if(a>b){
          c=a-b;
          d=b+100-a;
        }
        else{
            c=b-a;
            d=a+100-b;
        }
        cout<<std::min(c,d)<<endl;
    }
    return 0;
}
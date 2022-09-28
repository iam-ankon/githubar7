#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s,b,v=1;
    cin>>n;
    while (n--)
    {
        cin>>s>>b;
        int c=0;
        for(int i=s;i<=b;i++){
            
            if(i%2==1){
                
                c+=i;
            }
        }
        cout<<"Case "<<v++<<": "<<c<<endl;
    }
    
    return 0;
}
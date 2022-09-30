#include<bits/stdc++.h>
using namespace std;
int main(){
   int n,sum=0,c=0;
   cin>>n;
   int a[100];
   for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
   }
    c+=sum/n;
    int b=0;
    for(int i=0;i<n;i++){
      if(a[i]>c){
        b+=a[i]-c;
    }
    
    }
    int s=1;
    cout<<"Set #"<<s++<<endl;
   cout<<"The minimum number of moves is "<<b<<endl;
}
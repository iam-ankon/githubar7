#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int b[50]={0};
        for(int j=0;j<a;j++)
            cin>>b[j]; 

        int high=0,low=0;
        
        for(int j=0;j<a-1;j++){       
            if(b[j+1]>b[j]){
                high++;
            }
            if(b[j+1]<b[j]){
                low++;   
            }  
        } 
      cout<<"Case "<<i<<": "<<high<<" "<<low<<endl;
    } 
    return 0;
}
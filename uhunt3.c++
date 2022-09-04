#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,min,max;
       
    cin>>n;
    for(int i=0;i<n;i++){
        min=99;max=0;
    cin>>x;
    
         int arr[x];
    
   for(int i=0;i<x;i++){
        cin>>arr[i];
       
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
     cout<<(max-min)*2<<endl;
    }
   return 0;
}
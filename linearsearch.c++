#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,index;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    bool found;
    for(int i=0;i<n;i++){
        if(arr[i]==m){
            index = i+1;
            found = true;
        }
    }
    if(found){
    cout<<"found!! "<<m<<"index "<<index;
    }
    else{
            cout<<"not found";
        }
}
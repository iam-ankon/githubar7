#include<bits/stdc++.h>
using namespace std;
void heaplify(int arr[],int n,int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int large =i;
    if(l<n&&arr[l]>arr[i]){
        large = l;
    }
    if(r<n&&arr[r]>arr[i]){
        large = r;
    }
    if(large !=i){
        swap(arr[i],arr[large]);
        heaplify(arr,i,large);
    }
}
void buildheap(int arr[],int n){
     for(int i=(n/2)-1;i>=0;i--){
        heaplify(arr,n,i);
     }
}
void heapsort(int arr[],int n){
    buildheap(arr,n);
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heaplify(arr,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

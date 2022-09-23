#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    bool tr;
    cin>>n;
    cout<<"Lumberjacks:"<<endl;
    for(int i=0;i<n;i++){
        int b[10];
        for(int j=0;j<10;j++){
            cin>>b[j];
            if(b[j+9]>b[j+8]&&b[j+8]>b[j+7]&&b[j+7]>b[j+6]&&b[j+6]>b[j+5]&&b[j+5]>b[j+4]&&b[j+4]>b[j+3]&&b[j+3]>b[j+2]&&b[j+2]>b[j+1]&&b[j+1]>b[j]||b[j]>b[j+1]&&b[j+1]>b[j+2]&&b[j+2]>b[j+3]&&b[j+3]>b[j+4]&&b[j+4]>b[j+5]&&b[j+5]>b[j+6]&&b[j+6]>b[j+7]&&b[j+7]>b[j+8]&&b[j+8]>b[j+9]){
                tr = true;  
            }
        }
        if(tr){
            cout<<"Orderred"<<endl;
        }
        else{
            cout<<"unorderred"<<endl;
        }
    }
    return 0;
}
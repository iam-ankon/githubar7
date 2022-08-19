#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin >> ar[i];
    }
    int m;
    cin >> m;
    int first = 0;
    int last = n;
    int middle = (first+last)/2;
    while (first <= last)
    {
        if(ar[middle]<m){
            first = middle+1;
        }
        else if(ar[middle]==m){
            cout << "found!! "<<m<<endl<<"position "<< middle+1;
            break;
        }
          else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"\nThe number, "<<m<<" is not found in given Array";
    cout<<endl;
    
    return 0;
}
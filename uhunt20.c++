#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    vector<int> arr;
    freopen("input.txt", "r", stdin);
    cin>>n;
    while (n--)
    {
        
        cin>>a;
        string b;
        while (a--)
        {
            cin>>b;
            int count=0;
            if(b=="LEFT"){
                arr.push_back(-1);
            }
            if(b=="RIGHT"){
                arr.push_back(1);
            }
            if(b=="SAME"){
                cin >> b;
                cin >> count;
                arr.push_back(arr.at(--count));
            } 
        }
        int sum =0;
        for(int i=0; i<(int) arr.size(); i++) sum += arr.at(i);
        cout << sum << endl;
        arr.clear();
        
    }
    
    return 0;
}
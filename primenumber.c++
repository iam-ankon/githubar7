#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    for(int i = 2 ; i<=x ; i++){
        int carr =0;
        for(int j=2;j<sqrt(i);j++){
             if(i%j==0){
            carr=1;
        }
        
        }
         if(carr==0){
        cout << i <<" ";
      }
    }
    getch();

}
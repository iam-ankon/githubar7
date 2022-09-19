#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int n , count=0 , row , col;
    cin>> n;
    for(int row = 1;row<=n;row++){
        for(col = 1;col<=row;col++){
          cout << " " <<++count;
           }
          cout << endl;
        }
    
        
    

    getch();
}
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int n , row , col;
    cin>> n;
    for(int row = 1;row<=n;row++){
        for(col = 1;col<=row;col++){
            cout <<" "<<row%2;
        }
        cout << endl;
    }
    getch();
}
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int x,y;
    cin >> x >> y;
    int max = (x>y)?x:y;
    cout << max;
    getch();
}
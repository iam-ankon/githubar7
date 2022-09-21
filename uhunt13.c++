#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b,c;
    while (scanf("%d%d%d%d",&n,&a,&b,&c),n||a||b||c)
    {
        printf("%d\n", 1080 + ((n - a + 40) % 40 + (b - a + 40) % 40 + (b - c + 40) % 40) * 9);
    }
    return 0;
}

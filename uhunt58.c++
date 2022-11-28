#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,l;
    while (cin>>a>>b>>c>>d>>l)
    {
        if(!a&&!b&&!c&&!d&&!l)break;
        int k=0;
        for(int i=0;i<=l;i++)
        {
            int s=a*i*i+b*i+c;
            if(s%d==0)k++;
        }
        cout<<k<<endl;
    }
    
}



/*
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

main() {
    int a, b, c, d, L;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &L)) {
        if (!a && !b && !c && !d && !L) break;
        int kount = 0;
        for (int i=0; i<=L; i++) {
            int tmp = a*i*i + b*i + c;
            if (tmp%d == 0) kount++;
        }
        printf("%d\n", kount);
    }
}
*/
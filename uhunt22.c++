#include<bits/stdc++.h>
using namespace std;
int jk(char *c){
    int total(0);
    while (*c)
    {
        if(*c>='a'&&*c<='z'){
          total += *c-96;
        }
        else if(*c>='A'&&*c<='Z'){
            total += *c-64;
        }
        ++c;
    }
    while (total>=10)
    {
        int temp=0;
        while (total)
        {
            temp+=total%10;
            total/=10;
        }
        total=temp;
    }
    return total;
    
}
int main(){
    char a[30],b[30];
    int first,second;
    while (gets(a))
    {
        gets(b);
        first=jk(a);
        second=jk(b);
        if(first>second){
            printf("%.2f %%\n", second * 100.0 / first);
        }
        else{
            printf("%.2f %%\n", first * 100.0 / second);
        }
    }
    
    return 0;
}
#include<iostream>
using namespace std;

int main(){
    double a,b;
    char c;
    scanf("%lf %c %lf", &a, &c, &b);
    if(c=='+'){
        printf("%.2lf + %.2lf = %.2lf", a,b, a + b);
    }
    else if(c=='-'){
        printf("%lf - %lf = %lf", a,b,a - b);
    }
    else if(c=='/'){
        printf("%lf / %lf = %lf", a,b,a / b);
    }
    else if(c=='*'){
        printf("%lf * %lf = %lf", a,b,a * b);
    }
    else{
        printf("Invalid operation!");
    }
     return 0;
}
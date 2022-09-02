#include<iostream>
using namespace std;
class calculator
{
 public:
 double a,b,c;
 void sum (double a,double b){ 
 cout<<"Sum of two values: "<<endl;
 cout<<"a+b = "<<a+b<<endl<<"a-b = "<<a-b<<endl;
 cout<<"a*b = "<<a*b<<endl<<"a/b = "<<a/b<<endl<<endl;
 }
 void sum(double a,double b,double c){ 
 cout<<"Sum of three values: "<<endl;
 cout<<"a+b+c = "<<a+b+c<<endl<<"a-b-c = "<<a-b-c<<endl;
 cout<<"a*b*c = "<<a*b*c<<endl<<"a/b/c = "<<a/b/c<<endl;
 }
};
 int main(){
 calculator ob;
 ob. sum(30,11),ob.sum(30,11,10);
 return 0;
 }

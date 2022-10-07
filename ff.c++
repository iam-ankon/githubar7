#include<iostream>
using namespace std;
int state0(string s);
int state1(string s);
int state2(string s);
int state3(string s);
int state4(string s);
 
int main(){
    string s;
    cout<<"enter comment: ";
    cin>>s;
    int  res;
    res = state0(s);
 
    for(int k =0; k<s.length()-3; k++){
        if(res == 2){
            res = state1(s);
        }
        else if(res ==3){
            res = state2(s);
        }
        else if(res ==4){
            res = state3(s);
        }
        else if(res == 5){
            res = state4(s);
        }
        else if(res == 6)break;
    }
    if(res == 6)
        cout<<"valid comment";
    else
        cout<<"Invalid comment";
 
    return 0;
}
int state0(string s){
    int temp = 0;
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == '/')
            temp = 2;
    }
    return temp;
}
int state1(string s){
    int temp =0;
    for(int i=0; i<s.length()-1; i++){
        if(s[i] == '/' && s[i+1] == '/')
    {
            temp = 5;
            break;
        }
        else if(s[i] == '/' && s[i+1] == '*')
        {
            temp = 3;
            break;
        }
 
    }
    return temp;
}
int state2(string s)
{
    int temp = 0;
    for(int i=0; i<s.length()-2; i++)
    {
        if(s[i] == '*')
        {
            temp = 4;
            break;
        }
    }
    return temp;
}
int state3(string s)
{
    int temp = 0;
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i] == '/')
            temp = 5;
    }
    return temp;
}
int state4(string s)
{
    int temp =0;
    for(int k=0; k<s.length()-1; k++)
    {
        if((s[k] == '*' && s[k+1] == '/')||(s[k] == '/' && s[k+1] == '/'))
        {
            temp = 6;
            break;
        }
    }
 
    return temp;
}
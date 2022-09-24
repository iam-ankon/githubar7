#include<iostream>
using namespace std;
class TourPlace
{
public:
    string name;
    double distance,cost;
   TourPlace(string n, double a,double b){
        name = n;
        distance = a;
        cost = b;
   }
   double show(){
       cout << name << endl;
       cout << distance << endl;
       cout << cost << endl;
   }
  
};

int main(){
    TourPlace place1("Saint-martin",20000,10000);
    place1.show();
    TourPlace place2("Kuakata",14000.34,4000.33);
    place2.show();
    TourPlace place3("Coxsbazar",18000.66,6222.85);
    place3.show();
    return 0;
}
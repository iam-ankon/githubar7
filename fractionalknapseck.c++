#include <bits/stdc++.h>
using namespace std;
struct item
{
    int value;
    int weight;
};
bool compare(item &a, item &b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
double fractionalknapsack(struct item arr[], int n, int w)
{
    sort(arr, arr + n, compare);
    int curweight = 0;
    double curvalue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (curweight + arr[i].weight <= w)
        {
            curweight += arr[i].weight;
            curvalue += arr[i].value;
        }
        else
        {
            int remain = w - curweight;
            curvalue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return curvalue;
}
int main()
{
    int n;
    cin >> n;
    item arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].value;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].weight;
    }
    int w;
    cin >> w;
    double result = fractionalknapsack(arr, n, w);
    if ((int)result == result)
        cout << fixed << setprecision(1) << result;
    else
    {
        cout << result;
    }
}
#include<iostream>
using namespace std;


int factorial(int n){
    if(n=0){
        return 1;
    }

    int minus1fact = factorial(n-1);

    int smallcalc = minus1fact*n;
    return smallcalc;
}
int main()
{

    int n;
    cin>>n;
    cout<<factorial(n);

    return 0;
}
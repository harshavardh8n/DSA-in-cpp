#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void sayDigit(int test,vector<string>array){
  

    if(test==0){
        return;
    }
    int digit = test%10;
    test/=10;
    sayDigit(test,array);
    cout<<array[digit];



}
int main()
{
      vector<string>numbers = {" zero "," one "," two "," three "," four "," five "," six "," seven "," eight "," nine "};
    // vector<int>test = {1,4,5,6,9,3};
    int test;
    cin>>test;
    sayDigit(test,numbers);

    return 0;
}
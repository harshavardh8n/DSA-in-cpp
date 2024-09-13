#include<iostream>
using namespace std;

int expoen(int n){

    if(n==1){
        return 2;
    }

    int reccall = expoen(n-1);
    int smallcalc = reccall*2;
    return smallcalc;

 
}
int main()   
{

    cout<<expoen(3);
    return 0;
}
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    bool isprime = true;
    int i=2;

    while(i<n)
    {
        if(n%i==0){
            isprime = false;
            break;
        }
        i++;

    }

    if(isprime){
        cout<<"number is prime";
    }
    else{
        cout<<"number aint prime";
    }
    

    return 0;
}
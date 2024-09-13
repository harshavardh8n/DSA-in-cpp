#include<iostream>
using namespace std;

int fibonacii(int n){
    if(n==1){
        // cout<<n<<" ";
        return 1;
    }
    if(n==0){
        // cout<<n<<" ";
        return 0;
    }
    // cout<<n<<" ";
    int call1 = fibonacii(n-1);
    int call2 = fibonacii(n-2);
    return call1+call2;
}
int main()

{
    // cout<< fibonacii(0)<<endl;
    cout<< fibonacii(1)<<endl;
    cout<< fibonacii(2)<<endl;
    cout<< fibonacii(3)<<endl;
    cout<< fibonacii(4)<<endl;
    cout<< fibonacii(5)<<endl;
    return 0;
}
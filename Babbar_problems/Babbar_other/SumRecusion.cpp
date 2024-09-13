#include<iostream>
using namespace std;

int sum(int arr[],int n){
    // if()
    // if()
    // if(arr[0]==n-1){
    //     return arr[0];
    // }
    if(n==1){
        return arr[0];
    }

    return arr[0]+sum(arr+1,n-1);
}

int main(){
    int arr[5] = {2,3,5,6,8};
    int ans = sum(arr,5);
    cout<<ans;
    return 0;
}
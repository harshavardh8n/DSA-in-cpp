#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int> arr){

sort(arr.begin(),arr.end());

for(int i:arr){
    // if(arr[i]==arr[i+1]){
    //     return arr[i];
    cout<<i<<arr[i]<<endl;
    }
    return 2;
}

int main(){

  vector<int> arr={1,2,3,5,6,7,8,5,4};

    cout<<findDuplicate(arr);

  



  return 0;
}
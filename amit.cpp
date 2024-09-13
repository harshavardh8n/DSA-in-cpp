#include<iostream>
#include<math.h>
#include <vector>
using namespace std;


int ispower7(int n){
    if(n%7!=0){
        return 0;
    }
    if(n==7){
        return 1;
    }
    int count = 1;
    int ans = 7;
    while(n>ans){
        ans = ans*7;
        count++;
        if(ans==n){
            return count;
        }

    }
    return 0;
}
int main()
{
    // int[] arr = {343, 1, 7, 14, 56, 49, 20, 17, 43, 70};
    vector<int>newone{343, 1, 7, 14, 56, 49, 20, 17, 43, 70};
    // int n = 7;

    // 343  3
    // 49   2

    for(int i=0;i<newone.size();i++){
        if(ispower7(newone[i])!=0){
            cout<<newonwispower7(newone[i]);
        }
    }
    // cout<<ispower7(49);
    return 0;
}
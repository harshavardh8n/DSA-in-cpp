#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<int> a={1,3,6,9};
    cout<<a.size();
    vector<int> reversed(4);
    int n = a.size();
    // for(int i=0;i<n;i++){
    //     reversed[i] = a[n-i-1];
    //     cout<<"working "<<i;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<reversed[i];
    //     cout<<"working";
    // }
    // reversed[0]=a[n-1];
    // cout<<reversed[0];
    for (int i = 0; i < n; i++)
    {
        /* code */
        a[i]=(i+2)%n;
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
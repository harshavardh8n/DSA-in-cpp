#include <iostream>
using namespace std;

int main(){
    // int n=3;
    // int arr[] = {1,64};
    // for(int i=0;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }
    
// --------------------------------------------
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int f;
    cout<<"Element to find";
    cin>>f;

    // for (int i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<"element"<<i+1<<endl;
    // }

    // this is for displaying array 

    // ===========================================

    // for (int i = 0; i < n; i++)
    // {
    //     if(arr[i]==f){
    //         cout<<"element found at "<<i+1<<" position";
    //     }
    // }

    //this is linear search

    // ------------------------------------------------

    int left,right,middle;
    left = 0;
    right = n-1;
    // cout<<left<<right;
    for(int i=0;i<n;i++){
        middle = (left+right)/2;
        // cout<<middle;
        if(f==arr[left]){
            cout<<arr[left]<<" is found at :"<<left;
            break;
        }
        else if(f==arr[right]){
            cout<<arr[right]<<" is found at :"<<right;
            break;
        }
        if(arr[middle]==f){
            cout<<arr[middle]<<" is found at :"<<middle;
            break;
        }
        else if(arr[middle]<f){
            right = middle-1;
        }
        else if(arr[middle]>f){
            left = middle+1;
        }
    }
    
    

    return 0;

}
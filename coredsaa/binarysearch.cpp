#include<iostream>
#include<vector>
using namespace std;

int pivot(vector<int>arr){
    int s = 0;
    int n = arr.size();
      int e = n-1;
    int mid = s+(e-s)/2;
    while(s<e){
        // if(arr[mid]<arr[mid-1]){
        //     return mid;
        // }
        if(arr[mid]>=arr[0]){
            s = mid+1;
            cout<<"s :"<<s<<endl;

        }

        else{
            e = mid;
            cout<<"e:"<<e<<endl;
        }

        mid = s+(e-s)/2;
        cout<<"mid: "<<mid<<endl;
    }
    cout<<"pivot is: "<<e;
    return e;
}


int binarysearch(vector<int> arr, int k, int start, int end) {
    int s = start;
    int e = end;
    int mid = s + (e - s) / 2;

    while (s <= e) { // Fixed the condition
        if (arr[mid] == k) {
            return mid;
        }
        if (arr[mid] < k) {
            s = mid + 1; // Fixed the update for s
        } else {
            e = mid - 1; // Fixed the update for e
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}


// int binarySearch(vector<int>arr,int k){
//     int l = 0;
//     int r = arr.size()-1;
//     int middle =l+(r-l)/2;
//     while(l<=r){
//         if(arr[middle]==k){
//             // cout<<arr[middle]<<endl;
//             return middle;
//         }
//         if(arr[middle]>k){
//             l = middle+1;
//             // cout<<arr[l]<<endl;
//         }
//         else if(arr[middle]<k){
//             r = middle-1;
//             // cout<<arr[r]<<endl;
//         }
//         middle = (l+r)/2;
//         // cout<<middle<<endl;
//     }
//     return -1;
// }
  

int recursive_binarysearch(vector<int>array,int key,int s,int e){

    //element not found
    if(s>e){
        return -1;
    }

     int mid = s+(e-s)/2;

    //element found
    if(array[mid]==key){
        return mid;
    }
   

    if(array[mid]<key){
        return recursive_binarysearch(array,key,mid+1,e);
    }
    else{
        return recursive_binarysearch(array,key,s,mid-1);
    }

}

int main()
{
  vector<int> array = {11 ,13, 5 ,8 ,9, 10 };
//   int res = binarySearch(array,1);
    //   int res = pivot(array);
    //   int bin = binarysearch(array,9,res,5);
        int bin = recursive_binarysearch(array,9,0,5);
  cout<<bin;
  return 0;
}
    #include<iostream>
    using namespace std;


    void swapalternate(int arr[],int length){

        for(int i=0;i<length;i=i+2){
        if(i+1<length){
            swap(arr[i],arr[i+1]);
        }
        }
    }

    void printarray(int arr[],int length){

        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }

    }
    int main()
    {
        int arr[]= {1,3,4,6,4,6};
        int length = sizeof(arr)/sizeof(arr[0]);
        // int length = end(arr)-begin(arr);

        swapalternate(arr,length);
        printarray(arr,length);
        

        

        return 0;
    }
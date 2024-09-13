#include <iostream>
using namespace std;

int main(){

    char c;
    cin>>c;
    if (c>=65 && c<=90)
    {
        /* code */
        cout<<"uppercase";
    }
    // if(97<=c<=122){
    //     cout<<"lowercase";
    // }
    else if (c>=97 && c<=122)
    {
        /* code */
        cout<<"uppercase";
    }

    else if (c>=48 && c<=57)
    {
        /* code */
        cout<<"number";
    }
    // else if(48<=c<=57){
    //     cout<<"number";
    // }
    
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    // int n;
    // cin>>n;
    // char c = 'A';
    // for(int i=1;i<=n;i++){

    //     for(int j=1;j<=n;j++){
    //         cout<<c++<<" ";

    //     }
    //     cout<<endl;
    // }
    //pattern for A B C
            //   D E F
            //   G H I

// ----------------------------------------------

    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++){

    //     for(int j=1;j<=n;j++){
    //         char c = 'A'+j-1+i-1;
    //         cout<<c;

    //     }
    //     cout<<endl;
    // }

    // to print
    // ABC 
    // BCD 
    // CDE 
// =========================================================

int n;
    cin>>n;
    char a = 'A';
    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){
            // char c = 'A'+i-1+j-1;
            cout<<a++;

        }
        cout<<endl;
    }

    return 0;
}
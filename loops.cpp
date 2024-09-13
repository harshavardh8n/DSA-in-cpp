#include <iostream>
using namespace std;
int main(){

    bool candrive;
    int age;
    cout<<"ENter age";
    cin>>age;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<"Hello"<<endl;
    // }

    if(age>=18){
        candrive = true;
    }
    else{
        candrive = false;
    }

    if(candrive){
        cout<<"you can have license";
        return 0;
    }

    cout<<"you cannot have license";




    return 0;
}

#include<iostream>
using namespace std;
int main()

{
    int x = 1;
    int count = 0;


    while(x<60 && x>0){
        x++;
        count++;
        cout<<"loop running"<<count<<endl;
        
    }
    return 0;
}
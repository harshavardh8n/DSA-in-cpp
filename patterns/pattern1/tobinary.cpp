#include <iostream>
using namespace std;

string toBinary(int n){

    string verse="";
    while(n>0){
        int bit=n%2;
        verse+=to_string(bit);
        n = n/2;

    }
    string binary="";
    // cout<<verse.length();
    for (int i = verse.length()-1; i >= 0; i--)
    {
        binary+=verse[i];
    }

    
    // cout<<verse<<endl;

    return binary;
}

int main(){

    int number;
    cin>>number;
    
    cout<<toBinary(number);
    // verse+= to_string(n);
    // cout<<verse;



    return 0;
}
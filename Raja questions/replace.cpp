#include<iostream>
using namespace std;


void replacer(string &s){
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            s[i]='%';
        }
    }
}
int main()
{

    string s = "I want to work for Raja Software Labs";
    replacer(s);
    cout<<s;

    return 0;

}

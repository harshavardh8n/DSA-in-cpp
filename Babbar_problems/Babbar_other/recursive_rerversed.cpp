#include<iostream>
using namespace std;
string recursive_String_reverse(string s,int l, int e){
    if(l>e){
        return s;
    }
    swap(s[l],s[e]);
    return recursive_String_reverse(s,l+1,e-1);

}
int main()
{
    string s = "nahdravahsrah";
    string reversed = recursive_String_reverse(s,0,s.size()-1);

    cout<<reversed;
    return 0;
}
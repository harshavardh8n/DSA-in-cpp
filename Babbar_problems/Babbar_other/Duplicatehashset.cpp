#include<iostream>
#include<set>
#include<vector>
using namespace std;

int findDuplicate(vector<int> &arr){
    set<int>s;
    for(int i:arr){
       if( s.find(i)!=s.end()){
        return i;
       }
       s.insert(i);
    }
    return 0;


}
int main()
{
    vector<int> v = {1,3,4,5,7,3};
    cout<<findDuplicate(v);
    // set<int> s;
    // for(int i=0;i<v.size();i++){
    //     s.insert(v[i]);
    //     cout<<v[i]<<endl;
    // }
    // s.insert(1);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);
    // s.insert(7);
    // s.insert(3);

    // for(int i:s){
    //     cout<<i;
    // }
    // return s.end()!=4;



    return 0;
}
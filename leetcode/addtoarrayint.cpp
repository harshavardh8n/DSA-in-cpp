#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int calcpower(int base, int index){
        for(int i=0;i<index;i++){
            base = base*base;
        }
        return base;
    }
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> newarray;
        int number = 0;
        int n=num.size();
        for(int i=0;i<n;i++){
           
            // cout<<"iter for "<<i<<": "<<calc;
            int factor = calcpower(10,(n-i-1));
            // cout<<"for iteration"<<i<<pow(10,(n-i-1));
            int multiplier = num[i]*factor;
            cout<<num[i]<<" "<<multiplier<<endl;
            // cout<<pow(10,(2))<<endl;
            
            number=number+multiplier;
            cout<<"factor at"<<i<<"is "<<factor<<" "<<number<<endl;
        }
        // cout<<number<<endl;
        number = number+k;
        cout<<number<<endl;

        for(int i=0;i<n;i++){
            int digit = number%10;
            newarray.push_back(digit);
            number=number/10;
        }
        reverse(newarray.begin(),newarray.end());
        return newarray;
    }
};

int main()
{
    Solution s;
    vector<int>array = {1,2,0,0};
    vector<int>newarray=s.addToArrayForm(array,34);
    for(int i=0;i<newarray.size();i++){
        cout<<newarray[i];
    }

    cout<<s.calcpower(10,2)<<endl;
    cout<<s.calcpower(10,3)<<endl;
    cout<<s.calcpower(10,1)<<endl;


    return 0;
}
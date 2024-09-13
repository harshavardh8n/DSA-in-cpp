#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> duplicate;
        for(int i=0;i<n;i++){
            int ind = abs(nums[i])-1;
            if(nums[ind]>0){
                nums[ind] = -nums[ind];
            }
            else if(nums[ind]<0){
                duplicate.push_back(abs(nums[i]));
            }
        }

        return duplicate;
    }
};

int main(){

    Solution sol;

    // Define an input vector with some duplicates
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    // Find duplicates
    vector<int> duplicates = sol.findDuplicates(nums);

    // Print the result
    cout << "Duplicates in the array: ";
    for(int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
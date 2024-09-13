#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<=nums.size();i++){
            for(int j=i+1;j<=nums.size();j++){
                if(nums[i]==nums[j]){
                    cout<<i<<"and"<<j;
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){

    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 1};
    bool result1 = solution.containsDuplicate(nums1);
    cout << "Test case 1: " << (result1 ? "Contains duplicates" : "No duplicates") << endl;

    // // Test case 2
    // vector<int> nums2 = {1, 2, 3, 4};
    // bool result2 = solution.containsDuplicate(nums2);
    // cout << "Test case 2: " << (result2 ? "Contains duplicates" : "No duplicates") << endl;

    // // Test case 3
    // vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    // bool result3 = solution.containsDuplicate(nums3);
    // cout << "Test case 3: " << (result3 ? "Contains duplicates" : "No duplicates") << endl;

}
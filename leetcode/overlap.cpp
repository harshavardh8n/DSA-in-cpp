#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged = intervals;
        vector<vector<int>> newmerged;
        sort(merged.begin(),merged.end(),[](const vector<int>&a,const vector <int> &b){
            return a[0]<b[0];
        });

        for(int i=0;i<merged.size();i++){
            // for(i)
                cout<<"fffbf";
                if(merged[i][1]<=merged[i+1][1]){
                    cout<<"dskjdhk";
                    if(merged[i][1]>merged[i+1][1]){
                        continue;
                    }
                    newmerged.push_back({merged[i][0],merged[i+1][1]});
                    cout<<"["<<newmerged[i][0]<<","<<newmerged[i][1]<<"]";
                }
                // i++;

                else{  
                newmerged.push_back({merged[i][0],merged[i][1]});
                cout<<"["<<newmerged[i][0]<<newmerged[i][1]<<"]";
            }
            // cout<<merged[i][0],merged[i][1];
            // return newmerged;
        }


        return newmerged;

    }
};

int main(){

    Solution solution;
    vector<vector<int>> arraye = {{1,3},{5,6},{3,10},{15,18}};
    // cout<<arraye.size()<<"here";
    
    vector<vector<int>> result =solution.merge(arraye);

    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;


    return 0;
}

// int main() {
//     Solution solution;
//     vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
//     vector<vector<int>> result = solution.merge(intervals);
    
//     cout << "Merged intervals: " << endl;
//     for (const auto& interval : result) {
//         cout << "[" << interval[0] << ", " << interval[1] << "] ";
//     }
//     cout << endl;
    
//     return 0;
// }
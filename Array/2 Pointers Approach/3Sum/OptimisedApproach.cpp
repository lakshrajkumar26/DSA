#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find where a+b+c=0;
where ith != jth != kth

    class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
       

         vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; //  check and continue that loop
            }
            int j = i + 1;
            int k = n - 1;

            while (j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else { // match

                    ans.push_back({nums[i] , nums[j] , nums[k] });
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;    // for left side 11111
                    } // check why 
                      
                     while (j < k && nums[k] == nums[k + 1]) {
                        k--;   //for right side 2222
                    } // check why      {without this loop also can work but jsut to be more optimised}
                    
                }
            }
        }

        return ans;
        
    }
};

// Driver code
int main()
{

    Solution s;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = s.threeSum(nums);

    cout << "Answer:\n";

    for (auto vec : result)
    {

        cout << "[ ";

        for (auto x : vec)
        {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}
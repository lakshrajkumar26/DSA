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
         set<vector<int>>s;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        // We need ONLY unique triplets
                        // so we use SET.

                        // Before this, array is SORTED.
                        // Then every valid triplet is also stored in sorted order.

                        // Because of sorting:
                        // {-1,0,1} , {1,-1,0} , {0,1,-1}
                        // all become {-1,0,1}

                        // SET stores only unique values,
                        // so duplicate triplets are automatically removed.

                        // We use set instead of unordered_set because:
                        // unordered_set cannot directly store vector<int>
                        // easily with default hashing.

                        // Also set keeps elements sorted automatically.
                        
                        vector<int> triplet = {nums[i] , nums[j] , nums[k]};
                         
                        sort(triplet.begin(), triplet.end());

                        if(s.find(triplet) == s.end()) {
                            s.insert(triplet);
                            ans.push_back(triplet)
                        }

                        }

                    }
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
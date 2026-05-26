#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find where a+b+c=0;
// where ith != jth != kth

    class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        set<vector<int>> uniqueTriplet;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            int tar = -nums[i];
            set<int> s;
            for (int j = i + 1; j < n; j++)
            {

                int third = tar - nums[j];
                if (s.find(third) != s.end())
                {
                    vector<int> triplet = {nums[i], nums[j], third};

                    sort(triplet.begin(), triplet.end());
                    uniqueTriplet.insert(triplet);
                }

                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(uniqueTriplet.begin(), uniqueTriplet.end());

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
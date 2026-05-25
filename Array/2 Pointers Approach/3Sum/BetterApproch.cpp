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
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        vector<int> ans;
        list<int> l;

        int i = 0;
        int j = 0;
        int n = arr.size();

        while (j < n) {

            if (arr[j] < 0) {
                l.push_back(arr[j]);
            }

            if (j - i + 1 == k) {

                if (!l.empty()) {
                    ans.push_back(l.front());
                }
                else {
                    ans.push_back(0);
                }

                if (!l.empty() && l.front() == arr[i]) {
                    l.pop_front();
                }

                i++;
                j++;
            }

            else {  // window size < k
                j++;
            }
        }

        return ans;
    }
};

int main() {

    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    Solution obj;

    vector<int> result = obj.firstNegInt(arr, k);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
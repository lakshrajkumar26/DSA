# Maximum Sum of Subarray of Size K

## Problem
Given an array `arr[]` and an integer `k`, find the **maximum sum of any contiguous subarray of size `k`**.

---

## Approach: Sliding Window

Instead of checking every subarray (which would take **O(n*k)** time), we use the **Sliding Window Technique**.

### Idea
- Maintain a window of size `k`.
- Keep track of the **sum of elements inside the window**.
- Slide the window by removing the first element and adding the next element.

---

## Algorithm

1. Initialize:
   - `i = 0` → start of window
   - `j = 0` → end of window
   - `sum = 0`
   - `maxi = INT_MIN`

2. Traverse the array using `j`.

3. Add `arr[j]` to `sum`.

4. If window size becomes `k`:

j - i + 1 == k


5. Update maximum sum:

maxi = max(maxi, sum)


6. Slide the window:
- Remove `arr[i]` from `sum`
- Increment `i`

7. Move `j` forward.

---

## Dry Run Example

Input:


arr = [2,1,5,1,3,2]
k = 3


Subarrays of size `3`:


[2,1,5] → sum = 8
[1,5,1] → sum = 7
[5,1,3] → sum = 9 ← maximum
[1,3,2] → sum = 6


Output:


9


---

## Time Complexity


O(n)


Each element is added and removed from the window **at most once**.

---

## Space Complexity


O(1)


No extra space is used.

---

## C++ Implementation

```cpp
class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;

        while (j < n) {
            sum += arr[j];

            if (j - i + 1 == k) {
                maxi = max(maxi, sum);
                sum -= arr[i];
                i++;
                j++;
            } 
            else {
                j++;
            }
        }

        return maxi;
    }
};
Key Takeaways

Sliding Window is useful for problems involving contiguous subarrays.

Works best when the window size is fixed.

Reduces time complexity from O(n*k) → O(n).
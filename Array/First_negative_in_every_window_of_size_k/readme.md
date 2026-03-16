# First Negative Integer in Every Window of Size K

## Problem Statement
Given an array `arr[]` of size `N` and a window size `K`, find the **first negative integer in every contiguous subarray (window) of size `K`**.

If a window does not contain a negative integer, return `0` for that window.

---

## Example

**Input**

arr = [-8, 2, 3, -6, 10]  
k = 2

**Output**

[-8, 0, -6, -6]

**Explanation**

| Window | First Negative |
|------|------|
[-8, 2] | -8 |
[2, 3] | 0 |
[3, -6] | -6 |
[-6, 10] | -6 |

---

## Approach

This problem is solved using the **Sliding Window Technique**.

### Key Idea
1. Maintain a window of size `K`.
2. Use a **list (or deque)** to store negative numbers inside the window.
3. As the window slides:
   - Add negative elements when encountered.
   - If the window size becomes `K`, record the first negative.
   - Remove elements that leave the window.

---

## Algorithm Steps

1. Initialize two pointers `i` and `j` for the window.
2. Traverse the array using `j`.
3. If `arr[j]` is negative, store it in the list.
4. When window size becomes `K`:
   - If list is not empty → push `front()` to result.
   - Otherwise → push `0`.
5. Before sliding the window:
   - If the outgoing element equals the first negative, remove it from the list.
6. Slide the window by incrementing `i` and `j`.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {

        vector<int> ans;
        list<int> l;

        int i = 0, j = 0;
        int n = arr.size();

        while (j < n) {

            if (arr[j] < 0) {
                l.push_back(arr[j]);
            }

            if (j - i + 1 == k) {

                if (!l.empty())
                    ans.push_back(l.front());
                else
                    ans.push_back(0);

                if (!l.empty() && l.front() == arr[i]) {
                    l.pop_front();
                }

                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return ans;
    }
};
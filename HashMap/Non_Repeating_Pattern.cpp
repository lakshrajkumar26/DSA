#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    char nonRepeatingChar(string &s) {
        unordered_map<char,int> freq;
        
        // Count frequency
        for(char ch : s){
            freq[ch]++;
        }
        
        // Find first non-repeating character
        for(char x : s){
            if(freq[x] == 1){
                return x;
            }
        }
        
        return '$'; // if none found
    }
};

int main() {
    Solution obj;
    
    string s;
    cin >> s;
    
    char result = obj.nonRepeatingChar(s);
    cout << result << endl;
    
    return 0;
}
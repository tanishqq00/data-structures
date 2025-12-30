#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Buckets where index = frequency
        int n = s.size();
        vector<vector<char>> buckets(n + 1);

        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        // Step 3: Build result
        string ans = "";
        for (int i = n; i >= 1; i--) {
            for (char c : buckets[i]) {
                ans.append(i, c);  // add character i times
            }
        }

        return ans;
    }
};

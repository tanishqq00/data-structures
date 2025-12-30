#include <bits/stdc++.h>
using namespace std;


void backtrack(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);
    for (int i = start; i < nums.size(); i++) { // Use <, not <=
        // Skip duplicates: i > start ensures we don't go out of bounds on nums[i-1]
        if (i > start && nums[i] == nums[i-1]) continue; 
        
        path.push_back(nums[i]);
        backtrack(nums, i + 1, path, res);
        path.pop_back();
    }
}
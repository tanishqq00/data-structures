#include <bits/stdc++.h>
using namespace std;


class Solution{
    
private:
     void findcombination(int idx, int target,vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        int n= arr.size();
        if (target == 0) {
    ans.push_back(ds);
    return;
}

    
    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1]) continue;

        if(arr[i]>target) break;

        ds.push_back(arr[i]);
        findcombination(i+1,target-arr[i],arr,ans,ds);
        ds.pop_back();

    }
       
}
public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());

            vector<vector<int>> ans;
            vector<int> ds;
            findcombination(0,target,candidates,ans,ds);
            return ans;
        
    }

};  
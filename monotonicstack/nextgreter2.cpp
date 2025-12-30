#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   
    vector<int> bruteforce(vector<int>nums){
       
        int n= nums.size();
        vector<int> arr;

        for(int i=0;i<n;i++){
            bool flag=false; 
            for(int j=i+1;j<i+n;j++){
                int idx=j%n;
                if(nums[idx]>nums[i]){
                    arr.push_back(nums[idx]);
                    flag=true;
                    break;
                }

            }
            if(!flag) arr.push_back(-1);
        }
        return arr;
    }

};

int main(){
    Solution sol;
    vector<int> arry={1,2,3,4,5};

    vector<int> ans=sol.bruteforce(arry);

    for(int i=0;i<ans.size();i++){
        
      cout<<ans[i]<<" ";
    }

    return 0;

}

class solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) { // optimal
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = 2*n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while(!st.empty() && st.top() <= curr)
                st.pop();

            if(i < n && !st.empty())
                ans[i] = st.top();

            st.push(curr);
        }
        return ans;
    }
};

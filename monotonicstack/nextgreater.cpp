#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

     vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();

        
        
    }
public:
    
    vector<int> nextgreater(vector<int>&arr,int n) {
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            
            int curr=arr[i];
            
            for(int j=1;j<n;j++){
                int ind=(i+j)%n;

                if(arr[ind]>curr){
                    ans[i]=arr[ind];

                    break;

                }
             }
        }
      return ans;
   }
};

int main(){
    Solution solution;
    vector<int> arr={1,2,3,4,3};
    int n= arr.size();
    vector<int> ans =solution.nextgreater(arr,n);

    for(int i=0;i<n;i++){
        cout<<ans[i]<<",";

        
    }
    vector<int> answ = solution.nextGreaterElements(arr);
}
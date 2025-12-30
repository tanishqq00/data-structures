#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();

        int maxi=INT_MIN;
        int area=0;

        for(int i=0;i<n;i++){
            int minheight=heights[i];
            for(int j=i;j<n;j++){
               
                minheight=min(minheight,heights[j]);
                area= minheight*(j-i+1);
                maxi=max(area,maxi);
            }
        }
        return maxi;
    }
};

int main(){
    Solution sol; //object sol of class Solution
    vector<int>heights={2,1,5,6,2,3};
    cout<<sol.largestRectangleArea(heights);

}
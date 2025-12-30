#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        int sum=0;
        int MOD=1e9+7;

        for(int i=0;i<n;i++){
            int mini=arr[i];
            for(int j=i;j<n;j++){
                mini=min(mini,arr[j]);
                sum=(sum+mini)%MOD;
            }
        }
        
        return sum;
    }

};

int main(){
    
}

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> prev(n), next(n);
        stack<int> st;

        // 1️⃣ Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Clear stack
        while (!st.empty()) st.pop();

        // 2️⃣ Next Smaller Element (smaller or equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // 3️⃣ Calculate result
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;

            ans = (ans + arr[i] * left % MOD * right % MOD) % MOD;
        }

        return ans;
    }
};

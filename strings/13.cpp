#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, int> roman = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};


public:
    
    int romanToInt(string s) {
        int ans=0;

        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&roman[s[i]]<roman[s[i+1]]) {
                ans-= roman[s[i]];
                }
            
            else {
                ans+=roman[s[i]];
                }

        }
        return ans;
    }
};

int main(){
    Solution sol; //object

    string s = "MCMXCIV";
    int result= sol.romanToInt(s);
    cout<<result<<endl;

    return 0;
    

}
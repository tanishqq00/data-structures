#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(vector<vector<char>>& board, string &word,int r,int c,int i){
       
        if(i==word.length()) return true;


        

        if(r>=board.size()||c>=board[0].size()||r<0||c<0||board[r][c]!=word[i]){
            return false;
              }
       
        char temp = board[r][c];   // save original
        board[r][c] = '#';
      
        bool res= 
                  dfs(board,word,r+1,c,i+1)||
                  dfs(board,word,r-1,c,i+1)||
                  dfs(board,word,r,c+1,i+1)||
                  dfs(board,word,r,c-1,i+1);

            board[r][c]=temp; //to avoid perma blocking and explore path with diffrent starting points
            

        return res;

    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(dfs(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
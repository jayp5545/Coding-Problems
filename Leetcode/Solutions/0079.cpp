class Solution {
public:
    bool solve(int i,int j,vector<vector<char>> &board,string word,int k){
      if(k==word.size()) return true;
      if(i==board.size() || j==board[0].size() || i==-1 ||j==-1 || board[i][j]!=word[k]) return false;
      char ch=board[i][j];
      board[i][j]='#';
      bool op1=solve(i+1,j,board,word,k+1);
      bool op2=solve(i,j+1,board,word,k+1);
      bool op3=solve(i-1,j,board,word,k+1);
      bool op4=solve(i,j-1,board,word,k+1);
      board[i][j]=ch;
      return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
          for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){
              if(solve(i,j,board,word,0)) return true;
            }
          }
        }
        return false;
    }
};
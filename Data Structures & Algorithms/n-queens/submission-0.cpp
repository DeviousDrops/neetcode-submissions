class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.')); 
        vector<vector<string>> res;
        unordered_set<int> diag;
        unordered_set<int> adiag;
        unordered_set<int> cols;
        for(int p=0;p<n;p++)
            dfs(n,0,p,board,adiag,diag,cols,res);
        return res;
    }
    void dfs(int n, int r, int c, vector<string>& board,unordered_set<int>& adiag, unordered_set<int>& diag, unordered_set<int>& cols,vector<vector<string>>& res){
        if(r==n){
            res.push_back(board);
            return;
        }
        if(adiag.find(c-r)!=adiag.end() || cols.find(c)!=cols.end() || diag.find(c+r)!=diag.end()){
            return;
        }
        board[r][c]='Q';
        cols.insert(c);
        adiag.insert(c-r);
        diag.insert(c+r);
        if(r==n-1)
            dfs(n,r+1,c,board,adiag,diag,cols,res);  
        else{  
        for(int k=0;k<n;k++)
            dfs(n,r+1,k,board,adiag,diag,cols,res);
        }
        cols.erase(c);
        adiag.erase(c-r);
        diag.erase(c+r);
        board[r][c]='.';
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_set<int> s;
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0' || s.find(i*n+j)!=s.end())
                    continue;
                dfs(grid,s,i,j,m,n);
                ans++;
            }
        }  
        return ans;  
    }

    void dfs(vector<vector<char>>& grid, unordered_set<int> &s, int i, int j, int m, int n){
        if(i<0||j<0||i>=m||j>=n||grid[i][j]=='0'||s.find(i*n+j)!=s.end())
            return;
        s.insert(i*n+j);
        dfs(grid,s,i+1,j,m,n);
        dfs(grid,s,i,j+1,m,n);
        dfs(grid,s,i-1,j,m,n);
        dfs(grid,s,i,j-1,m,n);
    }
};
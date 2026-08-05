class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        deque<pair<int,int>> q;
        int f=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push_back({i,j});
                else if(grid[i][j]==1)
                    f++;
            }
        }  
        if(f==0)
            return 0;  
        int c=0;
        int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int sz=q.size();
            for(int t=0;t<sz;t++){
            auto it=q.front();
            q.pop_front();
            int x=it.first,y=it.second;
            for(int l=0;l<4;l++){
                int o=x+dir[l][0],p=y+dir[l][1];
                if(o>=0&&p>=0&&o<m&&p<n&&grid[o][p]==1){
                    grid[o][p]=2;
                    q.push_back({o,p});
                    f--;
                }
            }
            }
            c++;
        }
        return f==0?c-1:-1;
    }
};
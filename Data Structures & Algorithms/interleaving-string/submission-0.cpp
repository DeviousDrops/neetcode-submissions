class Solution {
public: 
    bool dfs(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& memo){
        if(memo[i][j]!=-1)
            return memo[i][j];
        bool i1=false,j1=false;
        if(s1[i]==s3[i+j])
            i1=dfs(i+1,j,s1,s2,s3,memo);
        if(s2[j]==s3[i+j])
            j1=dfs(i,j+1,s1,s2,s3,memo);
        memo[i][j]= i1 || j1;
        return memo[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
       vector<vector<int>> memo(s1.size()+1,vector<int>(s2.size()+1,-1));
       memo[s1.size()][s2.size()]=1;
       return dfs(0,0,s1,s2,s3,memo); 
        
    }
};
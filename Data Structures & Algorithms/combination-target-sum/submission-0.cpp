class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> s;
        dfs(candidates,target,0,s,0,res);
        return res;
    }
    void dfs(vector<int>& c, int& target, int sum, vector<int>& s, int i,vector<vector<int>>& res)
    {   
        if(sum==target){
            res.push_back(s);
            return;
        }
        else if(sum>target||i==c.size()){
            return;
        }
        s.push_back(c[i]);
        sum+=c[i];
        dfs(c,target,sum,s,i,res);
        sum-=c[i];
        s.pop_back();
        if(i+1!=c.size()&&c[i+1]==c[i])
            i++; 
        dfs(c,target,sum,s,i+1,res);

    }
};
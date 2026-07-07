class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> s;
        int len=1;
        for(int i=1;i<=nums.size();i++){
            len*=i;
        }
        unordered_set<int> o;
        dfs(res,s,nums,o);    
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& s, vector<int>& nums, unordered_set<int>& o){
        if(s.size()==nums.size()){
            res.push_back(s);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(o.find(nums[j])==o.end())
           { s.push_back(nums[j]);
                o.insert(nums[j]);
            dfs(res,s,nums,o);
            s.pop_back();
            o.erase(nums[j]);
            }
        
        }
    }
};
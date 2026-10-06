class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int i=0;
        vector<vector<int>> res;
        int m;
        while(i<in.size()){
            vector<int> next(2);
            m=in[i][1];
            next[0]=in[i++][0];
            while(i<in.size() && m>=in[i][0]){
                m=max(m,in[i][1]);
                i++;
            }
            next[1]=m;
            res.push_back(next);
        }      
        return res;
    }
};
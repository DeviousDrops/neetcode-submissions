class Solution {
public:
    void setZeroes(vector<vector<int>>& x) {
        unordered_set<int> r;
        unordered_set<int> c;
        int m=x.size();
        int n=x[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!x[i][j]){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(r.find(i)!=r.end() || c.find(j)!=c.end())
                    x[i][j]=0;
            }
        } 
    }
};
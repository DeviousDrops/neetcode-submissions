class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int c=0;
        int m=in[0][1];
        for(int i=1;i<in.size();i++){
            if(in[i][0]<m){
                c++;
                m=min(m,in[i][1]);
            }
            else
                m=in[i][1];
        }    
        return c;
    }
};
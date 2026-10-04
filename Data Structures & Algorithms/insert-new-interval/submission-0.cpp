class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i=0;
        while(i<interval.size() && interval[i][1]<newInterval[0]){
            res.push_back(interval[i]);
            i++;
        }
        if(res.size()==interval.size()){
            res.push_back(newInterval);
            return res;
        }
        int start=min(interval[i][0],newInterval[0]);
        while(i<interval.size() && interval[i][0] <= newInterval[1]){
            i++;
        }
        int end;
        if(i==0)
            end=newInterval[1];
        else
            end=max(interval[i-1][1],newInterval[1]);
        res.push_back({start,end});
        while(i<interval.size()){
            res.push_back(interval[i]);
            i++;
        }
    return res;
    }
};
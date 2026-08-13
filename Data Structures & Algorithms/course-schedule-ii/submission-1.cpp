class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mp;
        vector<int> in(numCourses,0);
        for(int i=0;i<pre.size();i++){
            mp[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }        
        deque<int> q;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push_back(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
                int k=q.front();
                q.pop_front();
                for(int j:mp[k]){
                    if(!--in[j])
                    {
                        q.push_back(j);
                        res.push_back(j);
                    }
                }
            

        }
        if(res.size()==numCourses)
            return res;
        else
            return {};
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }    
        priority_queue<pair<int,int>> q;
        q.push({0,k});
        unordered_set<int> v;
        int c=0;
        int p,d,t;
        while(!q.empty()){
            p=q.top().second;
            if(v.find(p)!=v.end()){
                q.pop();
                continue;
            }
            d=-q.top().first;
            q.pop();
            v.insert(p);
            c++;
            
            for(auto &o:adj[p]){
                if(v.find(o.first)!=v.end())
                    continue;
                t=d+o.second;
                q.push({-t,o.first});
            }
        }
        if(c==n)
            return d;
        return -1;
    }
};

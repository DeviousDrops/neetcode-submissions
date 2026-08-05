class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        unordered_map<int,vector<int>> mp;  
        unordered_map<int,int> in; 
        for(vector<int> i:p){
            mp[i[1]].push_back(i[0]);
            in[i[0]]++;
        } 
        deque<int> q;
        for(int i=0;i<numCourses;i++){
            if(!in[i])
                q.push_back(i);
        }
        int c=0;
        while(!q.empty()){
            int k=q.front();
            q.pop_front();
            c++;
            for(int i:mp[k]){
                if(--in[i]==0)
                    q.push_back(i);
            }
        }
        return c==numCourses;
    }
};
class DSU{
    public:
        unordered_map<int,int> parent;
        int find(int x){
            while(parent[x]!=x){
                parent[x]=parent[parent[x]];
                x=parent[x];
            }
            return x;
        }
        bool un(int a, int b){
            int r1=find(a),r2=find(b);
            if(r1==r2)
                return true;
            parent[r2]=r1;
            return false;
        }
};




class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU* red=new DSU();
        for(int i=0;i<n;i++){
            if(!red->parent[edges[i][0]])
                red->parent[edges[i][0]]=edges[i][0];
            if(!red->parent[edges[i][1]])
                red->parent[edges[i][1]]=edges[i][1];
            if(red->un(edges[i][0],edges[i][1]))
                return edges[i];
        }    
        return {};
    }
};
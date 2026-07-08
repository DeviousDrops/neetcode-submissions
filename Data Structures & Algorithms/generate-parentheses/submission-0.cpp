class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> res;string k;
    dfs(n,0,0,res,k);        
    return res;
    }
    void dfs(int n,int open,int closed,vector<string>& res,string& k){
        if(open==n){
            string p=k;
            while(open!=closed){
                p+=")";
                closed++;
                }
            res.push_back(p);
            return;
        }
        k+="(";
        dfs(n,open+1,closed,res,k);
        k.pop_back();
        if(open>closed){
            k+=")";
            dfs(n,open,closed+1,res,k);
            k.pop_back();
        }
    }
};
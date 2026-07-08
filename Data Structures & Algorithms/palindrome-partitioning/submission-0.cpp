class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> st;
        string k="";
        dfs(s,k,0,st,res);
        return res;
    }
    void dfs(string& s,string& k,int i,vector<string>& st, vector<vector<string>>& res){
        if(i==s.size()){
            if(k=="")
                res.push_back(st);
            return;
        }
        k+=s[i++];
        while(!palindrome(k)&&i<s.size()){
            k+=s[i++];
        }
        if(i<s.size() || i==s.size()&&palindrome(k)){
            st.push_back(k);
            k="";
            dfs(s,k,i,st,res);
            k=st.back();
            st.pop_back();
            dfs(s,k,i,st,res);
        }
    }

    bool palindrome(string a){
        string b=a;
        reverse(a.begin(),a.end());
        return a==b;
    }
};
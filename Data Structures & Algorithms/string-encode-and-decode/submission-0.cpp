class Solution {
public:
    unordered_map<char,string> mp;
    string encode(vector<string>& strs) {
        string k="";
        for(int i=0;i<strs.size();i++){
            mp[static_cast<char>(i)]=strs[i];
            k.push_back(static_cast<char>(i));
        }
        return k;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        for(int i=0;i<s.size();i++){
            ans.push_back(mp[static_cast<char>(i)]);
        }
        return ans;
    }
};

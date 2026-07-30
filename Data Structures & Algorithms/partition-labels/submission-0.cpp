class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }    
        int r=mp[s[0]];
        vector<int> res;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(i==r){
                res.push_back(i+1-l);
                l=i+1;
                if(l<s.size())
                    r=mp[s[l]];
            }
            else if(mp[s[i]]>r){
                r=mp[s[i]];
            }
        }
        return res;
    }
};
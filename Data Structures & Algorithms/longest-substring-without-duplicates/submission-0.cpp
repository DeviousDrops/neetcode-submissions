class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]&&l<mp[s[i]]){
                l=mp[s[i]];                
            }
            mp[s[i]]=i+1;
            ans=max(ans,i-l+1);
        }    
        return ans;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        vector<int> freq(26,0);
        for(char c:s1)
            freq[c-'a']++;
        vector<int> ans(26,0);
        for(int i=0;i<s1.size();i++)
            ans[s2[i]-'a']++;
        if(ans==freq)
            return true;
        int l=0;
        for(int j=s1.size();j<s2.size();j++){
            ans[s2[l]-'a']--;
            l++;
            ans[s2[j]-'a']++;
            if(ans==freq)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        int m=0;
        for(char c:tasks){
            freq[c-'A']++;
            m=max(freq[c-'A'],m);
        }         
        int c=0;
        for(int i=0;i<26;i++){
            if(m==freq[i])
                c++;
        }
        int k=tasks.size();
        int ans=max(k,(m-1)*(n+1)+c);
        return ans;
    }
};
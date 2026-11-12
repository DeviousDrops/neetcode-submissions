class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++){
            int k=i;
            while(k){
                k=k&(k-1);
                c[i]++;
            }
        }    
        return c;
    }
};
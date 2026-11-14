class Solution {
public:
    int getSum(int a, int b) {
        int c=0;
        int res=0;
        for(int i=0;i<32;i++){
            int x=a&1;
            int y=b&1;
            a>>=1;
            b>>=1;
            res=res|(x^y^c)<<i;
            c=x&y|c&x|c&y;
        }    
        return res;
    }
};
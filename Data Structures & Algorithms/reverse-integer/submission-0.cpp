class Solution {
public:
    int reverse(long xx) {
        long sign=1;
        if(xx<0) sign=-1;
        long x=sign*xx;
        long res=0;
        while(x){
            int d=x%10;
            res=res*10+d;
            x=x/10;
        }    
        if(res>INT_MAX||res*sign<INT_MIN){
            return 0;
        }    
        return res*sign;
    }
};
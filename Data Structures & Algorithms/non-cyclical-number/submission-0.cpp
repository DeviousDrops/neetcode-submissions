class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> v;
        while(n!=1){
            int d=n;
            n=0;
            while(d>0){
                int k=d%10;
                n+=k*k;
                d=d/10;
            }
            if(v.find(n)!=v.end())
                return false;
            v.insert(n);
        }    
        return true;        
    }
};
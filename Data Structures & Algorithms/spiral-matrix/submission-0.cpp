class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& x) {
        int u=-1;int l=-1;
        int m=x.size(),n=x[0].size();
        vector<int>res(m*n);
        int i=0;
        int r=0,c=0;
        vector<int> d(2);
        d[0]=0;d[1]=1;
        int k=m*n;
        while(i<k){
            res[i]=x[r][c];
            if(c+d[1]==n){
                d[1]=0;
                d[0]=1;
                u++;
            }
            else if(c+d[1]==l){
                d[1]=0;
                d[0]=-1;
                m--;
            }
            else if(r+d[0]==m){
                d[1]=-1;
                d[0]=0;
                n--;
            }
            else if(r+d[0]==u){
                d[1]=1;
                d[0]=0;
                l++;
            }
            r=r+d[0];
            c=c+d[1];
            i++;
        }       
        return res;
    }
};

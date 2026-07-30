class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int c=0;
        int g=0;
        int n=gas.size();
        int j=0;
        int i=-1;
        while(i<j){
            i=j;
            g=0;
            c=0;
            int r=0;

            while(r<n && g-c>=0){
                g+=gas[j]-c;
                c=cost[j];
                j=(j+1)%n;
                r++;
            }
            if(j==i && g-c>=0)
                return i;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c=1;
        int i=digits.size()-1;
        while(c&&i>-1){
            if(digits[i]==9){
                digits[i]=0;
            }
            else{
            digits[i]++;
            c=0;
            }
            i--;
        }
        if(c)
            digits.insert(digits.begin(),1);
        return digits;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string k="";
        for(char c : s){
            if(isalnum(c)) 
                k+=tolower(c);
        } 

        s=k;  
        reverse(k.begin(),k.end());
        return k==s;
    }
};

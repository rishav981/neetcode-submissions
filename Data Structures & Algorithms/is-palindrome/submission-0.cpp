class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,h=s.size()-1;
        while(h>l){
            while(l<s.size() && h>l && !is_char(s[l])){
                l++;
            }
            while(h>=0 && h>l && !is_char(s[h])){
                h--;
            }
            if(h>l && toupper(s[l]) != toupper(s[h])){
                return false;
            }
            l++;h--; 
        }
        return true;
    }

    bool is_char(char c){
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>= '0' && c<='9')){
            return true;
        }
        return false;
    }
};

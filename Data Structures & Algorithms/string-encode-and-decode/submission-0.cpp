class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string en = "";
       for(auto& it : strs){
        en += to_string(it.size());
        en += '#';
        en += it;
       }
       return en;
    }

    vector<string> decode(string s) {
       vector<string> ans;
       int i = 0; 
       while(i<s.size()){
         int j = i;
         string len = "";
         while(s[j] != '#'){
            len += s[j];
            j++;
         }
         j++;
         int temp_size = stoi(len);
         ans.push_back(s.substr(j, temp_size));
         i=j+temp_size;
       }
       return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]] = 1;
        }
         int ans = 0;
        for(int i=0; i<n; i++){
            if(mp.count(nums[i]-1) == false){
                int cur = 0;
                int val = nums[i];
               while(mp.count(val)==true){
                    val++;
                    cur++;
               }
              ans = max(ans,cur);
            }
        }
        return ans;
    }
};

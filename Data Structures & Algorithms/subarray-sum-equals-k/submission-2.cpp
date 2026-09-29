class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=1; i<n; i++){
         nums[i] +=nums[i-1];
        }
        unordered_map<int,int> fre;
        int ans = 0;
        fre[0] = 1;
        for(int i=0; i<n; i++){
         if(fre[nums[i]-k]>0){
            ans += fre[nums[i]-k];
         }
         fre[nums[i]]++;
        }
        return ans; 
    }
};
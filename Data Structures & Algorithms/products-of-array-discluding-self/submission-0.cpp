class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int n = nums.size();
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
           for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]*nums[i];
           }
            
           for(int i = n-2; i>=0; i--){
            suffix[i] = suffix[i+1]*nums[i];
           }
         vector<int> ans(n);
         for(int i = 0; i<n; i++){
            if(i==0){
                ans[i]=suffix[i+1];
            }
            else if(i==n-1){
                ans[i]=prefix[i-1];
            }
            else{
            ans[i] = prefix[i-1]*suffix[i+1];
            }
         }
       return ans;
    }
};

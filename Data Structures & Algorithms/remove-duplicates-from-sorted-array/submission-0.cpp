class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        while(j+1<n){
            if(nums[j]!=nums[j+1]){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        swap(nums[i],nums[j]);
        i++;
        return i;
    }
};
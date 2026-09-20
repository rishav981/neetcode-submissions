class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<=h && nums[l]==0){
            l++;
        }
        while(h>=0 && nums[h]==2){
            h--;
        }

        for(int i = l; i<=h; i++){
            if(nums[i] == 0){
               swap(nums[i],nums[l]);
               l++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[h]);
                h--;
                i--;
            }
        }
        
    }
};
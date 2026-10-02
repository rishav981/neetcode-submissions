class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }

    void quick_sort(vector<int>& nums, int l, int h){
        if(l>=h){
            return;
        }
            
        int partition_index = partition(nums, l, h, l);

        quick_sort(nums,l,partition_index-1);
        quick_sort(nums,partition_index+1,h);
    }

    int partition(vector<int>& nums,int l,int h, int pivot){
        int index = l;  

        for(int i=l; i<=h; i++){
          if(nums[i]<nums[pivot]){
            index++;
            swap(nums[i],nums[index]);
          }
        }
        swap(nums[index],nums[pivot]);
       return index;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
         quick_sort(nums,0,nums.size()-1); 
         //   merge_sort(nums, 0, nums.size()-1);
         return nums;
    }
    
    void quick_sort(vector<int>& nums, int l, int h){
         if(l>=h){
            return;
         }
         int pivot = l;

         int pivot_index = partiton(nums,l,h,pivot);
         quick_sort(nums,l,pivot_index-1);
         quick_sort(nums,pivot_index+1,h);   
         
    }

    int partiton(vector<int>& nums, int l, int h, int pivot){
        int index = l;
        int pivotValue = nums[l];
        for(int i=l; i<=h; i++){
           if(nums[i]<pivotValue){
            index++;
            swap(nums[i],nums[index]);
           }
        }
        swap(nums[pivot],nums[index]);
        return index;
    }
    
    
    void merge_sort(vector<int>& nums, int l, int h){
        if(l>=h){
            return;
        }

        int m = (l+h)/2;

        merge_sort(nums,l,m);
        merge_sort(nums,m+1,h);


        merge(nums,l,m,h); 
    }

    void merge(vector<int>& nums, int l, int m, int h){
          int i = l;
          int j = m+1;
          vector<int> temp;
          while(i<=m && j<=h){
            if(nums[i] <= nums[j]){
               temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
          }
          while(i<=m){
            temp.push_back(nums[i]);
            i++;
          }
          while(j<=h){
            temp.push_back(nums[j]);
            j++;
          }
         for(int i=0; i<temp.size(); i++){
            nums[i+l] = temp[i];
         }
    }

};
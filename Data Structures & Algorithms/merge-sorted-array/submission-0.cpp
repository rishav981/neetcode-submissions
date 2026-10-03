class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = n + m - 1 ;
        m--;n--;
        while(n>=0 && m>=0){
            if(nums1[m]>nums2[n]){
              nums1[last] = nums1[m];
              m--;
              last--;
            }
            else{
                nums1[last] = nums2[n];
                n--;
                last--;
            }
        }
        while(n>=0){
            nums1[last] = nums2[n];
            n--;
            last--;
        }

    }
};
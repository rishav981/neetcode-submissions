class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MAX;
        int cnt_a=0;
        int cnt_b=0;
        
        int n = nums.size();
         if(n<2){
            return vector<int>() = {nums[0]};
         }
        for(int i=0; i<n; i++){
            if(nums[i]==a){
                cnt_a++;
            }
            else if(nums[i]==b){
                cnt_b++;
            }
            else if(cnt_a==0){
             a = nums[i];
             cnt_a=1;
            }
            else if(cnt_b==0){
                b =nums[i];
                cnt_b=1;
            }
            else{
                cnt_a--;
                cnt_b--;
            }
            }
     vector<int>ans;
     int cnt =0;
        for(int i=0; i<n; i++){
            if(nums[i] == a){
                cnt++;
            }
        }
        if(cnt>n/3){
          ans.push_back(a);
        }
        cnt=0;
       for(int i=0; i<n; i++){
            if(nums[i] == b){
                cnt++;
            }
        }
        if(cnt > n/3 ){
            if(a!=b){
        ans.push_back(b);
            }
        }
        return ans;
}
};
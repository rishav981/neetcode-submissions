class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int>mp;

       for(int i=0; i<n; i++){
        mp[nums[i]]++;
       } 

       priority_queue<pair<int,int>,vector<pair<int,int>>,          greater<pair<int,int>>>pq;
      
       for(auto it : mp){
        pq.push({it.second,it.first});
        if(pq.size()>k){
        pq.pop();
        }
       }

       vector<int> ans;

       while(pq.size()){
        pair<int,int> it = pq.top();
        pq.pop();
        ans.push_back(it.second);
       }

       return ans;
       
    }
};

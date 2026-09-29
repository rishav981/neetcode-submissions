class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        int cnt_a = 0, cnt_b = 0;
        int n = nums.size();

        // Find potential candidates
        for (int num : nums) {
            if (num == a) {
                cnt_a++;
            }
            else if (num == b) {
                cnt_b++;
            }
            else if (cnt_a == 0) {
                a = num;
                cnt_a = 1;
            }
            else if (cnt_b == 0) {
                b = num;
                cnt_b = 1;
            }
            else {
                cnt_a--;
                cnt_b--;
            }
        }

        // Verify candidates
        cnt_a = 0;
        cnt_b = 0;

        for (int num : nums) {
            if (num == a) {
                cnt_a++;
            }
            else if (num == b) {
                cnt_b++;
            }
        }

        vector<int> ans;

        if (cnt_a > n / 3) {
            ans.push_back(a);
        }

        if (cnt_b > n / 3) {
            ans.push_back(b);
        }

        return ans;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0;
        int one = 0, zero = 0;
        int ans = 0;

        for(int r = 0; r < n; ++r){
            if(nums[r] == 0) zero++;
            else one++;

            while(zero > k){
                if(nums[l] == 0) zero--;
                else one--;
                l++;
            }
            ans = max(ans, zero + one);
        }
        return ans;
    }
}; 
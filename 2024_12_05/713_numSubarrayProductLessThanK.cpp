class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k <= 1) return 0;
        
        int l = 0;
        long prod = 1;
        int ans = 0;

        for(int r = 0; r < n; ++r){
            prod *= nums[r];
            while(prod >= k){
                prod /= numsh[l];
                l++;
            }
            ans += r - l + 1;

        }
        return ans;
        
    }
};
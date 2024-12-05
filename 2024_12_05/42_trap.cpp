class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;
        int prev_max = 0, sub_max = 0;

        int sum = 0;
        while(l < r){
            prev_max = max(prev_max, height[l]);
            sub_max = max(sub_max, height[r]);

            if(prev_max < sub_max){
                sum += prev_max - height[l];
                l++;
            }else{
                sum += sub_max - height[r];
                r--;
            }
        }
        return sum;
    }
};
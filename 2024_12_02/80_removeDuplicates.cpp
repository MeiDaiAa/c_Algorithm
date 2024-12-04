#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         int l = 0, r = 0;
//         int times = 0;

//         while(r < n){
//             while(r < n && nums[r] == nums[l]) r++;
//             if(r - l >= 2){
//                 l += 2;
//                 while(l < r) nums[l++] = -1001;
//             }
//             else l = r;
//         }

//         l = 0, r = 0;
//         while(r < n){
//             nums[l] = nums[r];
//             l++, r++;
//             while(r < n && nums[r] == -1001)r++;
//         }

//         return l;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int slow = 2, fast = slow + 1;

        while(fast < n){
            if(nums[slow - 2] == nums[slow]) {
                while(fast < n && nums[fast] != nums[slow]) fast++;
                nums[slow] = nums[fast];
            }

            slow++;
            fast++;
        }
        return slow;
    }
};
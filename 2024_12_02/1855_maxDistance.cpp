#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int len1 = nums1.size(), len2 = nums2.size();
//         int ret = 0;
//         int i = 0;

//         for(int j = 0; j < len2; ++j){
//             while(i <= j && nums1[i] <= nums2[j]){
//                 i++;
//             }

//             ret = max(ret, j - i);
//         }
//         return ret;
//     }
// };

// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int len1 = nums1.size(), len2 = nums2.size();
//         int ret = 0;
//         int i = 0;

//         for(int i = 0; i < len1; ++i){
//             int l = -1, r = len2;

//             while(l + 1 < r){
//                 int mid = l + (r - l) / 2;
//                 if(nums2[mid] < nums1[i]) l = mid;
//                 else r = mid;
//             }

//             if(r < i) ret = max(ret, r - i);
//         }
//         return ret;
//     }
// };



class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int ret = 0;
        int i = 0;

        for(int j = 0; j < len2; ++j){
            if(nums1[i] > nums2[j] && i < len1 && i <= j) ++i;

            ret = max(ret, j - i);
        }

        return ret;
    }
};
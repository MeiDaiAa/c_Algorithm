#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ret;

        if (n < 4) return ret;

        sort(nums.begin(), nums.end());

        if ((long)nums.at(n - 1) + nums.at(n - 2) + nums.at(n - 3) + nums.at(n - 4) < target) return ret;


        int L, R;
        long allSum;
        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums.at(i) == nums.at(i - 1)) continue;


            if ((long)nums.at(i) + nums.at(i + 1) + nums.at(i + 2) + nums.at(i + 3) > target) break;//return ret;

            if ((long)nums.at(i) + nums.at(n - 1) + nums.at(n - 2) + nums.at(n - 3) < target) continue;



            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums.at(j) == nums.at(j - 1)) continue;

                if ((long)nums.at(j) + nums.at(i) + nums.at(j + 1) + nums.at(j + 2) > target) break;//return ret;

                if ((long)nums.at(j) + nums.at(i) + nums.at(n - 2) + nums.at(n - 1) < target) continue;


                L = j + 1, R = n - 1;

                while (L < R) {
                    allSum = (long)nums.at(i) + nums.at(j) + nums.at(L) + nums.at(R);

                    if (allSum == target) {
                        ret.push_back({ nums.at(i), nums.at(j), nums.at(L), nums.at(R) });

                        while (L < R && nums.at(L) == nums.at(L + 1)) {
                            L++;
                        }
                        L++;
                        while (L < R && nums.at(R) == nums.at(R - 1)) {
                            R--;
                        }
                        R--;
                    }
                    else if (allSum < target) {
                        L++;
                    }
                    else {
                        R--;
                    }
                }
            }
        }
        return ret;
    }
};


//class Solution {
//public:
//    vector<vector<int>> fourSum(vector<int>& nums, int target) {
//        vector<vector<int>>ret;
//        int n = nums.size();
//        //定义哈希表去除重复元素
//        unordered_map<string, int>hash;//默认哈希表不能储存vector<int>类型的数据
//
//        //排序
//        sort(nums.begin(), nums.end());
//
//        //定义左右两个指针
//        int L = 0, R = n - 1;
//        int l = 0, r = 0;
//        long long twoSum = 0, allSum = 0;
//        string temp;
//        while (L < R) {
//            twoSum = nums.at(L) + nums.at(R);
//            //定义中间的遍历指针
//            int l = L + 1, r = R - 1;
//            while (l < r) {
//                allSum = twoSum + nums.at(l) + nums.at(r);
//                if (allSum == target) {
//                    temp = to_string(nums.at(L)) + to_string(nums.at(l)) + to_string(nums.at(r)) + to_string(nums.at(R));
//                    //如果哈希表中没有这个元素的数组就添加到返回数组中
//                    if (hash[temp] == 0) {
//                        ret.push_back({ nums.at(L), nums.at(l), nums.at(r), nums.at(R) });
//                        hash[temp]++;
//                    }
//                }
//                if (allSum < target) {
//                    l++;
//                }
//                else {
//                    r--;
//                }
//            }
//            if (twoSum < target) {
//                L++;
//            }
//            else {
//                R--;
//            }
//        }
//        return ret;
//    }
//};

/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //定义哈希表去除重复元素
        unordered_map<string, int>hash;//默认哈希表不能储存vector<int>类型的数据

        vector<vector<int>>ret;
        int n = nums.size();
        //排序
        sort(nums.begin(), nums.end());

        //定义左右两个指针
        int L = 0, R = n - 1;

        int twoSum = 0, allSum = 0;
        while (L < R) {
            twoSum = nums.at(L) + nums.at(R);

            calc(nums, hash, twoSum,target, L, R, ret);

            if(twoSum < target){
                L++;
            }
            else if (twoSum == target)
            {
                calc(nums, hash, twoSum,target, L + 1, R, ret);
                R--;
            }
            else{
                R--;
            }
        }
        return ret;
    }

    void calc(vector<int>&nums,unordered_map<string, int>hash, long long twoSum, int target,   int L, int R, vector<vector<int>>&ret){
        long long allSum = 0;
        string temp;
        int l = L + 1, r = R - 1;

        while (l < r) {
            allSum = twoSum + nums.at(l) + nums.at(r);
            if (allSum == target) {
                temp = to_string(nums.at(L)) + to_string(nums.at(l)) + to_string(nums.at(r)) + to_string(nums.at(R));
                //如果哈希表中没有这个元素的数组就添加到返回数组中
                if (hash[temp] == 0) {
                    ret.push_back({ nums.at(L), nums.at(l), nums.at(r), nums.at(R) });
                    hash[temp]++;
                }
            }
            if(allSum < target){
                l++;
            }
            else{
                r--;
            }
        }
    }
};
*/
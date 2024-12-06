class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int l = 0;
        int ans = 0;
        int memo[3] = {0};

        for(int r = 0; r < n; ++r){
            memo[s[r] - 'a']++;
            while(memo[0] > 0 && memo[1] > 0 && memo[2] > 0){
                ans += n - r;
                --memo[s[l++] - 'a'];
            }
            //ans += l;
        }
        return ans;
    }
};
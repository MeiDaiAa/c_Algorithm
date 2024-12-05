class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int l = 0;
        int T = 0, F = 0;
        int ans = 0;

        for(int r = 0; r < n; ++r){
            if(answerKey[r] == 'T')T++;
            else F++;

            while(T > k && F > k){
                if(answerKey[l] == 'T') T--;
                else F--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
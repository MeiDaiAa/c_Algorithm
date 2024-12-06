class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int l = 0, sum = 0;
        string str = "";
        for(int i = 0; i < n + 1; ++i) str += '1';
        
        for(int r = 0; r < n; ++r){
            if(s[r] == '1') sum++;
            while(sum == k){
                if(r - l + 1 < str.size()) str = s.substr(l, r - l + 1);
                else if(r - l + 1 == str.size()){
                    if(s.substr(l, r - l + 1) < str) str = s.substr(l, r - l + 1);
                }

                if(s[l] == '1') sum--;
                l++;
            }
        }
        return str.size() == n + 1 ? "" : str;
    }
};
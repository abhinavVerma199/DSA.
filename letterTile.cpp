class Solution {
public:
    int solve(vector<int>& freq) {
        int ans = 0;
        for(int i=0; i<26; i++) {
            if(freq[i] != 0) {
                ans++;
                freq[i]--;
                ans += solve(freq);
                freq[i]++;
            }
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        int n = tiles.length();
        vector<int> freq(26,0);
        for(auto ch: tiles) {
            freq[ch-'A']++;
        }
        return solve(freq);
    }
};
class Solution {
public:
    int solveUsingRecursion(string& a, string& b, int i, int j) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }

        int ans = 0;
        if(a[i] == b[j] ) {
            ans = 0 + solveUsingRecursion(a,b,i+1,j+1);
        }
        else {
            int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);
            int insert = 1 + solveUsingRecursion(a,b,i,j+1);
            int remove = 1 + solveUsingRecursion(a,b,i+1,j);
            ans = min(insert,min(remove,replace));
        }
        return ans;
    }
    int solveUsingMem(string& a, string& b, int i, int j,vector<vector<int> >& dp) {
        //base case
        if(i == a.length()) {
            return b.length()-j;
        }
        if(j == b.length()) {
            return a.length()-i;
        }

        //check if ans already exits
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        if(a[i] == b[j] ) {
            ans = 0 + solveUsingMem(a,b,i+1,j+1,dp);
        }
        else {
            int replace = 1 + solveUsingMem(a,b,i+1,j+1,dp);
            int insert = 1 + solveUsingMem(a,b,i,j+1,dp);
            int remove = 1 + solveUsingMem(a,b,i+1,j,dp);
            ans = min(insert,min(remove,replace));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveUsingTabulation(string a, string b) {
        vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));

        for(int col=0; col<=b.length(); col++) {
            dp[a.length()][col] = b.length()-col;
        }
        for(int row=0; row<=a.length(); row++) {
            dp[row][b.length()] = a.length()-row;
        }

        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            for(int j_index=b.length()-1; j_index>=0; j_index--) {
                int ans = 0;
                if(a[i_index] == b[j_index] ) {
                    ans = 0 + dp[i_index+1][j_index+1];
                }
                else {
                    int replace = 1 + dp[i_index+1][j_index+1];
                    int insert = 1 + dp[i_index][j_index+1];
                    int remove = 1 + dp[i_index+1][j_index];
                    ans = min(insert,min(remove,replace));
                }
                dp[i_index][j_index] = ans;
            }
        }
        return dp[0][0];
    }


    int solveUsingTabulationSO(string a, string b) {
        //vector<vector<int> > dp(a.length()+1, vector<int>(b.length()+1, -1));
        vector<int> curr(a.length()+1, 0);
        vector<int> next(a.length()+1, 0);

        //abhi k liye bhul jao
        // for(int col=0; col<=b.length(); col++) {
        //     dp[a.length()][col] = b.length()-col;
        // }
        //iska kuch n kuch toh karna padega, nahi toh galti krdenge - IMP
        //toh mujhe curr col ka last dabbe me b.length()-j save krna h 

        for(int row=0; row<=a.length(); row++) {
            next[row] = a.length()-row;
        }

    for(int j_index=b.length()-1; j_index>=0; j_index--) {
        //hr naye column k last dabbe me ans insert karo
        //MOST IMP LINE HAI
        curr[a.length()] = b.length()-j_index;
        for(int i_index=a.length()-1; i_index>=0; i_index--) {
            
                int ans = 0;
                if(a[i_index] == b[j_index] ) {
                    ans = 0 + next[i_index+1];
                }
                else {
                    int replace = 1 + next[i_index+1];
                    int insert = 1 + next[i_index];
                    int remove = 1 + curr[i_index+1];
                    ans = min(insert,min(remove,replace));
                }
                curr[i_index] = ans;
            }
            //shifting
            next = curr;
        }
        return next[0];
    }


    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        //vector<vector<int> > dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        int ans = solveUsingTabulationSO(word1, word2);
        return ans;
    }
};
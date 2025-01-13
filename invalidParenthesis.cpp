class Solution {
public:
    void solve(string& s, int index, int left, int right, int bal, string &output, unordered_set<string>& ans ) {
        //base case
        if(index >= s.length()) {
            //valid ans
            if(left ==0 && right ==0 && bal == 0 ) {
                ans.insert(output);
            } 
            return;
        }

        //main logic -> incl/excl
        if(s[index] !='(' && s[index] != ')') {
            //include
            output.push_back(s[index]);
            solve(s,index+1, left, right, bal, output, ans);
            output.pop_back();
        }
        else {
            //bracket wala case
            if(s[index] =='(') {
                //removal - include
                if(left > 0) {
                    solve(s, index + 1, left-1, right, bal, output, ans);
                }
                //removal - exclude
                output.push_back(s[index]);
                solve(s, index+1, left, right, bal+1,output, ans );
                output.pop_back();
            }
            else if(s[index] == ')') {
                //removal - include
                if(right > 0 ) {
                    solve(s, index+1, left, right-1, bal, output, ans);
                }
                //removal - exclude
                //removal nahi karna , sirf usi case jab corresponding opening bracket available hai 
                if(bal > 0 ) {
                    output.push_back(s[index]);
                    solve(s, index + 1, left, right, bal-1, output, ans);
                    output.pop_back();
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int invalidLeft = 0;
        int invalidRight = 0;

        for(auto ch: s ){
            if(ch == '(') 
                invalidLeft++;
            if(ch == ')') {
                if(invalidLeft != 0) {
                    --invalidLeft;
                }
                else {
                    invalidRight++;
                }
            }
        }
        int index = 0;
        int balance = 0;
        string output = "";
        solve(s,index,invalidLeft,invalidRight,balance,output,ans);
        return vector<string>(ans.begin(), ans.end());
    }
};
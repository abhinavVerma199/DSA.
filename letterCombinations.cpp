class Solution {
public:
    void solve(vector<string>& ans, string mapping[], string str, int index,string output) {
        //base case
        if(index >= str.length()) {
            
            if(output.length() > 0)
                ans.push_back(output);
            
            return;
        }
        string temp = mapping[str[index] - '0'];
        
        for(auto ch: temp) {
            output.push_back(ch);
            solve(ans,mapping,str,index+1,output);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        string output = "";
        solve(ans, mapping, digits,index,output);
        return ans;

        
    }
};
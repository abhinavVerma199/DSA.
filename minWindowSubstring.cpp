class Solution {
public:
    string minWindow(string s, string t) {
        //invalid case
        int len1 = s.length();
        int len2 = t.length();
        int start = 0;
        if(len1 < len2) {
            return "";
        }
        //valid case
        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;
        //store freq of pattern string
        for(char ch: t) {
            tMap[ch]++;
        }
        //initialise count variable, that basically shows count of actual
        //pattern wale string k character presrnt in the current window
        int count = 0;
        int e = 0;
        while(e < s.length()) {
            char ch = s[e];
            //update freq in sMap
            sMap[ch]++;
            if(sMap[ch] <= tMap[ch]) {
                //valid character
                count++;
            }

            if(count == len2) {
                //window found, jisme poora pattern existb krta h 
                //-> minimise
                //minimise sirf usi case me karunga, jis case me 
                //s index pr jo character present h, vop 
                //ya toh extra hai ya fer faltu hai 
                //aisa character jo pattern k andar hi nahi h, use bhi remove karo
                while(sMap[s[start]] > tMap[s[start]]) {
                    sMap[s[start]]--;
                    start++;
                }
                //answer nikalo
                int windowLength = e - start + 1;
                if(windowLength < ansLen) {
                    ansLen = windowLength;
                    ansIndex = start;
                }
            }
            e++;
        }

        if(ansIndex == -1) {
            return "";
        }
        else {
            return s.substr(ansIndex, ansLen);
        }

    }
};